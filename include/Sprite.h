#ifndef SPRITE
#define SPRITE

	#include <string>
	#define INCLUDE_SDL_IMAGE
	#include "SDL_include.h"

	using namespace std;
	class Sprite{
		private:
		//attributes:
			SDL_Texture* texture;
			int width, height;
			SDL_Rect clipRect;

		public:
		//methods:
			Sprite();
			Sprite(string file);
			~Sprite();
			void Open(string file);
			void SetClip(int x, int y, int w, int h);
			void Render(int x, int y);
			int GetWidth();
			int GetHeight();
			bool IsOpen();
		
	};
	
#endif