/*
 * SDLEventControl.cpp
 *
 *  Created on: 4-mei-2015
 *      Author: ruben
 */

#include "SDLEventControl.h"

using namespace std;

SDLEventControl::SDLEventControl(SDLFact *_fact) {
	_playing = true;
	_sec = 15;
	/**
	 *  \brief General event structure
	 */
	gEvent = new SDL_Event();
	this->_fact = _fact;

}

SDLEventControl::~SDLEventControl() {
	// TODO Auto-generated destructor stub
}

void SDLEventControl::delay(){
	//brief Wait a specified number of milliseconds before returning.
	SDL_Delay(_sec);
}

void SDLEventControl::handleEvents(){
	//cout << "Handle Events \n" << endl;

	/**
	 *  \brief Polls for currently pending events.
	 *
	 *  \return 1 if there are any pending events, or 0 if there are none available.
	 *
	 *  \param event If not NULL, the next event is removed from the queue and
	 *               stored in that area.
	 */
	if(SDL_PollEvent(gEvent))
	{
		switch (gEvent->type){
		 	/**< User-requested quit */
			case SDL_QUIT:
				_playing = false;
				break;
				/**< Key released */
			case SDL_KEYUP:
				_key = 0;
				break;
			/**< Key pressed */
			case SDL_KEYDOWN:
				switch( gEvent->key.keysym.sym ){
					/**< Left Key pressed */
					case SDLK_LEFT:
						_key=4;
						std::cout<<"left"<<std::endl;
						break;
					/**< Right Key pressed */
					case SDLK_RIGHT:
						_key=6;
						std::cout<<"right"<<std::endl;
						break;
					/**< Space Key pressed */
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


