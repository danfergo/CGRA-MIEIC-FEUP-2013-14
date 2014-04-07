#pragma once

#include "CGFObject.h"
#include "MyUnitCube.h"

class MyChair: public CGFobject {
private:
	int rotate;
public:
	MyChair();
	void draw();
};

