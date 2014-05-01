#include "myCylinder.h"

#include "MyClockHand.h"
#include "CGFappearance.h"



class MyClock: public myCylinder{
	MyClockHand * hours; 
	MyClockHand * minutes;
	MyClockHand * seconds; 
	unsigned long lastt;
public:
	MyClock(int h, int m, int s);

	void setSeconds(unsigned seconds);
	void setHours(unsigned hours);
	void setMinutes(unsigned minutes);
	void setTime(unsigned hours, unsigned minutes, unsigned seconds);

	void update(unsigned long);

	void draw();
};