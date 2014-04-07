#ifndef TPSCENE_H
#define TPSCENE_H

#include <vector>

#include "CGFscene.h"
#include "ExampleObject.h"


#include "MyTable.h"
#include "MyFloor.h"
#include "MyChair.h"
#include "MySheet.h"

class TPscene : public CGFscene
{
private:
	vector<MyChair *> myChair;
	MyFloor * myFloor;
	vector<MyTable *> myTable;
	vector<MySheet *> mySheet;
public:
	void init();
	void display();
};

#endif