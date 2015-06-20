/*
 * SDLCar.h
 *
 *  Created on: 23-mrt.-2015
 *      Author: ruben
 */

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "AEntity.h"
#include "ADisplayControl.h"

using namespace std;

#ifndef SRC_SDLCAR_H_
#define SRC_SDLCAR_H_


class SDLEntity : public a::AEntity {
	public:
		SDLEntity(string type, int x, int y);
		virtual ~SDLEntity();

		void MediaPath(string path);
		int getX(){ return x;}
		int getY(){ return y;}

		void position(int x, int y);

		void Visualize(a::ADisplayControl *_video);
		void Update(a::ADisplayControl *_video);
		void Free(a::ADisplayControl *_video);

};

#endif /* SRC_SDLCAR_H_ */
