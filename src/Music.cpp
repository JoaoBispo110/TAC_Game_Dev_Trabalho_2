#include <string>
#include "Music.h"

using namespace std;
Music::Music(){
	music = nullptr;
}

Music::Music(string file){
	music = nullptr;

	try{
		Open(file);
	}catch(const char* error_msg){
			throw error_msg;
		}
	printf("ultima coisa em music\n");
}

void Music::Play(int times){
	if(music != nullptr){
		try{
			Mix_PlayMusic(music, times);
		}catch(const char* error_msg){
				throw error_msg;
			}
	}
	else{
		throw "Tried to play a song, but song pointer is Null";
	}
}

void Music::Stop(int msToStop){
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
	if(music != nullptr){
		Stop();
	}
	music = Mix_LoadMUS(file.c_str());
	if(music == nullptr){
		throw SDL_GetError();
	}
}

bool Music::IsOpen(){
	return (music != nullptr);//Returns true if music is allocated
}

Music::~Music(){
	if(music != nullptr){
		Stop();
		Mix_FreeMusic(music);
		music = nullptr;
	}
}