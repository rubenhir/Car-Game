/*
 * SDLDisplayControl.h
 *
 *  Created on: 15-apr.-2015
 *      Author: ruben
 */

#ifndef SRC_SDLDISPLAYCONTROL_H_
#define SRC_SDLDISPLAYCONTROL_H_

#include "SDLFact.h"
#include "ADisplayControl.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <stdio.h>


using namespace std;

class SDLFact;
class SDLDisplayControl : public a::ADisplayControl  {
public:
	//Initializes variables
	SDLDisplayControl(SDLFact *fact);

	//Deallocates memory
	~SDLDisplayControl();
	void putrender();

	//Loads image at specified path
	bool loadMedia(string path);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture *mTexture;
	SDLFact *sdlfact;

	//Image dimensions
	int mWidth;
	int mHeight;
};


#endif /* SRC_SDLDISPLAYCONTROL_H_ */
