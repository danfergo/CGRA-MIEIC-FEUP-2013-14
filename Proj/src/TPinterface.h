#ifndef TPinterface_H
#define TPinterface_H

#include "CGFinterface.h"
#include "LightingScene.h"

class TPinterface: public CGFinterface {


private:
	LightingScene* lightingScene;
	int testVar;
	bool IisDown, JisDown, KisDown, LisDown;
public:
	TPinterface(LightingScene* sc);
	virtual void initGUI();
	virtual void processGUI(GLUI_Control *ctrl);
	virtual void processKeyboard(unsigned char key, int x, int y);
	void processKeyboardUp(unsigned char key, int x, int y);
	static void preprocessKeyboardUp(unsigned char key, int x, int y);


};

#endif
