#include <string>
#include "Sound.h"
#include "Component.h"
#include "GameObject.h"

using namespace std;
Sound::Sound(GameObject& associated) : Component(associated){
	chunk = nullptr;
}

Sound::Sound(GameObject& associated, string file) : Component(associated){
	try{
		Open(file);
	}catch(const char* error_msg){
			throw error_msg;
	}
}

Sound::~Sound(){
	Stop();
	if(chunk != nullptr){
		Mix_FreeChunk(chunk);
	}
}

void Sound::Play(int times){
	channel = Mix_PlayChannel(-1, chunk, (times - 1));
}

void Sound::Stop(){
	if(chunk != nullptr){
		Mix_HaltChannel(channel);
	}
}

void Sound::Open(string file){
	try{
		chunk = Mix_LoadWAV(file.c_str());
	}catch(const char* error_msg){
			throw error_msg;
	}
}

bool Sound::IsOpen(){
	return (chunk != nullptr);//Returns true if chunk is allocated
}

void Sound::Update(float dt){}

void Sound::Render(){}

bool Sound::Is(string type){
	if(type == "Sound"){
		return true;
	}
	else{
		return false;
	}
}