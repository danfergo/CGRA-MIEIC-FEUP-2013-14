/* 
 * G0_Base: projeto inicial de CGra
 * 
 */

#include <iostream>
#include <exception>

#include "TPinterface.h"
#include "CGFapplication.h"
#include "LightingScene.h"

using std::cout;
using std::exception;


int main(int argc, char* argv[]) {

	CGFapplication app = CGFapplication();
	LightingScene * scene = new LightingScene();
	try {
		app.init(&argc, argv);
		app.setScene(scene);
		app.setInterface(new TPinterface(scene));
		app.run();
	}
	catch(GLexception& ex) {
		cout << "Erro: " << ex.what();
		return -1;
	}
	catch(exception& ex) {
		cout << "Erro inesperado: " << ex.what();
		return -1;
	}

	return 0;
}