#pragma once

#include "CGFObject.h"
#include "MyUnitCube.h"

class MyChair: public CGFobject {
private:
	MyUnitCube * myCube;
	int rotate;
public:
	MyChair();
	void draw();
};

