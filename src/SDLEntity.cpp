/*
 * SDLCar.cpp
 *
 *  Created on: 23-mrt.-2015
 *      Author: ruben
 */

#include <iostream>

#include "SDLEntity.h"
using namespace std;


SDLEntity::SDLEntity(string type, int x, int y) {
	// TODO Auto-generated constructor stub
	cout << "test" << "\n" << endl;
	this->type = type;
	this->x = x;
	this->y = y;
}

SDLEntity::~SDLEntity() {
	// TODO Auto-generated destructor stub
}


void SDLEntity::MediaPath(string path){
	this->path = path;
}

void SDLEntity::Visualize(a::ADisplayControl *_video){
	_video->loadMedia(path,type);
	this->width = _video->getHeight();
	this->height = _video->getWidth();
}

void SDLEntity::Update(a::ADisplayControl *_video){
	_video->render(x,y);
}

void SDLEntity::Free(a::ADisplayControl *_video){
	_video->free();
}

void SDLEntity::position(int x, int y){
	this->x = x;
	this->y = y;
}
