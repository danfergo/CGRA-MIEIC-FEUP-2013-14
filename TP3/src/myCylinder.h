#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGFobject.h"
	
class myCylinder : public CGFobject {
	private:
		float stacks_height, angle, stacks;
		unsigned slices;
		bool smooth;
		void drawPolygon();
		void drawPipe();
		void drawPlygonalPipe();
	public:
		myCylinder(int slices, int stacks, bool smooth);
		void draw();
		void setSmooth(bool sm);
};



#endif
