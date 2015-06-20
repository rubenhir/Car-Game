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
	//cout << "Handle Events \n" << endl;
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
						std::cout<<"left"<<std::endl;
						break;
					case SDLK_RIGHT:
						_key=6;
						std::cout<<"right"<<std::endl;
						break;
					case SDLK_UP:
						_key=8;
						if(_time > 0)
							_time -= 1;
						std::cout<<"up"<<std::endl;
						break;
					case SDLK_DOWN:
						_key=2;
						if(_time < 20)
							_time += 1;
						std::cout<<"down"<<std::endl;
						break;
					case SDLK_SPACE:
						_pauzing=true;
						std::cout<<"space"<<std::endl;
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
	_time = time;
}
void SDLEventControl::delay(){
	SDL_Delay(_time);
}
