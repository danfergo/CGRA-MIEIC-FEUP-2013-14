#include "MyLamp.h"
#include "Texture.h"

float lamp_light_diffuse[4] = {1,1,1,1};
float lamp_light_specular[4] = {0.1,0.1,0.1,1};
float lamp_light_pos[4]= {0,0.5,0,1};

float ambTurnedOn[4] = {20, 20, 20,1};
float ambTurnedOff[4] = {1, 1, 1,1};

float material_dif[4] = {1, 1, 1,1};
float material_spec[4] = {1, 1,1,1};
float material_shininess = 120.f;

MyLamp::MyLamp(unsigned int lightid){
	semisphere = new MySemiSphere(15,15);
	bottom = new myCylinder(30,10,true);

	light = new CGFlight(lightid,lamp_light_pos);
	light->setDiffuse(lamp_light_diffuse);
	light->setSpecular(lamp_light_specular);

	this->material = new CGFappearance(ambTurnedOn,material_dif,material_spec,material_shininess);	
}

void MyLamp::draw(){
	light->draw();

	glPushMatrix();
		glScalef(1.3,0.1,1.3);
		textures::wood->apply();
		bottom->draw();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,0.1,0);
		material->apply();
		semisphere->draw();
	glPopMatrix();
}

void MyLamp::setState(bool s){
	if(s){
		this->material->setAmbient(ambTurnedOn);
		light->enable();
	}else{
		this->material->setAmbient(ambTurnedOff);
		light->disable();
	}
}

MyLamp::~MyLamp(){
	delete(light);
	delete(material);
	delete(semisphere);
}