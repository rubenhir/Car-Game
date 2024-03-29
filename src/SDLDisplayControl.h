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
#include <SDL2/SDL_ttf.h>
#include <string>
#include <stdio.h>
#include <map>


using namespace std;

class SDLFact;
class SDLDisplayControl : public a::ADisplayControl  {
public:
	//Initializes variables
	SDLDisplayControl(SDLFact *fact);

	//Deallocates memory
	~SDLDisplayControl();
	void putrender();
	void clearRender();

	//Loads image at specified path
	bool loadMedia(string path, string type);

	//Loads text at specified path
	bool drawText(std::string textureText, int x, int y, string type);
	void renderText(std::string type, int x, int y);

	//Deallocates texture
	void free(string type);

	//Renders texture at given point
	void render(string type, int x, int y, int w, int h);

	//Gets image dimensions
	int *getSize(){ return size; }

protected:
	map <std::string, SDL_Texture*> _textureMap;

private:
	//The actual hardware texture
	SDL_Texture *mTexture;
	SDL_Surface *_surface;
	SDL_Surface *_Tsurface;
	SDL_Rect *_dest;
	TTF_Font *gFont;

	SDLFact *sdlfact;



};


#endif /* SRC_SDLDISPLAYCONTROL_H_ */
