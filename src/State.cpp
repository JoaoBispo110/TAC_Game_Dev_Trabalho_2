#include "State.h"
#include "Sprite.h"
#include "Music.h"
#include "Constants.h"

State::State(){
	quitRequested = false;
	bg = Sprite();

	try{
		music.Open(MUSIC_PATH);
		music.Play();
	}catch(const char* error_msg){
			throw error_msg;
		}
}

void State::LoadAssets(){}

void State::Update(float dt){

	//Checks if user requested closing the game
	quitRequested = SDL_QuitRequested();
}

void State::Render(){
	bg.Open(BG_PATH);
}

bool State::QuitRequested(){
	return quitRequested;
}