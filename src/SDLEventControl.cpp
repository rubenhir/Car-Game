/*
 * SDLEventControl.cpp
 *
 *  Created on: 4-mei-2015
 *      Author: ruben
 */

#include "SDLEventControl.h"

using namespace std;

SDLEventControl::SDLEventControl(SDLFact *_fact) {
	_running = true;
	_time = 10;
	_event = new SDL_Event();
	this->_fact = _fact;

}

SDLEventControl::~SDLEventControl() {
	// TODO Auto-generated destructor stub
}



void SDLEventControl::handleEvents(){
	if(SDL_PollEvent(_event))
	{
		switch (_event->type){
			case SDL_QUIT:
				_running = false;
				break;
			case SDL_KEYUP:
				_key = 0;
				break;

			case SDL_KEYDOWN:
				switch( _event->key.keysym.sym ){
					case SDLK_LEFT:
						_key=4;
						std::cout<<"Links"<<std::endl;
						break;
					case SDLK_RIGHT:
						_key=6;
						std::cout<<"Rechts"<<std::endl;
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
}
void SDLEventControl::setDelayTime(double time){

}
void SDLEventControl::delay(){

}
