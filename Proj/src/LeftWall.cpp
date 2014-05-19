#include "LeftWall.h"


LeftWall::LeftWall(void)
{//(100,-1.25,2.25,-0.5,1.5)
	centerTop = new Plane(100,0.04,0.96,0.7,1.5);
	centerBottom = new Plane(100,0.04,0.96,-0.5,0.05);
	left = new Plane(100,-1.25,0.04,-0.5,1.5);
	right = new Plane(100,0.96,2.25,-0.5,1.5);
	leftWindow = new Plane(100,0.5,0.96,0.05,0.7);
	rightWindow = new Plane(100,0.04,0.5,0.05,0.7);
}


LeftWall::~LeftWall(void)
{
	delete(centerTop);
	delete(centerBottom);
	delete(left);
	delete(right);
}


void LeftWall::draw(){
	glPushMatrix();
	// glScaled(15,0.2,8);

	glPushMatrix();
		glTranslated(0,4,7.5);
		glRotated(-90.0,0,0,1);
		glRotated(90.0,0,1,0);
	
		glPushMatrix();
			glTranslated(4.75,0,0);
			glScaled(5.5,1,8);
			right->draw();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-4.75,0,0);
			glScaled(5.5,1,8);
			left->draw();
		glPopMatrix();

	glPopMatrix();


	glPushMatrix();
		glTranslated(0,1.1,7.5);
		
		glRotated(-90.0,0,0,1);
		glRotated(90.0,0,1,0);

		glScaled(4,1,2.2);
		centerBottom->draw();
	glPopMatrix();


	glPushMatrix();
		glTranslated(0,6.4,7.5);
		
		glRotated(-90.0,0,0,1);
		glRotated(90.0,0,1,0);

		glScaled(4,1,3.2);
		centerTop->draw();
	glPopMatrix();


	glPushMatrix();
		
		glTranslated(-0.985,3.5,6.5-1.18);
		glRotated(-100,0,1,0);
		glRotated(-90.0,0,0,1);
		glRotated(90.0,0,1,0);

		glScaled(2,1,2.6);
		leftWindow->draw();
	glPopMatrix();

	glPushMatrix();
		
		glTranslated(-0.985,3.5,8.5+1.18);
		glRotated(100,0,1,0);
		glRotated(-90.0,0,0,1);
		glRotated(90.0,0,1,0);

		glScaled(2,1,2.6);
		rightWindow->draw();
	glPopMatrix();

	glPopMatrix();
}