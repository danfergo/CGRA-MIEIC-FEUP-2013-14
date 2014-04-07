#ifndef TPSCENE_H
#define TPSCENE_H

#include "CGFscene.h"
#include "ExampleObject.h"

class TPscene : public CGFscene
{
private:
	ExampleObject myObject;
public:
	void init();
	void display();
};

#endif