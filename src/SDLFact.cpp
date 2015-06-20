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
	_success = false;
	//cout << "SDL start\n" << endl; //sec hoort gij mij nee :D
}

SDLFact::~SDLFact() {
	// TODO Auto-generated destructor stub
}


bool SDLFact::init(int sWidth, int sHeight){
	//cout << "SDL init \n" << endl;
	//Initialization flag
	_success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		//cout << "SDL could not initialize! SDL Error: ";
		//cout << SDL_GetError() << endl;
		_success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			//cout << "Warning: Linear texture filtering not enabled!" << endl;
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sWidth, sHeight, SDL_WINDOW_SHOWN );
		//cout << "SDL create window \n" << endl;
		if( gWindow == NULL )
		{
			//cout << "Window could not be created! SDL Error: ";
			//cout << SDL_GetError() << endl;
			_success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			//cout << "SDL create renderer \n" << endl;
			if( gRenderer == NULL )
			{
				//cout << "Renderer could not be created! SDL Error: ";
				//cout << SDL_GetError() << endl;
				_success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				//cout << "SDL set render draw color \n" << endl;

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				//cout << "IMG flags \n" << endl;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					//cout << "SDL_image could not initialize! SDL_image Error: ";
					//cout << IMG_GetError() << endl;
					_success = false;
				}
			}
		}
	}
	//if(_success == true) cout << "True" << endl;

	return _success;
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


a::ALevelControl* SDLFact::getLevel(){
	SDLLevelControl *_timer = new SDLLevelControl();
	return _timer;
}
