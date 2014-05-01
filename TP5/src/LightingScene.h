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

#include <time.h>       /* time_t, struct tm, difftime, time, mktime */


class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	virtual void update(unsigned long);

	CGFlight* light0;
	CGFlight* light1;


	//new lights
	CGFlight* light2;
	CGFlight* light3;

	MyTable * table;
	MyChair * chair;
	Plane* wall;
	Plane* boardWall;
	Plane * floor;

	Plane* boardA;
	Plane* boardB;
	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;

	//Clock
	MyClock * clock;

	//Cylinder
	myCylinder * cilindro;
	
	// MySemiShpere
	MyLamp * lamp;

	~LightingScene();
};

#endif