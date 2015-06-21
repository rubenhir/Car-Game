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

		int getLevel(){
			return level;
		}
		int getScore(){
			return score;
		}
		int getWarnings(){
			return warnings;
		}

		void setLevel(int level);
		void setScore(int score);
		void giveWarning();
};


#endif /* SRC_SDLLEVELCONTROL_H_ */
