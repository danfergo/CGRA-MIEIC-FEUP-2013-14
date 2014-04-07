#include "MySemiSphere.h"
#include <math.h>

static float pi = acos(-1.0);
static float ambientNull[4]={0,0,0,1};



MySemiSphere::MySemiSphere(unsigned st, unsigned sl): slices(sl< 3 ? 3 : sl),stacks(st < 1  ? 1 : st) {

	angle_a = 2*pi/(float)slices;
	angle_b = (pi/(float)2)/stacks;
}


void MySemiSphere::draw(){

		
	glPushMatrix();
		


		for(unsigned i = 0 ; i < stacks; i++){
			glPushMatrix();	
				//glTranslatef(0,i*sin(angle_b),0);
			

				glBegin(GL_QUAD_STRIP);
					for(unsigned j = 0; j <= slices ; j++){
						glNormal3d(cos((i+1)*angle_b)*sin(j*angle_a),sin(angle_b*(i+1)),cos((i+1)*angle_b)*cos(j*angle_a));
						glVertex3f(cos((i+1)*angle_b)*sin(j*angle_a),sin(angle_b*(i+1)),cos((i+1)*angle_b)*cos(j*angle_a));
					
						glNormal3d(cos((i)*angle_b)*sin(j*angle_a),sin(angle_b*i),cos((i)*angle_b)*cos(j*angle_a));
						glVertex3f(cos((i)*angle_b)*sin(j*angle_a),sin(angle_b*i),cos((i)*angle_b)*cos(j*angle_a));
					}
				glEnd();
			
			
			glPopMatrix();
		}
		
		// top 
		
		glPushMatrix();
			glRotated(180,0,0,1);
			glNormal3d(0,1,0);
			glBegin(GL_POLYGON);
				for(unsigned i = 0; i < slices ; i++){
					glVertex3f(sin(i*angle_a),0,cos(i*angle_a));
				}
			glEnd();
		glPopMatrix();

	glPopMatrix();
} 

