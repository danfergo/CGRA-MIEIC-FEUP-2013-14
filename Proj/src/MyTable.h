#pragma once

#include "CGFObject.h"
#include "MyUnitCube.h"
class MyTable: public CGFobject {
	MyUnitCube * myCube;
	float xTrans;
	float zTrans;
	int rPN;
public:
	MyTable();
	void draw();
};

