#ifndef SOUND
#define SOUND

	#include <string>
	#define INCLUDE_SDL_MIXER
	#include "SDL_include.h"
	#include "Component.h"

	using namespace std;
	class Sound : public Component{
		private:
		//attributes:
			Mix_Chunk* chunk;
			int channel;

		public:
		//methods:
			Sound(GameObject *associated);
			Sound(GameObject *associated, string file);
			~Sound();
			void Play(int times = 1);
			void Stop();
			void Open(string file);
			bool IsOpen();
			void Update(float dt);
			void Render();
			bool Is(string type);
	};

#endif