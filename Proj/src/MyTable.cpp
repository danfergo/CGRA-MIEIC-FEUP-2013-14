#include "MyTable.h"
#include <iostream>
#include "CGFappearance.h"

static float ambWood[3] ={0.70, 0.4, 0.0397};
static float difWood[3] = {0.38, 0.2, 0.0196};
static float specWood[3] = {0.05, 0.05, 0.05};
static float shininessWood = 10.f;
static CGFappearance * wood = new CGFappearance(ambWood,difWood,specWood,shininessWood);

	
static float ambMetal[3] = {0.3, 0.3, 0.3};
static float difMetal[3] = {0.4, 0.4, 0.4};
static float specMetal[3] = {0.6, 0.6, 0.6};
static float shininessMetal = 500.f;
static CGFappearance * metal = new CGFappearance(ambMetal,difMetal,specMetal,shininessMetal);

MyTable::MyTable(): CGFobject(){
	xTrans = (float)((rand() % 10) - 5) / 10;
	zTrans = (float)(rand() % 5) / 10;
		wood->setTexture("table.png");
	do{
		rPN = (rand() % 3) - 1;
	}while(rPN != -1 && rPN != 1);
}

void MyTable::draw(){ 

	MyUnitCube myUnitCube = MyUnitCube();
	
	glPushMatrix();
		glRotated(rPN*zTrans*30,0,1,0);
		glTranslatef(xTrans,0,zTrans);
		glPushMatrix();  // top
			glTranslatef(0, 0.15 + 3.5,0);
			glScalef(5,0.3,3);
			wood->apply();

			myUnitCube.draw();
		glPopMatrix();

	metal->apply();
	
	glPushMatrix(); // legs
		glTranslatef(0, 1.75,0);

		glPushMatrix();
			glTranslatef(-2.5 + 0.15, 0, -1.5 + 0.15);
			glScalef(0.3,3.5,0.3);
			myUnitCube.draw();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(2.5 - 0.15, 0, -1.5 + 0.15);
			glScalef(0.3,3.5,0.3);
			myUnitCube.draw();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.5 + 0.15, 0, 1.5 - 0.15);
			glScalef(0.3,3.5,0.3);
			myUnitCube.draw();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(2.5 - 0.15, 0, 1.5 - 0.15);
			glScalef(0.3,3.5,0.3);
			myUnitCube.draw();
		glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}