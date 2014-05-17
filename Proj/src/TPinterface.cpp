#include "TPinterface.h"
#include <iostream>

TPinterface::TPinterface(LightingScene* sc):CGFinterface(),lightingScene(sc){
testVar=0;
}

void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'i':
			lightingScene->robotForward();
			break;
		case 'j':
			lightingScene->robotLeft();
			break;
		case 'k':
			lightingScene->robotBackwards();
			break;
		case 'l':
			lightingScene->robotRight();
			break;
	}
}

void TPinterface::initGUI()
{
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel= addPanel("Group", 1);
	addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);
	
	// You could also pass a reference to a variable from the scene class, if public
	addSpinnerToPanel(varPanel, "Val 2(scene)", 2, &(((LightingScene*) scene)->sceneVar), 2);

}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf ("GUI control id: %d\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
		case 1:
		{
			printf ("New Val 1(interface): %d\n",testVar);
			break;
		}

		case 2:
		{
			printf ("New Val 2(scene): %d\n",((LightingScene*) scene)->sceneVar);
			break;
		}
	};
}

