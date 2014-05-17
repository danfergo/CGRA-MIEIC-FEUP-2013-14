#include "MyUnitCube.h"

void MyUnitCube::rectangle(float xi,float yi,float xf,float yf){
	glNormal3f(0,0,1);
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(xi,yi,0);

		glTexCoord2d(1,0);
		glVertex3f(xf,yi,0);

		glTexCoord2d(1,1);
		glVertex3f(xf,yf,0);

		glTexCoord2d(0,1);
		glVertex3f(xi,yf,0);
	glEnd();
}



void MyUnitCube::draw(){
		glPushMatrix();  // front 
		glTranslatef(0,0,0.5);
		rectangle(-0.5,-0.5,0.5,0.5);
	glPopMatrix();
	
	glPushMatrix(); // top 
		glTranslatef(0,0.5,0);
		glRotated(-90,1,0,0);
		rectangle(-0.5,-0.5,0.5,0.5);
	glPopMatrix();

	glPushMatrix(); // back 
		glTranslatef(0,0,-0.5);
		glRotated(-180,1,0,0);
		rectangle(-0.5,-0.5,0.5,0.5);
	glPopMatrix();

	glPushMatrix(); // bottom 
		glTranslatef(0,-0.5,0);
		glRotated(90,1,0,0);
		glRotated(90,0,0,1);
		rectangle(-0.5,-0.5,0.5,0.5);
	glPopMatrix();

	glPushMatrix(); // left 
		glTranslatef(-0.5,0,0);
		glRotated(-90,0,1,0);
		rectangle(-0.5,-0.5,0.5,0.5);
	glPopMatrix();

	glPushMatrix(); // right 
		glTranslatef(0.5,0,0);
		glRotated(90,0,1,0);
		rectangle(-0.5,-0.5,0.5,0.5);
	glPopMatrix();
};