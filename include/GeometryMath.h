#ifndef GEOMATH
#define GEOMATH

	#include "Vec2.fwd.h"

	float Distance(float x1, float y1, float x2, float y2);
	float Distance(Vec2 vector1, Vec2 vector2);
	float Distance(Vec2 vector, float x, float y);
	float Slope(float x1, float y1, float x2, float y2);
	float Slope(Vec2 vector1, Vec2 vector2);
	float Slope(Vec2 vector, float x, float y);

#endif