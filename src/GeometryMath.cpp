#include <cmath>
#include "GeometryMath.h"
#include "Vec2.h"

float Distance(float x1, float y1, float x2, float y2){
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

float Distance(Vec2 vector1, Vec2 vector2){
	return (vector1 - vector2).Magnitude();
}

float Distance(Vec2 vector, float x, float y){
	return sqrt(pow((vector.x - x), 2) + pow((vector.y - y), 2));
}

float Slope(float x1, float y1, float x2, float y2){
	float m;

	if(((x1 - x2) < 0.0001) && ((x1 - x2) > -0.0001)){
		return M_PI/2;
	}
	else{
		m = (y1 - y2)/(x1 - x2);
		return atan(m);
	}
}

float Slope(Vec2 vector1, Vec2 vector2){
	float m;

	if(((vector1.x - vector2.x) < 0.0001) && ((vector1.x - vector2.x) > -0.0001)){
		return M_PI/2;
	}
	else{
		m = (vector1.y - vector2.y)/(vector1.x - vector2.x);
		return atan(m);
	}
}

float Slope(Vec2 vector, float x, float y){
	float m;

	if(((vector.x - x) < 0.0001) && ((vector.x - x) > -0.0001)){
		return M_PI/2;
	}
	else{
		m = (vector.y - y)/(vector.x - x);
		return atan(m);
	}
}