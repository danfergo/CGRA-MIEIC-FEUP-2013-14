#include "MySheet.h"

MySheet::MySheet(): CGFobject(){
	rot = (rand() % 91) - 45;
}

void MySheet::draw(){
	glPushMatrix();
		MyUnitCube c = MyUnitCube();
		glRotated(rot,0,1,0);
		glScalef(1.5,0.05,1);
		c.draw();
	glPopMatrix();
}

