#ifndef MYLAMP_X
#define MYLAMP_X

#include "CGFobject.h"
#include "CGFappearance.h"
#include "CGFlight.h"
#include "MySemiSphere.h"
#include "myCylinder.h"

class MyLamp: public CGFobject{
	private:
		CGFlight * light;
		CGFappearance * material;
		CGFappearance * materialTop;
		MySemiSphere * semisphere;
		myCylinder * bottom;
	public:
		MyLamp(unsigned int lightid);
		~MyLamp();
		void draw();

		void setState(bool s);
};




#endif