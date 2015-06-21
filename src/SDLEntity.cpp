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
	//cout << "test" << "\n" << endl;
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

void SDLEntity::Visualize(a::ADisplayControl *_display){
	//cout << "SDLEntity_LoadingMedia" << "\n" << endl;
	_display->loadMedia(path,type);
	//cout << "Media Loaded" << "\n" << endl;
	pointerWH = _display->getSize();
	this->width = pointerWH[0];
	this->height = pointerWH[1];
}

void SDLEntity::Update(a::ADisplayControl *_display){
	//cout << "Render video" << "\n" << endl;
	_display->render(type, x, y, width, height);
}

void SDLEntity::Free(a::ADisplayControl *_display){
	_display->free(type);
}

void SDLEntity::position(int x, int y){
	this->x = x;
	this->y = y;
}
