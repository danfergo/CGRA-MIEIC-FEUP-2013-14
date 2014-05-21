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
#include "LeftWall.h"

#include <time.h>       //time_t, struct tm, difftime, time, mktime

class LightingScene : public CGFscene
{
private:
	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	CGFlight* lightWindow;

	MyLamp * lamp;

public:
	void init();
	void display();
	virtual void update(unsigned long);
	~LightingScene();

	//Robot movment
	void robotForward();
	void robotLeft();
	void robotBackwards();
	void robotRight();

	int robotTexture, clockState, lightsState[5], slideNum;
	bool toRight,toLeft,toForward, toBackwards, windowState, windowNotStop;

	MyRobot* robot;

	MyTable * table;
	MyChair * chair;
	Plane* wall;
	Plane* boardWall1,* boardWall2,* boardWall3,* boardWall4;
	Plane* floor;
	Plane* impostor;
	Plane* boardA;
	Plane* boardB;

	//CGFappearance* slidesAppearance[3];
	//CGFappearance* boardAppearance;
	//CGFappearance* impostorText;

	MyClock * clock;
	myCylinder * cilindro;
	LeftWall * leftWall;
};

#endif