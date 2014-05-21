#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include <iostream>
#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};
float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};
float light_window_pos[4] = {0, 5, 7.5, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0.1,0.1,0.1,1};

// number of divisions
#define BOARD_A_DIVISIONS 30 
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {1,1,1};
float difA[3] = {1,1,1};
float specA[3] = {0.1, 0.1, 0.1};
float shininessA = 10.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.7, 0.7, 0.7};
float specB[3] = {0.9, 0.9, 0.9};
float shininessB = 120.f;

float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};


float ambFloor[3] ={0.05,0.025,0.01};
float difFloor[3] = {0.4,0.25,0.1};
float specFloor[3] = {0.01, 0.01, 0.01};
float shininessFloor = 5.f;

float ambWall[3] ={0.5,0.5,0.5};
float difWall[3] = {0.9,0.9,0.9};
float specWall[3] = {0.01, 0.01, 0.01};
float shininessWall = 5.f;

float ambLeftWall[3] ={0.5,0.5,0.5};
float difLeftWall[3] = {0.9,0.9,0.9};
float specLeftWall[3] = {0.01, 0.01, 0.01};
float shininessLeftWall = 5.f;


CGFappearance * wallMaterial;
CGFappearance * floorAppearance;
CGFappearance * windowAppearance;
CGFappearance * columnAppearance;
CGFappearance * clockAppearance;

 time_t timer;

void LightingScene::robotForward(){
	robot->forward();
}
 void LightingScene::robotLeft(){
	robot->toLeft();
 }
 void LightingScene::robotBackwards(){
	robot->backwards();
 }
void LightingScene::robotRight(){
	robot->toRight();
 }

