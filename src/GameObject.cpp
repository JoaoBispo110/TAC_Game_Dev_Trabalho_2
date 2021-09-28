#include <string>
#include <vector>
#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(){
	is_dead = false;
}

GameObject::~GameObject(){
	int i;

	for(i = 0; i < components.size(); i++){
		if(components[i] != nullptr){
			delete components[i];
		}
	}

	components.clear();
}

void GameObject::Update(float dt){
	int i;

	for(i = 0; i < components.size(); i++){
		components[i]->Update(dt);
	}
}

void GameObject::Render(){
	int i;

	for(i = 0; i < components.size(); i++){
		components[i]->Render();
	}
}

bool GameObject::IsDead(){
	return is_dead;
}

void GameObject::RequestDelete(){
	is_dead = true;
}

void GameObject::AddComponent(Component* cpt){
	components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
	int i;

	for(i = 0; i < components.size(); i++){
		if(components[i] == cpt){
			//delete components[i];
			components.erase(components.begin() + i);
			break;
		}
	}
}

Component* GameObject::GetComponent(string type){
	int i;

	for(i = 0; i < components.size(); i++){
		if(components[i]->Is(type)){
			return components[i];
		}
	}
	return nullptr;
}