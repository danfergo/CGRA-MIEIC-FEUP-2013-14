#include "myCylinder.h"
#include <math.h>

float pii = acos(-1.0);


myCylinder::myCylinder(int sl, int st, bool sm): slices(sl< 3 ? 3 : sl),stacks(st < 1  ? 1 : st), smooth(sm) {
		angle = (2*pii)/(float)slices;
		stacks_height = 1 /(float) this->stacks;
}


void myCylinder::drawPolygon(){
	glPushMatrix();
		glNormal3d(0,1,0);
		glBegin(GL_POLYGON);
		for(int i = 0; i < slices ; i++){
			glVertex3f(sin(i*angle),0,cos(i*angle));
		}
		glEnd();
	glPopMatrix();

}


void myCylinder::drawPipe(){
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
		for(int i = 0; i <= slices ; i++){
			glNormal3d(sin(i*angle),0,cos(i*angle));

			glVertex3f(sin(i*angle),stacks_height,cos(i*angle));
			glVertex3f(sin(i*angle),0,cos(i*angle));
		}
		glEnd();
	glPopMatrix();
}

void myCylinder::drawPlygonalPipe(){
	glPushMatrix();
		glBegin(GL_QUADS);
		for(int i = 0; i < slices ; i++){
			glNormal3d(sin(i*angle + (angle/2)),0,cos(i*angle + (angle/2)));
		
				glVertex3f(sin((i+1)*angle),0,cos((i+1)*angle));
				glVertex3f(sin((i+1)*angle),stacks_height,cos((i+1)*angle));
				
				glVertex3f(sin(i*angle),stacks_height,cos(i*angle));
				
				glVertex3f(sin(i*angle),0,cos(i*angle));		
				
		}	
		glEnd();
	glPopMatrix();
}


void myCylinder::draw(){
	glPushMatrix();

		for(int i = 0; i < stacks; i++){
			glPushMatrix();
				glTranslated(0,i*stacks_height,0);
				if(smooth) {
					drawPipe();
				} else{
					drawPlygonalPipe();
				};	
			glPopMatrix();	
		}
		
		glPushMatrix();
			glTranslated(0,1,0);
			this->drawPolygon();
		glPopMatrix();	
			
		glPushMatrix();	
			glRotated(180,0,0,1);
			this->drawPolygon();
		glPopMatrix();
	
		
	glPopMatrix();
}


void myCylinder::setSmooth(bool sm) {
	smooth = sm;
}