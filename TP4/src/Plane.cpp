#include "Plane.h"
#include <GL/glu.h>


Plane::Plane(void)
{
	_numDivisions = 1;
}

Plane::Plane(int n)
{
	_numDivisions = n;
}


Plane::Plane(int n, float ui,float uf,float vi,float vf):ui(ui),vi(vi),vf(vf),uf(uf)
{
	_numDivisions = n;
}


Plane::~Plane(void)
{
}

void Plane::calculateTextFit(float planeW, float planeH, float textW, float textH){
	
	float appTextH = (textH/(float)textW) < (planeH/(float)planeW) ? planeW*(textH/(float)textW) : planeH;
	float appTextW =  (textH/(float)textW) < (planeH/(float)planeW) ? planeW : planeH*(textW/(float)textH);

	float alphaH= ((float)1 - (appTextH/(float)planeH))/2;
	float alphaW = ((float)1 - (appTextW/(float)planeW))/2;

	ui = -alphaW;
	uf = 1 + alphaW;
	vi = -alphaH;
	vf = 1 + alphaH;
}

void Plane::draw()
{
	float deltaU = uf - ui; 
	float deltaV = vf - vi;



	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
				glTexCoord2f(ui + deltaU*((float)(bx)/_numDivisions), vi);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glTexCoord2f(ui + deltaU*((float)(bx+1)/_numDivisions),deltaV*((float)(bz)/_numDivisions) + vi);
					glVertex3f(bx + 1, 0, bz);
					
					glTexCoord2f(ui + deltaU*((float)(bx)/_numDivisions),deltaV*((float)(bz+1)/_numDivisions) + vi);
					glVertex3f(bx, 0, bz + 1);
				}
				
				glTexCoord2f(ui + deltaU*((float)(bx+1)/_numDivisions), vf);
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}
