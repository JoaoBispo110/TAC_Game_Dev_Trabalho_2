#ifndef GAME_OBJECT
#define GAME_OBJECT

	#include <string>
	#include <vector>
	#include <memory>
	#include "GameObject.fwd.h"
	#include "Component.fwd.h"
	#include "Rect.h"
	

	using namespace std;
	class GameObject{
		private:
		//attributes:
			vector < Component* > components;
			bool is_dead;

		public:
		//attributes:
			Rect box;

		//metods:
			GameObject();
			~GameObject();
			void Update(float dt);
			void Render();
			bool IsDead();
			void RequestDelete();
			void AddComponent(Component* cpt);
			void RemoveComponent(Component* cpt);
			Component* GetComponent(string type);
	};

#endif