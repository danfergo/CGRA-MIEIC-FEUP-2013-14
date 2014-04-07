#include "MyChair.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <math.h>
#include "CGFappearance.h"


MyChair::MyChair(): CGFobject() {
	rotate = (rand() % 41) - 20;
}


void MyChair::draw(){

	float ambWood[3] ={0.38, 0.2, 0.0196};
	float difWood[3] = {0.38, 0.2, 0.0196};
	float specWood[3] = {0.05, 0.05, 0.05};
	float shininessWood = 10.f;
	CGFappearance * wood = new CGFappearance(ambWood,difWood,specWood,shininessWood);

	float ambMetal[3] = {0.3, 0.3, 0.3};
	float difMetal[3] = {0.4, 0.4, 0.4};
	float specMetal[3] = {0.6, 0.6, 0.6};
	float shininessMetal = 500.f;
	CGFappearance * metal = new CGFappearance(ambMetal,difMetal,specMetal,shininessMetal);


	float pi = acos(-1.0);
	float deg2rad=pi/180.0;

	wood->apply();
	MyUnitCube myCube = MyUnitCube();
	glPushMatrix();
		glTranslated(0,0,-1);
		glRotated(this->rotate,0,1,0);
		glRotated(-1 * abs(rotate*0.5),1,0,0);
		glTranslated(0,0,1);
		glTranslatef(0,0,-1 * abs(0.018*rotate));
		
		
		glPushMatrix(); 
			glTranslatef(0, 0.1 + 1.75,0);
			glScalef(2,0.2,2);
			myCube.draw();
		glPopMatrix();

		metal->apply();
		
		glPushMatrix();
			glTranslatef(-1 + 0.1, 2,-1 + 0.1);
			glScalef(0.3,4,0.3);
			myCube.draw();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1 - 0.1,  2,-1 + 0.1);
			glScalef(0.3,4,0.3);
			myCube.draw();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(- 1 + 0.15, 0.875 , 1 - 0.15);
			glScalef(0.3,1.75,0.3);
			myCube.draw();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1 - 0.15, 0.875 , 1 - 0.15);
			glScalef(0.3,1.75,0.3);
			myCube.draw();
		glPopMatrix();

		wood->apply();

		glPushMatrix();
			glTranslatef(0,2.5 +0.8 ,-0.8);
			glRotated(-7,1,0,0);
			glScalef(1.5,1.5,0.25);
			myCube.draw();
		glPopMatrix();

	glPopMatrix();
}