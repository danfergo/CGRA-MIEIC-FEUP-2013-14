#include "MyClock.h"

float ambPtr[3] ={1,0.1,0.1};
float diffPtr[3] = {1,0.1,0.1};
float specPtr[3] = {1, 0.01, 0.01};
float shinPtr = 5.f;

CGFappearance * pointerAppearance = new CGFappearance(ambPtr,diffPtr,specPtr,shinPtr);

MyClock::MyClock(int h, int m, int s): myCylinder(12,1,true), lastt(0){	
	hours = new MyClockHand(0.09,0.6);
	minutes = new MyClockHand(0.05,0.8);
	seconds = new MyClockHand(0.03,1);
	setHours(h);
	setMinutes(m);
	setSeconds(s);
};

void MyClock::setHours(unsigned h){
	hours->setAngle((h%60)*30);
}
void MyClock::setMinutes(unsigned m){
	minutes->setAngle((m%60)*6);
}
void MyClock::setSeconds(unsigned s){
	seconds->setAngle((s%60)*6);
}

void MyClock::setTime(unsigned hours, unsigned minutes, unsigned seconds){
	setHours(hours);
	setMinutes(minutes);
	setSeconds(seconds);
}

void MyClock::draw(){
		glPushMatrix();
		
		glPushMatrix();
			glRotated(90,1,0,0);
			glScalef(1,0.05,1);
			myCylinder::draw();
		glPopMatrix();


		pointerAppearance->apply();
	


		glPushMatrix();
			glTranslatef(0,0,0.06);

			glPushMatrix();
				hours->draw();
			glPopMatrix();

			glPushMatrix();

				minutes->draw();
			glPopMatrix();

			glPushMatrix();

				seconds->draw();
			glPopMatrix();

		glPopMatrix();
				
	glPopMatrix();
}



void MyClock::update(unsigned long t){
	unsigned i = (t - lastt)*1000;

	seconds->setAngle(seconds->getAngle() + (float)(i%60)/60);
	
	minutes->setAngle(minutes->getAngle() + (float)i/60);
	lastt = t;
}