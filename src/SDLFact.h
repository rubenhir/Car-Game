/*
 * SDKFact.h
 *
 *  Created on: 9-mrt.-2015
 *      Author: ruben
 */

#ifndef SRC_SDLFACT_H_
#define SRC_SDLFACT_H_

#include "AFact.h"
#include "ADisplayControl.h"
#include "AEventControl.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "AEntity.h"
#include <string>
#include <stdio.h>
#include "SDLEntity.h"
#include "SDLEventControl.h"
#include "SDLDisplayControl.h"

using namespace std;

class SDLFact : public a::AFact {
	public:
		SDLFact();
		virtual ~SDLFact();

		a::AEntity *getEntity(string path, int x, int y);
		a::ADisplayControl *getDisplayControl();
		a::AEventControl *getEventControl();

		bool init(int sWidth, int sHeight);

		int isReady(){
			return _success;
		}

		SDL_Renderer *getgRenderer(){
			return gRenderer;
		}

	private:
		//private success message
		int _success;

		//The window we'll be rendering to
		SDL_Window* gWindow;

		//The window renderer
		SDL_Renderer* gRenderer;
	};

#endif /* SRC_SDLFACT_H_ */

