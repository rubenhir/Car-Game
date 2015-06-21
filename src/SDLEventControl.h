/*
 * SDLEventControl.h
 *
 *  Created on: 4-mei-2015
 *      Author: ruben
 */

#ifndef SRC_SDLEVENTCONTROL_H_
#define SRC_SDLEVENTCONTROL_H_

#include "SDLFact.h"
#include "AEventControl.h"

using namespace std;

class SDLFact;
	class SDLEventControl  : public a::AEventControl {
		public:
			SDLEventControl(SDLFact *_fact);
			~SDLEventControl();

			// Events (key pressed)
			void handleEvents();
			// brief Wait a specified number of milliseconds before returning.
			void delay();
			// Check if player didn't Quit
			bool playing() { return _playing; }
			int kSelect() { return _key; }

		private:
			SDL_Event *gEvent;
			SDLFact *_fact;
		};

#endif /* SRC_SDLEVENTCONTROL_H_ */
