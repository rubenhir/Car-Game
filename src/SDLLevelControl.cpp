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

}

SDLLevelControl::~SDLLevelControl() {
	// TODO Auto-generated destructor stub
}

void SDLLevelControl::setLevel(int level){
	this->level = level;
}

void SDLLevelControl::setScore(int score){
	this->score = score;
}

void SDLLevelControl::giveWarning(){
	this->warnings = this->warnings + 1;
}
