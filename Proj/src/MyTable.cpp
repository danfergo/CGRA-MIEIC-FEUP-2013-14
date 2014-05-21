#include "MyTable.h"
#include <iostream>
#include "CGFappearance.h"
#include "Texture.h"

MyTable::MyTable(): CGFobject(){
	myCube = new MyUnitCube();
	xTrans = (float)((rand() % 10) - 5) / 10;
	zTrans = (float)(rand() % 5) / 10;
	do{
		rPN = (rand() % 3) - 1;
	}while(rPN != -1 && rPN != 1);
}

void MyTable::draw(){ 
	
	glPushMatrix();
		glRotated(rPN*zTrans*30,0,1,0);
		glTranslatef(xTrans,0,zTrans);
		glPushMatrix();  // top
			glTranslatef(0, 0.15 + 3.5,0);
			glScalef(5,0.3,3);
			textures::wood->apply();

			myCube->draw();
		glPopMatrix();

		textures::grayMetal->apply();
	
		glPushMatrix(); // legs
			glTranslatef(0, 1.75,0);

			glPushMatrix();
				glTranslatef(-2.5 + 0.15, 0, -1.5 + 0.15);
				glScalef(0.3,3.5,0.3);
				myCube->draw();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(2.5 - 0.15, 0, -1.5 + 0.15);
				glScalef(0.3,3.5,0.3);
				myCube->draw();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-2.5 + 0.15, 0, 1.5 - 0.15);
				glScalef(0.3,3.5,0.3);
				myCube->draw();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(2.5 - 0.15, 0, 1.5 - 0.15);
				glScalef(0.3,3.5,0.3);
				myCube->draw();
			glPopMatrix();

		glPopMatrix();

	glPopMatrix();
}