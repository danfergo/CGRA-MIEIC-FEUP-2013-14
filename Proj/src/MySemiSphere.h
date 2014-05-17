#ifndef MYSEMISPHERE_X
#define MYSEMISPHERE_X

#include "CGFobject.h"
#include "CGFappearance.h"
#include "CGFlight.h"

typedef struct Point {
   float x;
   float y;
   float z;
} Point;


class MySemiSphere: public CGFobject{
	private:
		float angle_a, angle_b;
		unsigned stacks, slices;
		Point ** dots;
		
	public:
		MySemiSphere(unsigned stacks, unsigned slices);
		void draw();
		~MySemiSphere();
};




#endif