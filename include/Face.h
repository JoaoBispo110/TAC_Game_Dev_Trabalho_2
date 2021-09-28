#ifndef FACE
#define FACE

	#include <string>
	#include "Component.h"

	using namespace std;
	class Face : public Component{
		private:
		//attributes:
			int hitpoints;

		public:
		//metods:
			Face(GameObject& associated);
			void Damage(int damage);
			void Update(float dt);
			void Render();
			bool Is(string type);
	};

#endif