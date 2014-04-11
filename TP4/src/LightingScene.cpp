#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include <iostream>
//#include "MyTable.h"
//#include "Plane.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0,0,0,0};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0, 0.8, 0.8};
float shininessA = 10.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};


float ambFloor[3] ={0.2,0.2,0.2};
float difFloor[3] = {0.4,0.5,0.55};
float specFloor[3] = {0.01, 0.01, 0.01};
float shininessFloor = 5.f;

float ambWall[3] ={0.2,0.2,0};
float difWall[3] = {1,1,0.3};
float specWall[3] = {0.01, 0.01, 0};
float shininessWall = 5.f;

float ambLeftWall[3] ={0.2,0.2,0.1};
float difLeftWall[3] = {1,1,0.9};
float specLeftWall[3] = {0.01, 0.01, 0.01};
float shininessLeftWall = 5.f;


CGFappearance * wallMaterial;
CGFappearance * leftWall;
CGFappearance * floorMaterial;


void LightingScene::init() 
{
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  
	
	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  
	
	// Declares and enables two lights, with null ambient component
	/*
	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);	
	//light0->disable();
	light0->disable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	//light1->disable();
	light1->disable();
	
	
	//light2
	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	//light2->disable();
	light2->setKc(0);
	light2->setKl(1);
	light2->setKq(0);
	light2->disable();

	
	//light3
-	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	//light3->disable();
	light3->setKc(0);
	light3->setKl(0);
	light3->setKq(0.2);
	light3->disable(); */


	// Uncomment below to enable normalization of lighting normal vectors
	glEnable (GL_NORMALIZE);

	// Enalble shade model GL_FLAT
	// glShadeModel(GL_FLAT);


	//Declares scene elements
	table = new MyTable();
	chair = new MyChair();
	wall = new Plane(100,-1.25,2.25,-0.5,1.5);
	cilindro = new myCylinder(15,20,true);
	lamp = new MyLamp(GL_LIGHT4);


	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);
	
	//Declares materials	
	materialA = new CGFappearance(ambA,difA,specA,shininessB);
	materialA->setTexture("slides.png");
	materialA->setTextureWrap(GL_CLAMP,GL_CLAMP);
	boardA->calculateTextFit(BOARD_WIDTH,BOARD_HEIGHT,512,512);

	
	materialB = new CGFappearance(ambB,difB,specB,shininessB);
	materialB->setTexture("board.png");
	materialB->setTextureWrap(GL_CLAMP,GL_CLAMP);
	boardB->calculateTextFit(BOARD_WIDTH,BOARD_HEIGHT,512,327);

	
	wallMaterial = new CGFappearance(ambWall,difWall,specWall,shininessWall);
	leftWall = new CGFappearance(ambLeftWall,difLeftWall,specLeftWall,shininessLeftWall);
	leftWall->setTexture("window.png");
	leftWall->setTextureWrap(GL_CLAMP, GL_CLAMP);

	floorMaterial = new CGFappearance(ambWall,difFloor,specFloor,shininessFloor);
	floorMaterial->setTexture("floor.png");
}

void LightingScene::display() 
{

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// turing off 4 lights
	//light0->draw();
	//light1->draw();
	//light2->draw();
	//light3->draw();
	
	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	// Cylinders

	glPushMatrix();	
		glScaled(1,8,1);	
		
		glPushMatrix();
			cilindro->setSmooth(true);
			glTranslatef(3,0,4);
			cilindro->draw();
		glPopMatrix(); 
		
	/*	glPushMatrix();
			cilindro->setSmooth(false);
			glTranslatef(12,0,4);
			cilindro->draw();
		glPopMatrix(); */
	glPopMatrix(); 

		
	glPushMatrix();
		glTranslatef(7.5,8,7.5);
		glRotated(180,1,0,0);
		lamp->draw();
	glPopMatrix();
	
	//First Table
	glPushMatrix();
		glTranslated(5,0,8);
		table->draw();
		glTranslated(0,0,2);
		glRotated(180,0,1,0);
		chair->draw();
	glPopMatrix();

	//Second Table
	glPushMatrix();
		glTranslated(12,0,8);
		table->draw();
		glTranslated(0,0,2);
		glRotated(180,0,1,0);
		chair->draw();
	glPopMatrix();

	floorMaterial->apply();

	//Floor
	glPushMatrix();
		glTranslated(7.5,0,7.5);
		glScaled(15,0.2,15);
		wall->draw();
	glPopMatrix();

	wallMaterial->apply();

	//PlaneWall
	glPushMatrix();
		glTranslated(7.5,4,0);
		glRotated(90.0,1,0,0);
		glScaled(15,0.2,8);
		wall->draw();
	glPopMatrix();

	leftWall->apply();

	//LeftWall
	glPushMatrix();
		glTranslated(0,4,7.5);
		glRotated(-90.0,0,0,1);
		glRotated(90.0,0,1,0);
		glScaled(15,0.2,8);
		
		wall->draw();
	glPopMatrix();

	// Board A
	glPushMatrix();
		glTranslated(4,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		materialA->apply();
		boardA->draw();
	glPopMatrix();
	
	//PlaneB
	glPushMatrix();
		glTranslated(10.5,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		materialB->apply();
		boardB->draw();
	glPopMatrix();
	
	// ---- END Primitive drawing section
	

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);
	delete(light2);
	delete(light3);
	

	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
}