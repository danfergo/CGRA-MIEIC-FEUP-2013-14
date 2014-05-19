#pragma once
#include "Plane.h"
#include "CGFobject.h"

class LeftWall: public CGFobject
{
	Plane *centerTop, *centerBottom, *left,*right, *leftWindow, *rightWindow;
public:
	LeftWall(void);
	~LeftWall(void);
	void draw();
};

