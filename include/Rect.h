#ifndef RECT
#define RECT

	#include "Rect.fwd.h"
	#include "Vec2.fwd.h"

	class Rect{
		public:
		//attributes:
			float x, y, w, h;
		//metods:
			Rect(float x = 0, float y = 0, float w = 0, float h = 0);
			Vec2 Center();
			float DistanceCenter(Rect rectangle);
			float DistanceCenter(float x, float y);
			float DistanceCenter(Vec2 vector);
			bool IsIn(float x, float y);
			bool IsIn(Vec2 vector);
	};

#endif