#ifndef COMPONENT
#define COMPONENT

	#include <string>
	#include "Component.fwd.h"
	#include "GameObject.h"

	using namespace std;
	class Component{
		protected:
		//attributes:
			GameObject& associated = *(new GameObject());

		public:
		//metods:
			Component(GameObject& associated);
			~Component();
			void virtual Update(float dt) = 0;
			void virtual Render() = 0;
			bool virtual Is(string type) = 0;
	};

#endif