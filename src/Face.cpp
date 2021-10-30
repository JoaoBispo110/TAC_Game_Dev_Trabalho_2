#include "Face.h"
#include "Component.h"
#include "Sound.h"

Face::Face(GameObject *associated) : Component(associated){
	hitpoints = 30;
}

void Face::Damage(int damage){
	Component* sound;

	hitpoints -= damage;
	if(hitpoints <= 0){
		associated->RequestDelete();
		sound = associated->GetComponent("Sound");
		if(sound != nullptr){
			((Sound*)sound)->Play();
		}
	}
}

void Face::Update(float dt){}

void Face::Render(){}

bool Face::Is(string type){
	if(type == "Face"){
		return true;
	}
	else{
		return false;
	}
}