#pragma once

#include "CGFobject.h"
#include "CGFappearance.h"
#include "CGFlight.h"

typedef struct PointP {
   float x;
   float y;
   float z;
} PointP;


class Sky
{
public:
	private:
		float angle_a, angle_b;
		unsigned stacks, slices;
		PointP ** dots;
		
	public:
		Sky(unsigned stacks, unsigned slices);
		void draw();
		~Sky();
};

