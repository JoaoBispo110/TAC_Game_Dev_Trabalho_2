#ifndef SPRITE
#define SPRITE

	#include <string>
	#define INCLUDE_SDL_IMAGE
	#include "SDL_include.h"
	#include "Component.h"

	using namespace std;
	class Sprite : public Component{
		private:
		//attributes:
			SDL_Texture* texture;
			int width, height;
			SDL_Rect clipRect;

		public:
		//methods:
			Sprite(GameObject *associated);
			Sprite(GameObject *associated, string file);
			~Sprite();
			void Open(string file);
			void SetClip(int x, int y, int w, int h);
			int GetWidth();
			int GetHeight();
			bool IsOpen();
			void Update(float dt);
			void Render();
			bool Is(string type);
		
	};
	
#endif