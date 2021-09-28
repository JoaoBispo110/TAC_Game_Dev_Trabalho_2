#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "State.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "GameObject.h"
#include "Face.h"
#include "Vec2.h"
#include "Constants.h"

State::State(){
	GameObject bg_obj;

	bg = new Sprite(bg_obj, BG_PATH);
	bg_obj.AddComponent(bg);

	quitRequested = false;

	try{
		music = new Music(MUSIC_PATH);
		music->Play();
	}catch(const char* error_msg){
			throw error_msg;
		}
}

State::~State(){
	delete music;
	delete bg;
	object_array.clear();
}

void State::LoadAssets(){}

void State::Render(){
	int i;
	
	//bg.Open(BG_PATH);
	for(i = 0; i < object_array.size(); i++){
		object_array[i]->Render();
	}
}

bool State::QuitRequested(){
	return quitRequested;
}

void State::Input(){
	SDL_Event event;
	int mouseX, mouseY;

	// Gets mouse coordinates
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent returns 1 in case there are any events, 0 otherwise
	while (SDL_PollEvent(&event)){

		// If the event is quit, than set the corresponding flag
		if(event.type == SDL_QUIT){
			quitRequested = true;
		}
		
		// If the event is a mouse click...
		if(event.type == SDL_MOUSEBUTTONDOWN){

			// Start from the end so the click is allways performed on the object thats on top.
			for(int i = (object_array.size() - 1); i >= 0; i--){
				// Gets the pointer and casts it to Face.
				GameObject* go = (GameObject*) object_array[i].get();
				// Note: We should avoid unencaping the vector at all costs.
				// The purpose of unique_ptr is mantaining only one copy of each pointer,
				// when we use get(), we violate this principle, thus we are less safe.
				// This code, aswell as the Face class, are temporary. In the future, we will
				// use object_array[i]->function() directly to call GameObject functions.

				if(go->box.IsIn((float)mouseX, (float)mouseY)){
					Face* face = (Face*)go->GetComponent("Face");
					if (face != nullptr){
						// Apply damage
						face->Damage((std::rand() % 10) + 10);
						// Exit loop (we only want to hit one)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ){
			// If the key pressed was ESC, set the set the quit flag
			if( event.key.keysym.sym == SDLK_ESCAPE ){
				quitRequested = true;
			}
			// If the key was something else, then create an object.
			else{
				Vec2 objPos = Vec2( 200, 0 ).GetRotated( -M_PI + M_PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void State::Update(float dt){
	int i;

	Input();
	for(i = 0; i < object_array.size(); i++){
		object_array[i]->Update(dt);
	}
	for(i = 0; i < object_array.size(); i++){
		if(object_array[i]->IsDead()){
			object_array.erase(object_array.begin() + i);
			i--;
		}
	}
}

void State::AddObject(int mouseX, int mouseY){
	GameObject enemy;
	Sprite sprite_enemy(enemy, ENEMY_SPRITE_PATH);
	Sound sound_enemy(enemy, ENEMY_SOUND_PATH);
	Face face_enemy(enemy);

	enemy.box.x = (mouseX - (sprite_enemy.GetWidth() / 2));
	if(enemy.box.x < 0){
		enemy.box.x = 0;
	}
	enemy.box.y = (mouseY - (sprite_enemy.GetHeight() / 2));
	if(enemy.box.y < 0){
		enemy.box.y = 0;
	}

	enemy.AddComponent(&sprite_enemy);
	enemy.AddComponent(&sound_enemy);
	enemy.AddComponent(&face_enemy);
	
	object_array.emplace_back(&enemy);
}