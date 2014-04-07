#include "TPscene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#include "CGFappearance.h"
#include <time.h>       /* time */

#define ROWS	7   // Number of tables in a row
#define COLS	5   // Number of tables in a line


CGFappearance *mat1;

void TPscene::init() 
{
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);  // Define ambient light
	
	// Declares and enables a light
	float light0_pos[4] = {4.0, 6.0, 5.0, 1.0};
	CGFlight* light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->enable();

	// Defines a default normal
	glNormal3f(0,0,1);

	// Init myObject
		srand (time(NULL));
	this->myFloor = new MyFloor();
	for(int i= 0; i < (COLS*ROWS); i++){
		myChair.push_back(new MyChair());
		myTable.push_back(new MyTable());
		mySheet.push_back(new MySheet());
	}

}

void TPscene::display() 
{

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw axis
	axis.draw();
	
    // ---- END Background, camera and axis setup


	// ---- BEGIN Draw table




	

	/*

	glPushMatrix();
		glScaled(COLS,1,ROWS);
		glTranslated(4,0,3);
		myFloor->draw();
	glPopMatrix();
	glTranslatef(0,0.1,0);

	int c = 0;
	for(int i = 0; i < COLS; i++){
		for(int j = 0; j < ROWS; j++){
		glPushMatrix();
			glTranslated(4 + 8*i,0,3+6*j);
			myTable[c]->draw();

			glPushMatrix();
				glTranslatef(0,3.8,0);
				mySheet[c]->draw();
			glPopMatrix();

			glTranslatef(0,0,-1);
			myChair[c]->draw();
			
			c++;
		glPopMatrix();
		}
	}
	*/

		

	

	// ---- END Draw table

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

/******************* Old  transformation section *******************

	glPushMatrix();
	glTranslated(0, 5, 0);  // translate through yy, 5 units
	myObject->draw();
	glPopMatrix();


	// ---- BEGIN Geometric transformation section

	// NOTE: OpenGL transformation matrices are transposed

	// Translate (5, 0, 2)
	
	float tra[16] = { 1.0, 0.0, 0.0, 0.0,
                      0.0, 1.0, 0.0, 0.0,
                      0.0, 0.0, 1.0, 0.0,
                      5.0, 0.0, 2.0, 1.0}; 

	// Rotate 30 degrees around Y
	// These constants would normally be pre-computed at initialization time
	// they are placed here just to simplify the exampl
	
	float a_rad=30.0*deg2rad;
	float cos_a = cos(a_rad);
	float sin_a = sin(a_rad);

	float rot[16] = { cos_a,  0.0,  -sin_a,  0.0,
                      0.0,    1.0,   0.0,    0.0,
                      sin_a,  0.0,   cos_a,  0.0,
                      0.0,    0.0,   0.0,    1.0};

	// Scaling by (2,2,1)
	float sca[16] = { 2.0, 0.0, 0.0, 0.0,
                      0.0, 2.0, 0.0, 0.0,
                      0.0, 0.0, 1.0, 0.0,
                      0.0, 0.0, 0.0, 1.0};

	// Multiplication of the previous transformations
	glMultMatrixf(rot);     // GT = GT * rot
	glMultMatrixf(sca);     // GT = GT * sca 
	glMultMatrixf(tra);     // GT = GT * tra 
	//glRotated(30,0,1,0);
	glScaled(2,2,1);
	glTranslated(5, 0, 2);

	// ---- END Geometric transformation section
	

	// ---- BEGIN Primitive drawing section

    // NOTE: the visible face of the polygon is determined by the order of the vertices

	myObject->draw();  

	****************/