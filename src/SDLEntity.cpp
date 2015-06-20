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

void SDLEntity::Visualize(a::ADisplayControl *_video){
	//cout << "SDLEntity_LoadingMedia" << "\n" << endl;
	_video->loadMedia(path,type);
	//cout << "Media Loaded" << "\n" << endl;
	_ref_w_h = _video->getSize();
	this->width = _ref_w_h[0];
	this->height = _ref_w_h[1];
}

void SDLEntity::Update(a::ADisplayControl *_video){
	//cout << "Render video" << "\n" << endl;
	_video->render(type, x, y, width, height);
}

void SDLEntity::Free(a::ADisplayControl *_video){
	_video->free(type);
}

void SDLEntity::position(int x, int y){
	this->x = x;
	this->y = y;
}
