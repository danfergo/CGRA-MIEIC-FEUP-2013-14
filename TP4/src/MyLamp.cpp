#include "MyLamp.h"

MyLamp::MyLamp(unsigned int lightid){
	semisphere = new MySemiSphere(64,64);
	bottom = new myCylinder(30,10,true);

	float pos[4]= {0,0.5,0,1};
	light = new CGFlight(lightid,pos);
	float ambient[4] = {0.1,0.1,0.1,1};
	float diffuse[4] = {1,1,1,1};
	light->setAmbient(ambient);
	light->setDiffuse(diffuse);

	// material
	float amb[4] = {20, 20, 20,1};
	float dif[4] = {0, 0, 0,1};
	float spec[4] = {1, 1, 0,1};
	float shininess = 120.f;
	this->material = new CGFappearance(amb,dif,spec,shininess);



	float ambTop[4] = {1, 1, 1,1};
	float difTop[4] = {1, 1, 0,1};
	float specTop[4] = {1, 1, 0,1};
	float shininessTop = 120.f;
	
	float ambWood[3] ={0.70, 0.4, 0.0397};
	float difWood[3] = {0.38, 0.2, 0.0196};
	float specWood[3] = {0.05, 0.05, 0.05};
	float shininessWood = 10.f;

	this->materialTop = new CGFappearance(ambWood,difWood,specWood,shininessWood);

	
}


void MyLamp::draw(){
	light->draw();

	glPushMatrix();
		glScalef(1.3,0.1,1.3);
		materialTop->apply();
		bottom->draw();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,0.1,0);
		material->apply();
		semisphere->draw();
	glPopMatrix();
}

MyLamp::~MyLamp(){
	delete(light);
	delete(materialTop);
	delete(material);
	delete(semisphere);
}