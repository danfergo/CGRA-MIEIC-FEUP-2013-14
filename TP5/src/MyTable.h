#pragma once

#include "CGFObject.h"
#include "MyUnitCube.h"
class MyTable: public CGFobject {
	float xTrans;
	float zTrans;
	int rPN;
	// Coefficients for material B

public:
	MyTable();
	void draw();
};

