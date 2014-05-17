#ifndef MY_CLOCK_HAND
#define MY_CLOCK_HAND

#include "CGFobject.h" 

class MyClockHand: public CGFobject{
private:
	float angle, width, height;
public:
	MyClockHand(float with, float height);
	float getAngle() const{
		return angle;
	}
	void setAngle(float a);
	void draw();
};

#endif