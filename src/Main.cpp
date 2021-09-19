#include <iostream>
#include "Game.h"

#include "Vec2.h"
#include "Rect.h"
#include "GeometryMath.h"

int main(int argc, char** argv){
	try{
		Game* game = &(Game::GetInstance());

		game->Run();

		delete game;
	}catch(const char* error_msg){
			cout << error_msg << endl;
			getchar();
		}

	return 0;
}