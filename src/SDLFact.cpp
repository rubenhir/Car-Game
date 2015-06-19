/*
 * SDKFact.cpp
 *
 *  Created on: 9-mrt.-2015
 *      Author: ruben
 */

#include "SDLFact.h"
using namespace std;

SDLFact::SDLFact() {
	gRenderer = NULL;
	gWindow = NULL;
	_success = 0;
}

SDLFact::~SDLFact() {
	// TODO Auto-generated destructor stub
}


bool SDLFact::init(int sWidth, int sHeight){

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sWidth, sHeight, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}
	_success = 1;
	return success;
}

a::AEntity* SDLFact::getEntity(string path,int x,int y){
	SDLEntity* test = new SDLEntity(path, x, y);
	return test;
}

a::ADisplayControl* SDLFact::getDisplayControl(){
	SDLDisplayControl* test = new SDLDisplayControl(this);
	return test;
}


a::AEventControl* SDLFact::getEventControl(){
	SDLEventControl* test = new SDLEventControl(this);
	return test;
}


