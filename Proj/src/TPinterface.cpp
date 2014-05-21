#include "TPinterface.h"
#include <iostream>

TPinterface::TPinterface(LightingScene* sc):CGFinterface(),lightingScene(sc){
	IisDown=false; JisDown=false; KisDown=false; LisDown=false;


	testVar=0;
}

void TPinterface::preprocessKeyboardUp(unsigned char key, int x, int y)
{
	modifiers=glutGetModifiers();
	((TPinterface *)CGFinterface::activeInterface)->processKeyboardUp(key,x,y); 
}

void TPinterface::processKeyboardUp(unsigned char key, int x, int y){
	switch(key)
	{
		case 'i':
			lightingScene->toForward = false;
			break;
		case 'j':
			lightingScene->toLeft = false;
			break;
		case 'k':
			lightingScene->toBackwards = false;
			break;
		case 'l':
			lightingScene->toRight = false;
			break;
	}
}




void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'i':
			lightingScene->toForward = true;
			break;
		case 'j':
			lightingScene->toLeft = true;
			break;
		case 'k':
			lightingScene->toBackwards = true;
			break;
		case 'l':
			lightingScene->toRight = true;
			break;
	}
}

void TPinterface::initGUI()
{
	GLUI_Panel * panel= addPanel("Luzes", 1);
	addCheckboxToPanel (panel, "Luz central",&lightingScene->lightsState[0], 2);
	addCheckboxToPanel (panel, "Luz sup. esq.", &lightingScene->lightsState[1], 3);
	addCheckboxToPanel (panel, "Luz sup. dir.", &lightingScene->lightsState[2], 4);
	addCheckboxToPanel (panel, "Luz inf. esq.", &lightingScene->lightsState[3], 5);
	addCheckboxToPanel (panel, "Luz sup. dir.", &lightingScene->lightsState[4], 6);

	addColumn();

	GLUI_Panel * panel2 = addPanel("Relogio",1);
	addButtonToPanel(panel2, "", 8)->set_name(lightingScene->clockState == 0 ? "Iniciar" : "Parar");
	
	GLUI_Panel * panel4 = addPanel("Janela",1);
	addButtonToPanel(panel4, "", 15)->set_name(lightingScene->windowState == 0 ? "Abrir" : "Fechar");

	addColumn();

	GLUI_Panel * panel3 = addPanel("Robot",1);

	GLUI_Listbox * listb = addListboxToPanel(panel3, "Textura ",  &lightingScene->robot->textureId, 9);
	listb->add_item(0,"Predefinicao");
	listb->add_item(1,"Aço");
	listb->add_item(2,"Hip-Hop");
	listb->add_item(3,"Azteca");

	addSeparatorToPanel(panel3);

	addStaticTextToPanel(panel3,"Modo de desenho:");
	GLUI_RadioGroup * rg = addRadioGroupToPanel(panel3,&lightingScene->robot->wireframe, 13);
	addRadioButtonToGroup (rg, "Textured");
	addRadioButtonToGroup (rg, "Wireframe");

	addColumn();

	GLUI_Panel * panel5 = addPanel("Slides",16);

	GLUI_Listbox * lists = addListboxToPanel(panel5, "Slides",  &lightingScene->slideNum, 14);
	lists->add_item(0,"Modelos de Iluminação");
	lists->add_item(1,"Smooth Shading");
	lists->add_item(2,"Ray Casting");
}


void TPinterface::processGUI(GLUI_Control *ctrl)
{
	switch (ctrl->user_id)
	{
		case 8:
		{
			lightingScene->clockState = !lightingScene->clockState;
			((GLUI_Button *)ctrl)->set_name(lightingScene->clockState == 0 ? "Iniciar" : "Parar");
			break;
		}
		case 15:
		{
			lightingScene->windowState = !lightingScene->windowState;
			lightingScene->windowNotStop = true;
			((GLUI_Button *)ctrl)->set_name(lightingScene->windowState == 0 ? "Abrir" : "Fechar");
			break;
		}
		case 16:
		{
			lightingScene->slideNum = (lightingScene->slideNum+1)%2;
			break;
		}
	};
}

