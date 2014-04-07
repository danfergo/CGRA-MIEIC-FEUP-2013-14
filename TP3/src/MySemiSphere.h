#ifndef MYSEMISPHERE_X
#define MYSEMISPHERE_X

#include "CGFobject.h"
#include "CGFappearance.h"
#include "CGFlight.h"

class MySemiSphere: public CGFobject{
	private:
		float angle_a, angle_b;
		unsigned stacks, slices;
		
	public:
		MySemiSphere(unsigned stacks, unsigned slices);
		void draw();
};




#endif