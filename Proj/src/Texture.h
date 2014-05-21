#pragma once
#ifndef TEXTURES_FILE
#define TEXTURES_FILE

#include "CGFappearance.h"

namespace textures{
	extern float ambWood[3], difWood[3],specWood[3], shininessWood;
	extern CGFappearance * wood;
	extern float ambGroundWoodPattern[3], difGroundWoodPattern[3], specGroundWoodPattern[3], shininessGroundWoodPattern;
	extern CGFappearance * groundWoodPattern;
	extern float ambMetal[3], difMetal[3], specMetal[3], shininessMetal;
	extern CGFappearance * grayMetal;
	extern float ambCementWall[3], difCementWall[3], specCementWall[3], shininessCementWall;
	extern CGFappearance * cementWall;

	extern float ambA[3], difA[3], specA[3], shininessA;
	extern float ambB[3], difB[3], specB[3], shininessB;
	extern CGFappearance * clockFace;
	extern CGFappearance * boardA[3];
	extern CGFappearance * boardB;
	extern CGFappearance * impostor;
	extern CGFappearance * windowWall;
	void loadImageTextures();
}

namespace colors{
	extern float ambientNull[4];
	extern float yellow[4];
}

namespace math {
	extern float pi;
	extern float deg2rad;
}
#endif