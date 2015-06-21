/*
 * SDLUserInterfaceControl.h
 *
 *  Created on: 21 jun. 2015
 *      Author: Ruben
 */

#ifndef SRC_SDLUSERINTERFACECONTROL_H_
#define SRC_SDLUSERINTERFACECONTROL_H_

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "AUserInterfaceControl.h"
#include "ADisplayControl.h"

using namespace std;

class SDLUserInterfaceControl : public a::AUserInterfaceControl{
public:
	SDLUserInterfaceControl(string type, int x, int y);
	virtual ~SDLUserInterfaceControl();

	void setText(string text);

	void Visualize(a::ADisplayControl *text);
	void Update(a::ADisplayControl *text);
	void Free(a::ADisplayControl *text);
};



#endif /* SRC_SDLUSERINTERFACECONTROL_H_ */


