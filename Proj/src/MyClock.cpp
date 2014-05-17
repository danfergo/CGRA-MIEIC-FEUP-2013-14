#include "MyClock.h"
float ambPtr[3] ={1,0.1,0.1};
float diffPtr[3] = {1,0.1,0.1};
float specPtr[3] = {1, 0.01, 0.01};
float shinPtr = 5.f;

CGFappearance * pointerAppearance = new CGFappearance(ambPtr,diffPtr,specPtr,shinPtr);

MyClock::MyClock(float h, float m, float s): myCylinder(12,1,true), mscounter(0){	
	hours = new MyClockHand(0.09,0.6);
	minutes = new MyClockHand(0.05,0.8);
	seconds = new MyClockHand(0.03,1);
	setHours(h);
	setMinutes(m);
	setSeconds(s);
	lastT=0;

	cili = new myCylinder();
};

void MyClock::setHours(float h){
	if (h<=24){
		hours->setAngle(h*30);
		hh = h;
	}

}
void MyClock::setMinutes(float m){
	if(m <=60){

		minutes->setAngle(m*6);
		mm = m;
	}
}
void MyClock::setSeconds(float s){
	if(s<=60){
		seconds->setAngle(s*6);
		ss = s;
	}
}

void MyClock::setTime(float h, float m, float s){
	setHours(h);
	setMinutes(m);
	setSeconds(s);
}

void MyClock::draw(){
		glPushMatrix();
		
		glPushMatrix();
			glRotated(90,1,0,0);
			glScalef(1,0.05,1);
			cili->draw();
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
	double s = (lastT==0) ? 0 : (((double)(t-lastT))/1000);
	ss += s;

	mm += s/(double)60;
	hh += s/(double)3600;

	if(ss >= 60){
		ss = 0;
	}

	if(mm >= 60){
		mm = 0;
	}

	if(hh >= 60){
		hh = 0;
	}
	setTime(hh,mm,ss);
	lastT = t;
}