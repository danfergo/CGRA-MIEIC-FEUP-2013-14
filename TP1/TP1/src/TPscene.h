#ifndef TPSCENE_H
#define TPSCENE_H

#include "CGFscene.h"
#include "ExampleObject.h"

#include "MyTable.h"
#include "MyFloor.h"
class TPscene : public CGFscene
{
private:
	MyFloor * myFloor;
	MyTable * myTable;
public:
	void init();
	void display();
};

#endif