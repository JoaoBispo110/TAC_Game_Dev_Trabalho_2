#ifndef MUSIC
#define MUSIC

	#include <string>
	#define INCLUDE_SDL_MIXER
	#include "SDL_include.h"

	using namespace std;
	class Music{
		private:
		//attributes:
			Mix_Music* music;

		public:
		//methods:
			Music();
			Music(string file);
			~Music();
			void Play(int times = -1);
			void Stop(int msToStop = 1500);
			void Open(string file);
			bool IsOpen();	
	};

#endif