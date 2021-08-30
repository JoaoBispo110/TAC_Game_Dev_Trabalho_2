#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Game.h"

using namespace std;
Game::Game(string title, int width, int height){
	if(instance != nullptr){
		throw "Attempting to create a new instance of \"Game\", while one already exists";
	}

	instance = this;

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){
		throw SDL_GetError();
	}

	if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) !=  (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
		throw SDL_GetError();
	}

	if( Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
		throw SDL_GetError();
	}

	if( Mix_Init(MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_MP3 | MIX_INIT_MOD) !=
		(MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_MP3 | MIX_INIT_MOD) ){
		throw SDL_GetError();
	}

	Mix_AllocateChannels(32);
	//Should only cause a problem in case of not enough memory, which should only happen if the number given is very big
	//(32 is not very big)

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0x0);
	if(window == nullptr){
		throw SDL_GetError();
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == nullptr){
		throw SDL_GetError();
	}

	try{
		state = new State;
	}catch(const char* error_msg){
			throw error_msg;
		}
}

Game& Game::GetInstance(){
	if(instance == nullptr){
		try{
			instance = new Game("JoaoGuimaraesBispo170067793", 1024, 600);
		}catch(const char* error_msg){
			throw error_msg;
		}
	}

	return *instance;
}

Game::~Game(){
	delete state;

	Mix_CloseAudio();
	Mix_Quit();

	IMG_Quit();

	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);

	SDL_Quit();
}

State& Game::GetState(){
	return *state;
}

SDL_Renderer* Game::GetRenderer(){
	return renderer;
}

void Game::Run(){
	while(state->QuitRequested() == false){
		state->Update(0.0);//random placeholder number
		state->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);//33ms so the game runs at approximately 30FPS
	}
}