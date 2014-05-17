#pragma once

#include "CGFobject.h"
#include "CGFappearance.h"

typedef struct Point3d{
	float x, z, nx, nz;
	}Point3d;

class MyRobot : public CGFobject
{
	float coordx, coordz, angle, nyd, nym; //nyd quota-normal-diagonals; nyd quota-normal-middle(almost) 
	Point3d ** dots;
	float* quotas;
	unsigned stacks;
	CGFappearance* textRobot;
public:
	MyRobot(unsigned stacks=10);
	~MyRobot(void);
	void setPosition(float xx, float zz, float angle);
	void draw();
	void forward();
	void backwards();
	void toLeft();
	void toRight();
};

