#ifndef VEC2
#define VEC2

	#include "Vec2.fwd.h"
	#include "Rect.fwd.h"

	class Vec2{
		public:
		//attributes:
			float x, y;
		//metods:
			Vec2(float x = 0, float y = 0);
			Vec2 operator=(Vec2 vector);
			Vec2 operator+(Vec2 vector);
			Rect operator+(Rect rectangle);
			Vec2 operator-(Vec2 vector);
			float operator*(Vec2 vector);
			Vec2 operator*(float scalar);
			Vec2 operator/(float scalar);
			float Magnitude();
			Vec2 Normalized();
			float VDistance(float x, float y);
			float VDistance(Vec2 vector);
			float Slope();
			void Rot(float theta);
			Vec2 GetRotated(float theta);
			void Print();

	};

	Vec2 operator*(float scalar, Vec2 vector);

#endif