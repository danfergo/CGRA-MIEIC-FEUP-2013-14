#pragma once

#include "CGFObject.h"
#include "MyUnitCube.h"

class MySheet: public CGFobject {
	int rot;
public:
	MySheet(void);
	void draw();
};

