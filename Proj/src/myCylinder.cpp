#include "myCylinder.h"
#include <math.h>

float pii = acos(-1.0);


myCylinder::myCylinder(int sl, int st, bool sm): slices(sl< 3 ? 3 : sl),stacks(st < 1  ? 1 : st), smooth(sm) {
	dots = new Point2D [slices+1];

	angle = (2*pii)/(float)slices;
	stacks_height = 1 /(float) this->stacks;

	for(unsigned j = 0; j <= slices ; j++){
		dots[j].x = sin(j*angle);
		dots[j].z = cos(j*angle);
	}



}

myCylinder::~myCylinder(){
	delete [] dots;
}

void myCylinder::drawPolygon(){
	glPushMatrix();
		glNormal3d(0,1,0);
		glBegin(GL_POLYGON);
		for(int i = 0; i < slices ; i++){
			glTexCoord2f(0.5*(sin(i*angle))+0.5,-0.5*(cos(i*angle))+0.5);
			glVertex3f(sin(i*angle),0,cos(i*angle));
		}
		glEnd();
	glPopMatrix();

}


void myCylinder::drawPipe(unsigned i){
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
		for(int j = 0; j <= slices ; j++){
			glNormal3d(dots[j].x,0,dots[j].z);

			glTexCoord2f(j/(float)slices,1);
			glVertex3f(dots[j].x,stacks_height,dots[j].z);

			glTexCoord2f(j/(float)slices,0);
			glVertex3f(dots[j].x,0,dots[j].z);



			//glNormal3d(sin(j*angle),0,cos(j*angle));
			
			//glTexCoord2f(j/(float)slices,1);
			//glVertex3f(sin(j*angle),stacks_height,cos(j*angle));

			//glTexCoord2f(j/(float)slices,0);
			//glVertex3f(sin(j*angle),0,cos(j*angle));
		}
		glEnd();
	glPopMatrix();
}

void myCylinder::drawPlygonalPipe(){
	glPushMatrix();
		glBegin(GL_QUADS);
		for(int i = 0; i < slices ; i++){

				glNormal3d(sin(i*angle + (angle/2)),0,cos(i*angle + (angle/2)));
				
				glTexCoord2f(0,0);
				glVertex3f(sin(i*angle),0,cos(i*angle));

				glTexCoord2f(1,0);
				glVertex3f(sin((i+1)*angle),0,cos((i+1)*angle));
				
				glTexCoord2f(1,1);
				glVertex3f(sin((i+1)*angle),stacks_height,cos((i+1)*angle));
				
				glTexCoord2f(0,1);
				glVertex3f(sin(i*angle),stacks_height,cos(i*angle));
				
		
				
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
					drawPipe(i);
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