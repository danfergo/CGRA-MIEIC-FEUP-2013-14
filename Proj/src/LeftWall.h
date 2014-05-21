#pragma once
#include "Plane.h"
#include "CGFobject.h"

class LeftWall: public CGFobject
{
	Plane *centerTop, *centerBottom, *left,*right, *leftWindow, *rightWindow;
	int angle;
public:
	LeftWall(void);
	~LeftWall(void);
	void draw();
	bool update(bool open);
};

