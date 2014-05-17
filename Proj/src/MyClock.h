#include "myCylinder.h"

#include "MyClockHand.h"
#include "CGFappearance.h"


class MyClock: public myCylinder{
	MyClockHand * hours; 
	MyClockHand * minutes;
	MyClockHand * seconds; 
	unsigned mscounter;
	unsigned long lastT;
	float hh, mm,ss;
	myCylinder * cili;
public:
	MyClock(float h, float m, float s);

	void setSeconds(float seconds);
	void setHours(float hours);
	void setMinutes(float minutes);
	void setTime(float hours, float minutes, float seconds);

	void update(unsigned long);

	void draw();
};