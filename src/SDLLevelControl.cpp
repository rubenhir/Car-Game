/*
 * SDLLevelControl.cpp
 *
 *  Created on: 20 jun. 2015
 *      Author: Ruben
 */

#include "SDLLevelControl.h"

using namespace std;

SDLLevelControl::SDLLevelControl() {
	// TODO Auto-generated constructor stub
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;

}

SDLLevelControl::~SDLLevelControl() {
	// TODO Auto-generated destructor stub
}



void SDLLevelControl::start(){
	started = true;
	paused = false;
	startTicks = SDL_GetTicks();
}

void SDLLevelControl::stop(){
	started = false;
	paused = false;
}

void SDLLevelControl::pause(){
	if( ( started == true ) && ( paused == false ) ){
		paused = true;
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void SDLLevelControl::unpause(){
	if( paused == true ){
		paused = false;
		startTicks = SDL_GetTicks() - pausedTicks;
		pausedTicks = 0;
	}
}

int SDLLevelControl::get_ticks(){
	if( started == true )
	{
		if( paused == true )
			return pausedTicks;
		else
			return SDL_GetTicks() - startTicks;
	}
	return 0;
}

double SDLLevelControl::get_sec(){
	if( started == true )
	{
		if( paused == true )
			return pausedTicks;
		else
			return (SDL_GetTicks() - startTicks)/1000;
	}
	return 0;
}


bool SDLLevelControl::is_started(){
	return started;
}

bool SDLLevelControl::is_paused(){
	return paused;
}
