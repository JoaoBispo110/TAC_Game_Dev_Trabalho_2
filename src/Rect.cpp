#include "Rect.h"
#include "Vec2.h"
#include "GeometryMath.h"

Rect::Rect(float x, float y, float w, float h){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

Vec2 Rect::Center(){
	Vec2 Result;

	Result.x = x + (w/2);
	Result.y = y + (h/2);

	return Result;
}

float Rect::DistanceCenter(Rect rectangle){
	Vec2 vector1, vector2;

	vector1 = Center();
	vector2 = rectangle.Center();

	return Distance(vector1, vector2);
}

float Rect::DistanceCenter(float x, float y){
	return Distance(Center(), x, y);
}

float Rect::DistanceCenter(Vec2 vector){
	return Distance(Center(), vector);
}

bool Rect::IsIn(float x, float y){
	if((this->x <= x) && ((this->x + w) >= x) && (this->y <= y) && ((this->y + h) >= y)){
		return true;
	}
	else{
		return false;
	}
}

bool Rect::IsIn(Vec2 vector){
	if((x <= vector.x) && ((x + w) >= vector.x) && (y <= vector.y) && ((y + h) >= vector.y)){
		return true;
	}
	else{
		return false;
	}
}