void LightingScene::init() 
{
	toRight=false; toLeft=false; toForward=false; toBackwards=false;
	lightsState[0] = 1; lightsState[1] = 0; lightsState[2] = 0; lightsState[3] = 0; lightsState[4] = 0;  lightsState[5] = 0;
	clockState = 1; slideNum=0;
	
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  
	
	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  
	
	// Declares lights
	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);	

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);

	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(0);
	light2->setKl(1);
	light2->setKq(0);

	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setKc(0);
	light3->setKl(0);
	light3->setKq(0.2);

	lightWindow = new CGFlight(GL_LIGHT4, light_window_pos);
	lightWindow->setAmbient(ambientNull);
	lightWindow->setSpecular(yellow);

	// Uncomment below to enable normalization of lighting normal vectors
	glEnable (GL_NORMALIZE);

	// Enalble shade model GL_FLAT
	// glShadeModel(GL_FLAT);


	//Declares scene elements
	table = new MyTable();
	chair = new MyChair();
	wall = new Plane(100,-1.25,2.25,-0.5,1.5);
	boardWall = new Plane(100, 0,3.50,0.075,2);
	floor = new Plane(50, 0,12,0,10);
	cilindro = new myCylinder(15,5,true);
	lamp = new MyLamp(GL_LIGHT5);


	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);
	
	leftWall = new LeftWall();


	//Declares materials
	slidesAppearance[2] = new CGFappearance(ambA,difA,specA,shininessB);
	slidesAppearance[2]->setTexture("slide3.png");
	slidesAppearance[2]->setTextureWrap(GL_CLAMP,GL_CLAMP);

	slidesAppearance[1] = new CGFappearance(ambA,difA,specA,shininessB);
	slidesAppearance[1]->setTexture("slide2.png");
	slidesAppearance[1]->setTextureWrap(GL_CLAMP,GL_CLAMP);
	
	slidesAppearance[0] = new CGFappearance(ambA,difA,specA,shininessB);
	slidesAppearance[0]->setTexture("slide1.png");
	slidesAppearance[0]->setTextureWrap(GL_CLAMP,GL_CLAMP);

	boardA->calculateTextFit(BOARD_WIDTH,BOARD_HEIGHT,512,512);

	
	boardAppearance = new CGFappearance(ambB,difB,specB,shininessB);
	boardAppearance->setTexture("board.png");
	boardAppearance->setTextureWrap(GL_CLAMP,GL_CLAMP);
	boardB->calculateTextFit(BOARD_WIDTH,BOARD_HEIGHT,512,327);

	windowAppearance= new CGFappearance(ambLeftWall,difLeftWall,specLeftWall,shininessLeftWall);
	windowAppearance->setTexture("window.png");
	windowAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	wallMaterial = new CGFappearance(ambWall,difWall,specWall,shininessWall);
	wallMaterial->setTexture("wall.png");

	floorAppearance = new CGFappearance(ambWall,difFloor,specFloor,shininessFloor);
	floorAppearance->setTexture("floor.png");

	columnAppearance= new CGFappearance(ambLeftWall,difLeftWall,specLeftWall,shininessLeftWall);
	columnAppearance->setTexture("wall.png");

	//Clock
	clockAppearance= new CGFappearance(ambLeftWall,difLeftWall,specLeftWall,shininessLeftWall);
	clockAppearance->setTexture("clock.png");

	clock = new MyClock(3,30,45);

	time(&timer);  /* get current time; same as: timer = time(NULL)  */

	gmtime(&timer);

	setUpdatePeriod(10);

	//Robot
	robot = new MyRobot();

	//impostor

	impostor = new Plane(BOARD_A_DIVISIONS);
	impostorText = new CGFappearance(ambA,difA,specA,shininessB);
	impostorText->setTexture("landscape.jpg");
	impostor->calculateTextFit(30,18,2048,1221);
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

	if(lightsState[0]) lamp->setState(true); else lamp->setState(false);
	if(lightsState[1]) light0->enable(); else light0->disable();
	if(lightsState[2]) light1->enable(); else light1->disable();
	if(lightsState[3]) light2->enable(); else light2->disable();
	if(lightsState[4]) light3->enable(); else light3->disable();


	lightWindow->update();
	light0->draw();
	light1->draw();
	light2->draw();
	light3->draw();
	
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	glPushMatrix();
		glTranslatef(7.5,8,7.5);
		glRotated(180,1,0,0);
		lamp->draw();
	glPopMatrix();

	//	ROBOT
	robot->draw();

	//Impostor
	impostorText->apply();
	glPushMatrix();
		glTranslated(-25,-2,5);
		glRotated(90,0,1,0);
		glRotated(90,1,0,0);
		glScaled(60,1,40);
		impostor->draw();
	glPopMatrix();

	// CLOCK !
	clockAppearance->apply();
	glPushMatrix();
		glTranslatef(7.25,7.5,0.2);
		glScalef(0.45,0.45,1);
		clock->draw();
	glPopMatrix();

	// Cylinders
	columnAppearance->apply();

	glPushMatrix();	
		glScaled(1,8,1);	
		
		glPushMatrix();
			cilindro->setSmooth(true);
			glTranslatef(3,0,13);
			cilindro->draw();
		glPopMatrix(); 
		
		//glPushMatrix();
			//cilindro->setSmooth(false);
			//glTranslatef(12,0,4);
			//cilindro->draw();
		//glPopMatrix(); 
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

	floorAppearance->apply();

	//Floor
	glPushMatrix();
		glTranslated(7.5,0,7.5);
		glScaled(15,0.2,15);
		floor->draw();
	glPopMatrix();

	wallMaterial->apply();

	//PlaneWall
	glPushMatrix();
		glTranslated(7.5,4,0);
		glRotated(90.0,1,0,0);
		glScaled(15,0.2,8);
		boardWall->draw();
	glPopMatrix();

	//LeftWall
	glPushMatrix();
		windowAppearance->apply();
		leftWall->draw();
	glPopMatrix();

	glPushMatrix();
		glTranslated(-0.1,4,7.5);
		glRotated(-90.0,0,0,1);
		glRotated(90.0,0,1,0);
		glScaled(15,0.2,8);
		windowAppearance->apply();
	//	wall->draw();
	glPopMatrix();


	// Board A
	glPushMatrix();
		glTranslated(4,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		slidesAppearance[slideNum]->apply();
		boardA->draw();
	glPopMatrix();
	
	//PlaneB
	glPushMatrix();
		glTranslated(10.5,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		boardAppearance->apply();
		boardB->draw();
	glPopMatrix();
	
	// ---- END Primitive drawing section
	

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

void LightingScene::update(unsigned long t){
	
	if(clockState) clock->update(t);

	if(windowNotStop) windowNotStop=leftWall->update(windowState);

	bool rToBackwards = toBackwards && !toForward;

	if(toForward) robotForward();
	if(toLeft) {if(rToBackwards) robotRight(); else robotLeft();};
	if(toBackwards) robotBackwards();
	if(toRight) {if(rToBackwards) robotLeft(); else robotRight();};
}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);
	delete(light2);
	delete(light3);
	delete(lightWindow);
	delete(robot);

	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(slidesAppearance);
	delete(boardAppearance);
}