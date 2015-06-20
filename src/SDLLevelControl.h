/*
 * SDLLevelControl.h
 *
 *  Created on: 20 jun. 2015
 *      Author: Ruben
 */

#ifndef SRC_SDLLEVELCONTROL_H_
#define SRC_SDLLEVELCONTROL_H_

#include "SDLFact.h"
#include "ALevelControl.h"
#include <SDL2/SDL.h>

using namespace std;

class SDLLevelControl : public a::ALevelControl  {
	public:
		SDLLevelControl();
		virtual ~SDLLevelControl();

		//Clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets time
		int get_ticks();
		double get_sec();

		//Checks the status
		bool is_started();
		bool is_paused();
};


#endif /* SRC_SDLLEVELCONTROL_H_ */
