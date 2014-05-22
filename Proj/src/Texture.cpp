#include "Texture.h"
#include "CGFobject.h"
#include <math.h>

namespace textures{
	float ambWood[3] = {0.70, 0.4, 0.0397}, difWood[3] = {0.38, 0.2, 0.0196},specWood[3] = {0.05, 0.05, 0.05}, shininessWood = 10.f;
	CGFappearance * wood = new CGFappearance(ambWood,difWood,specWood,shininessWood);
	
	float ambGroundWoodPattern[3]={0.05,0.025,0.01}, difGroundWoodPattern[3]= {0.4,0.25,0.1}, specGroundWoodPattern[3] = {0.01, 0.01, 0.01}, shininessGroundWoodPattern = 5.f;
	CGFappearance * groundWoodPattern= new CGFappearance(ambGroundWoodPattern,difGroundWoodPattern,specGroundWoodPattern,shininessGroundWoodPattern);

	float ambMetal[3] = {0.4, 0.4, 0.4}, difMetal[3] = {0.4, 0.4, 0.4}, specMetal[3] = {1, 1, 1}, shininessMetal = 5000.f;
	CGFappearance * grayMetal = new CGFappearance(ambMetal,difMetal,specMetal,shininessMetal);

	float ambCementWall[3]={0.5,0.5,0.5}, difCementWall[3] = {0.9,0.9,0.9}, specCementWall[3] = {0.01, 0.01, 0.01}, shininessCementWall= 5.f;
	CGFappearance * cementWall = new CGFappearance(ambCementWall,difCementWall,specCementWall,shininessCementWall);
	CGFappearance * windowWall = new CGFappearance(ambCementWall,difCementWall,specCementWall,shininessCementWall);

	float ambA[3] = {1,1,1}, difA[3] = {1,1,1}, specA[3] = {0.1, 0.1, 0.1}, shininessA = 10.f;
	float ambB[3] = {0.2, 0.2, 0.2}, difB[3] = {0.7, 0.7, 0.7}, specB[3] = {0.9, 0.9, 0.9}, shininessB = 120.f;


	CGFappearance * clockFace = new CGFappearance(ambCementWall,difCementWall,specCementWall,shininessCementWall);
	CGFappearance * boardA[3] =  { new CGFappearance(ambA,difA,specA,shininessB), new CGFappearance(ambA,difA,specA,shininessB), new CGFappearance(ambA,difA,specA,shininessB)};
	CGFappearance * boardB = new CGFappearance(ambB,difB,specB,shininessB);

	CGFappearance * impostor = new CGFappearance(ambB,difB,specB,shininessB);
	CGFappearance * sky = new CGFappearance(ambB,difB,specB,shininessB);
	
	void loadImageTextures(){
		wood->setTexture("table.png");
		cementWall->setTexture("wall.png");
		groundWoodPattern->setTexture("floor.png");
		clockFace->setTexture("clock.png");

		boardB->setTexture("board.png");
		boardB->setTextureWrap(GL_CLAMP,GL_CLAMP);

		boardA[2]->setTexture("slide3.png");
		boardA[2]->setTextureWrap(GL_CLAMP,GL_CLAMP);

		boardA[1]->setTexture("slide2.png");
		boardA[1]->setTextureWrap(GL_CLAMP,GL_CLAMP);
	
		boardA[0]->setTexture("slide1.png");
		boardA[0]->setTextureWrap(GL_CLAMP,GL_CLAMP);

		impostor->setTexture("landscape.jpg");
		impostor->setTextureWrap(GL_CLAMP,GL_CLAMP);

		windowWall->setTexture("window.png");
		windowWall->setTextureWrap(GL_CLAMP, GL_CLAMP);
	
		sky->setTexture("sky.png");
	}

}

namespace colors{
	float ambientNull[4]={0,0,0,1};
	float yellow[4]={1,1,0,1};
}

namespace math{
	float pi = acos(-1.0);
	float deg2rad=pi/180.0;
}