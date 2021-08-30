#ifndef GAME
#define GAME

	#include <string>
	#define INCLUDE_SDL
	#include "SDL_include.h"
	#include "State.h"

	using namespace std;
	class Game{
		private:
		//attributes:
			State* state;
			SDL_Window* window;
			SDL_Renderer* renderer;
			inline static Game* instance = nullptr;

		//metods:
			Game(string title, int width, int height);

		public:
		//metods:
			~Game();
			void Run();
			SDL_Renderer* GetRenderer();
			State& GetState();
			static Game& GetInstance();
	};

#endif