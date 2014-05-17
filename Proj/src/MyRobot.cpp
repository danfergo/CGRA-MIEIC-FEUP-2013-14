#include "MyRobot.h"
#include <math.h>
#include <iostream>

using namespace std;

float PI=acos(-1.0), degree2rad=PI/180;

float ambR[3] = {1,1,1};
float difR[3] = {1,1,1};
float specR[3] = {0.1, 0.1, 0.1};
float shininessR = 10.f;

MyRobot::MyRobot(unsigned stacks):coordx(8),coordz(8),angle(0),stacks(stacks){
	
	textRobot = new CGFappearance(ambR,difR,specR,shininessR);
	textRobot->setTexture("robot.jpg");

	dots = new Point3d* [stacks+1];
	for(unsigned i=0; i<=stacks; i++)
		dots[i] = new Point3d[13];
	quotas = new float[stacks+1];

	//m=xf-xi
	nyd=1/sqrt(2.0)-0.25;
	nym=sqrt(9.25/36)-0.25;

	//points for square base
	//creats 4 points each iteration in right bottom vertex in each corner anti-clockwise
	for(unsigned j=0; j<3; j++){
		dots[0][j].x=0.5; dots[0][j].z=0.5-(float)j/3;//right
		dots[0][j+3].x=0.5-(float)j/3; dots[0][j+3].z=-0.5;//top
		dots[0][j+6].x=-0.5; dots[0][j+6].z=-0.5+(float)j/3;//left
		dots[0][j+9].x=-0.5+(float)j/3; dots[0][j+9].z=0.5;//bottom
	}

	//normal to points
	for(unsigned j=0; j<4; j++){
		dots[0][j*3].nx = sin(PI/4+j*PI/2); dots[0][j*3].nz = cos(PI/4+j*PI/2);
		dots[0][j*3+1].nx = (j%2!=0)? 0:(j==0 ? 1 : -1); dots[0][j*3+1].nz = (j%2==0)? 0:(j==1 ? -1 : 1);
		dots[0][j*3+2].nx = dots[0][j*3+1].nx; dots[0][j*3+2].nz = dots[0][j*3+1].nz;
	}

	dots[0][12]=dots[0][0];

	//points for circumference top
	for(unsigned j=0; j<=12; j++){
		dots[stacks][j].x=0.25*sin(j*PI/6+PI/4); dots[stacks][j].z=0.25*cos(j*PI/6+PI/4);
		dots[stacks][j].nx = sin(PI/4+j*PI/6); dots[stacks][j].nz = cos(PI/4+j*PI/6);
	}


	for(unsigned i=0; i<=stacks; i++)
		quotas[i]=i*1.0/stacks;
	
	//points for body
	float dx, dz;
	for(unsigned j=0; j<=12; j++){
		dx = (float)(dots[stacks][j].x - dots[0][j].x)/stacks;
		dz = (float)(dots[stacks][j].z - dots[0][j].z)/stacks;
		for(unsigned i=1; i<stacks; i++){
			dots[i][j].x = dots[0][j].x + i*dx;
			dots[i][j].z = dots[0][j].z + i*dz;
		}
	}

	//normal
	float mx, mz, k;
	for(unsigned j=0; j<=12; j++){
		mx = (float)(dots[stacks][j].nx - dots[0][j].nx)/stacks;
		mz = (float)(dots[stacks][j].nz - dots[0][j].nz)/stacks;
		for(unsigned i=1; i<stacks; i++){
			dots[i][j].nx = dots[0][j].nx + i*mx;
			dots[i][j].nz = dots[0][j].nz + i*mz;
			k = 1/sqrt(pow(2,dots[i][j].nx) + pow(2,dots[i][j].nx));
			dots[i][j].nx *= k;
			dots[i][j].nz *= k;

		}
	}

}

MyRobot::~MyRobot(void){
	for(unsigned i=0; i<=stacks; i++)
		delete[] dots[i];
	delete[] dots;
	delete[] quotas;
}

void MyRobot::setPosition(float xx, float zz, float angle){
	coordx=xx;
	coordz=zz;
	this->angle=angle;
}

void MyRobot::draw(){
	glPushMatrix();
	
	textRobot->apply();

	glTranslated(coordx,0,coordz);
	glRotated(angle,0,1,0);
	
	glNormal3d(0,1,0);
	glBegin(GL_POLYGON);
	for(unsigned j=0; j<12; j++){
		glTexCoord2f(0.5+dots[stacks][j].x,-0.5-dots[stacks][j].z);
		glVertex3f(dots[stacks][j].x,quotas[stacks],dots[stacks][j].z);
	}
	glEnd();

	/*glBegin(GL_TRIANGLES);
	glVertex3f(0.5,0.3,0);
	glVertex3f(-0.5,0.3,0);
	glVertex3f(0,0.3,2);
	glEnd();*/

	for(unsigned j=0; j<12; j++){
		glBegin(GL_TRIANGLE_STRIP);
		for(unsigned i=0; i<=stacks; i++){
			glTexCoord2f(0.5+dots[i][j].x,-0.5-dots[i][j].z);
			glNormal3f(dots[i][j].nx, j%3==0 ? nyd : nym, dots[i][j].nz);
			glVertex3f(dots[i][j].x,quotas[i],dots[i][j].z);
			
			glTexCoord2f(0.5+dots[i][j+1].x,-0.5-dots[i][j+1].z);
			glNormal3f(dots[i][j+1].nx, (j+1)%3==0 ? nyd : nym, dots[i][j+1].nz);
			glVertex3f(dots[i][j+1].x,quotas[i],dots[i][j+1].z);
		}
		glEnd();
	}
	
	glNormal3d(0,-1,0);
	glBegin(GL_POLYGON);
	for(unsigned j=12; j>0; j--)
		glVertex3f(dots[0][j].x,quotas[0],dots[0][j].z);
	glEnd();

	glPopMatrix();
}

void MyRobot::backwards(){
	coordz-=cos(angle*degree2rad)*0.3;
	coordx-=sin(angle*degree2rad)*0.3;
}

void MyRobot::forward(){
	coordz+=cos(angle*degree2rad)*0.3;
	coordx+=sin(angle*degree2rad)*0.3;
}

void MyRobot::toLeft(){
	angle+=05;
}

void MyRobot::toRight(){
	angle-=05;
}