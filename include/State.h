#ifndef STATE
#define STATE

	#include "Sprite.h"
	#include "Music.h"

	class State{
		private:
		//attributes:
			Sprite bg;
			Music music;
			bool quitRequested;

		public:
		//methods:
			State();
			bool QuitRequested();
			void LoadAssets();
			void Update(float dt);
			void Render();
		
	};
	
#endif