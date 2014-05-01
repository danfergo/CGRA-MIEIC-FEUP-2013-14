#include "MyClockHand.h"

MyClockHand::MyClockHand(float w, float h):angle(0), width(w), height(h){
};

void MyClockHand::setAngle(float a){
	this->angle = -a;
}


void MyClockHand::draw(){
	glPushMatrix();
		glRotatef(angle,0,0,1);
		glBegin(GL_TRIANGLES);
			glVertex3f(-((float)width)/2,0,0);
			glVertex3f(((float)width)/2,0,0);
			glVertex3f(0,height,0);
		glEnd();
	glPopMatrix();

}