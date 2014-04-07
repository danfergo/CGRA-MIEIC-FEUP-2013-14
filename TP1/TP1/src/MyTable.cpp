#include "MyTable.h"

void MyTable::draw(){ 
	MyUnitCube myUnitCube = MyUnitCube();

	glPushMatrix();  // top
	glTranslatef(0, 0.15 + 3.5,0);
	glScalef(5,0.3,3);
	myUnitCube.draw();
	glPopMatrix();


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
}