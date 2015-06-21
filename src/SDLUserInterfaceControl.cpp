/*
 * SDLUserInterfaceControl.cpp
 *
 *  Created on: 21 jun. 2015
 *      Author: Ruben
 */

#include "SDLUserInterfaceControl.h"

using namespace std;

SDLUserInterfaceControl::SDLUserInterfaceControl(string text, int x, int y) {
	// TODO Auto-generated constructor stub
	this->text = text;
	this->x = x;
	this->y = y;
}

SDLUserInterfaceControl::~SDLUserInterfaceControl() {
	// TODO Auto-generated destructor stub
}

void SDLUserInterfaceControl::setText(string text, int x, int y){
	this->text = text;
	this->x = x;
	this->y = y;
}

void SDLUserInterfaceControl::Visualize(a::ADisplayControl *_text){
	//cout << "SDLEntity_LoadingMedia" << "\n" << endl;
	_text->drawText(text, x, y);

}

void SDLUserInterfaceControl::Update(a::ADisplayControl *_text){
	//cout << "Render video" << "\n" << endl;
	_text->renderText(text, x, y);
}

void SDLUserInterfaceControl::Free(a::ADisplayControl *_text){
	//_text->free();
}
