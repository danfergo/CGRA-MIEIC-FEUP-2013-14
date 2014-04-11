#pragma once

#include "CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int);
	Plane(int n, float ui,float uf,float vi,float vf);
	~Plane(void);
	void draw();
	void calculateTextFit(float width, float height, float textureWidth, float textureHeight);
private:
	float ui, uf, vi,vf;
	int _numDivisions; // Number of triangles that constitute rows/columns
};

