#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGFobject.h"

typedef struct Point2D {
   float x;
   float z;
} Point2D;

class myCylinder : public CGFobject {
	private:
		float stacks_height, angle ;
		unsigned slices,stacks;
		Point2D * dots;

		bool smooth;
		void drawPolygon();
		void drawPipe(unsigned);
		void drawPlygonalPipe();
	public:
		myCylinder(int slices=12, int stacks=5, bool smooth=true);
		~myCylinder();
		void draw();
		void setSmooth(bool sm);
};

#endif
