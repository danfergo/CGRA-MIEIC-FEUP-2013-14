#include "MyFloor.h"


void MyFloor::draw(){
		glPushMatrix();

		MyUnitCube myUnitCube = MyUnitCube();
		glTranslatef(0,0.05,0);
		glScalef(8,0.1,6);
		myUnitCube.draw();

		glPopMatrix();
}



