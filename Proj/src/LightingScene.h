#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "MyTable.h"
#include "Plane.h"
#include "MyChair.h"
#include "myCylinder.h"
#include "MyLamp.h"
#include "MyClock.h"
#include "MyRobot.h"

#include <time.h>       /* time_t, struct tm, difftime, time, mktime */

class LightingScene : public CGFscene
{
private:
	MyRobot* robot;
public:
	void init();
	void display();
	virtual void update(unsigned long);
	void toggleSomething(){};

	int sceneVar;

	CGFlight* light0;
	CGFlight* light1;
	

	//new lights
	CGFlight* light2;
	CGFlight* light3;

	MyTable * table;
	MyChair * chair;
	Plane* wall;
	Plane* boardWall;
	Plane* floor;
	Plane* impostor;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* impostorText;

	//Clock
	MyClock * clock;

	//Cylinder
	myCylinder * cilindro;
	
	// MySemiShpere
	MyLamp * lamp;

	~LightingScene();

	//Robot
	void robotForward();
	void robotLeft();
	void robotBackwards();
	void robotRight();
};

#endif