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

			void handleEvents();
			void setDelayTime(double time);
			void delay();
			bool running() { return _running; }
			bool pauzing() { return _pauzing; }
			int keyselection() { return _key; }

		private:
			SDLFact *_fact;
			SDL_Event *_event;
		};

#endif /* SRC_SDLEVENTCONTROL_H_ */
