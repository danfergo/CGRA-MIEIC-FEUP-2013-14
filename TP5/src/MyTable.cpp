#include "MyTable.h"
#include <iostream>
#include "CGFappearance.h"

MyTable::MyTable(): CGFobject(){
	xTrans = (float)((rand() % 10) - 5) / 10;
	zTrans = (float)(rand() % 5) / 10;
	
	do{
		rPN = (rand() % 3) - 1;
	}while(rPN != -1 && rPN != 1);
}

void MyTable::draw(){ 
	float ambWood[3] ={0.70, 0.4, 0.0397};
	float difWood[3] = {0.38, 0.2, 0.0196};
	float specWood[3] = {0.05, 0.05, 0.05};
	float shininessWood = 10.f;
	CGFappearance * wood = new CGFappearance(ambWood,difWood,specWood,shininessWood);

	float ambMetal[3] = {0.3, 0.3, 0.3};
	float difMetal[3] = {0.4, 0.4, 0.4};
	float specMetal[3] = {0.6, 0.6, 0.6};
	float shininessMetal = 500.f;
	CGFappearance * metal = new CGFappearance(ambMetal,difMetal,specMetal,shininessMetal);



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