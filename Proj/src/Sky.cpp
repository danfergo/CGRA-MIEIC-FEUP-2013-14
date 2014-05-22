#include "Sky.h"
#include <math.h>
#include "Texture.h"

static float pi = acos(-1.0);
static float ambientNull[4]={0,0,0,1};

Sky::Sky(unsigned st, unsigned sl): slices(sl< 3 ? 3 : sl),stacks(st < 1  ? 1 : st){
	dots = new PointP* [stacks+1];
	for (int i = 0; i <= stacks; ++i)
		dots[i] = new PointP[slices+1];
	
	angle_a = 2*pi/(float)slices;
	angle_b = (pi/(float)2)/stacks;
	
	
	for(unsigned i = 0 ; i <= stacks; i++){
		for(unsigned j = 0; j <= slices ; j++){
			dots[i][j].x = (float)cos((i)*angle_b)*sin(j*angle_a);
			dots[i][j].y = sin(angle_b*i);
			dots[i][j].z = cos((i)*angle_b)*cos(j*angle_a);
		}
	}

}

Sky::~Sky(){
	for (int i = 0; i < stacks; ++i)
		    delete [] dots[i];
	delete [] dots;
}


void Sky::draw(){

	glPushMatrix();
		textures::sky->apply();
		for(unsigned i = 0 ; i < stacks; i++){
			glPushMatrix();	
				glBegin(GL_TRIANGLE_STRIP);
					for(unsigned j = 0; j <= slices ; j++){
						/*
						if(j%2 == 0)
							glTexCoord2f((((float)(j+0.5)*angle_a)-(cos(angle_b*i)*angle_a*0.5))/((float)2*math::pi),dots[i][j].y);
						else
							glTexCoord2f((((float)(j-0.5)*angle_a)+(cos(angle_b*i)*angle_a*0.5))/((float)2*math::pi),dots[i][j].y);
						*/
						glTexCoord2f((j*angle_a)/((float)2*math::pi),dots[i][j].y);
						glNormal3d(-dots[i][j].x,-dots[i][j].y,-dots[i][j].z);
						glVertex3f(dots[i][j].x,dots[i][j].y,dots[i][j].z);
						/*
						if((j+1)%2 == 0)
							glTexCoord2f((((float)(j+0.5)*angle_a)-(cos(angle_b*(i+1))*angle_a*0.5))/((float)2*math::pi),dots[i+1][j].y);
						else
							glTexCoord2f((((float)(j-0.5)*angle_a)+(cos(angle_b*(i+1))*angle_a*0.5))/((float)2*math::pi),dots[i+1][j].y);
						*/
						glTexCoord2f((j*angle_a)/((float)2*math::pi),dots[i+1][j].y);
						glNormal3d(-dots[i+1][j].x,-dots[i+1][j].y,-dots[i+1][j].z);
						glVertex3f(dots[i+1][j].x,dots[i+1][j].y,dots[i+1][j].z);
						
						//(j*angle_a+0.5*angle_a-cos(angle_b*i)*angle_a)/((float)2*math::pi)
					}
				glEnd();
			
			
			glPopMatrix();
		}
		
		// top 
		
		glPushMatrix();
		//	glRotated(180,0,0,1);
			glNormal3d(0,1,0);
			glBegin(GL_POLYGON);
				for(unsigned i = 0; i < slices ; i++){
					glVertex3f(sin(i*angle_a),0,cos(i*angle_a));
				}
			glEnd();
		glPopMatrix();

	glPopMatrix();
} 

