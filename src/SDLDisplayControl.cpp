/*
 * SDLDisplayControl.cpp
 *
 *  Created on: 15-apr.-2015
 *      Author: ruben
 */

#include "SDLDisplayControl.h"

using namespace std;


SDLDisplayControl::SDLDisplayControl(SDLFact *fact) {
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	type = "";
	this->sdlfact = fact;
	_dest = NULL;
	_surface = NULL;
}

SDLDisplayControl::~SDLDisplayControl() {
	//Deallocate
	free();
}

bool SDLDisplayControl::loadMedia(string path, string type){

	printf( "testdispcontr");
	this->type = type;
	//Load image at specified path
	cout << path << endl;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	cout << loadedSurface << endl;
	if( loadedSurface == NULL )
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	else{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(sdlfact->getgRenderer(), loadedSurface );
		if( mTexture == NULL )
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		else{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	//Return success
	return mTexture != NULL;
}

void SDLDisplayControl::free()
{
	SDL_DestroyTexture( mTexture );
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	type = "";
	_dest = NULL;
}

void SDLDisplayControl::render(int x, int y)
{
	//Set rendering space and render to screen
	_dest->w = mWidth;
	_dest->h = mHeight;
	_dest->x = x;
	_dest->y = y;

	//Render to screen
	SDL_RenderCopy(sdlfact->getgRenderer(), mTexture, NULL, _dest);
}

int SDLDisplayControl::getWidth()
{
	return mWidth;
}

int SDLDisplayControl::getHeight()
{
	return mHeight;
}

void SDLDisplayControl::putrender()
{
	SDL_RenderPresent(sdlfact->getgRenderer());
}
