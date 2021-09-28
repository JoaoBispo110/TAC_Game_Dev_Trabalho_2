#include <cmath>
#include "Vec2.h"
#include "Rect.h"
#include "GeometryMath.h"

Vec2::Vec2(float x, float y){
	this->x = x;
	this->y = y;
}

Vec2 Vec2::operator=(Vec2 vector){
	x = vector.x;
	y = vector.y;

	return vector;
}

Vec2 Vec2::operator+(Vec2 vector){
	Vec2 Result;

	Result.x = x + vector.x;
	Result.y = y + vector.y;

	return Result;
}

Rect Vec2::operator+(Rect rectangle){
	Rect Result;

	Result.x = rectangle.x + x;
	Result.y = rectangle.y + y;
	Result.w = rectangle.w;
	Result.h = rectangle.h;

	return Result;
}

Vec2 Vec2::operator-(Vec2 vector){
	Vec2 Result;
	
	Result.x = x - vector.x;
	Result.y = y - vector.y;

	return Result;
}

float Vec2::operator*(Vec2 vector){
	return ((x * vector.x) + (y * vector.y));
}

Vec2 Vec2::operator*(float scalar){
	Vec2 Result;
	
	Result.x = x * scalar;
	Result.y = y * scalar;

	return Result;
}

Vec2 operator*(float scalar, Vec2 vector){
	return vector * scalar;
}

Vec2 Vec2::operator/(float scalar){
	Vec2 Result;
	
	Result.x = x / scalar;
	Result.y = y / scalar;

	return Result;
}

float Vec2::Magnitude(){
	return sqrt((x*x) + (y*y));
}

Vec2 Vec2::Normalized(){
	Vec2 Result;

	Result.x = x/this->Magnitude();
	Result.y = y/this->Magnitude();

	return Result;
}

float Vec2::VDistance(float x, float y){
	return Distance(*this, x, y);
}

float Vec2::VDistance(Vec2 vector){
	return Distance(*this, vector);
}

float Vec2::Slope(){
	return atan(y/x);
}

void Vec2::Rot(float theta){
	x = x*cos(theta) - y*sin(theta);
	y = x*sin(theta) + y*cos(theta);
}

Vec2 Vec2::GetRotated(float theta){
	Vec2 rotacionado;

	rotacionado = *this;
	rotacionado.Rot(theta);

	return rotacionado;
}