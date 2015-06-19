/*
 * SDLCar.cpp
 *
 *  Created on: 23-mrt.-2015
 *      Author: ruben
 */

#include <iostream>

#include "SDLEntity.h"
using namespace std;


SDLEntity::SDLEntity(string path,int x, int y) {
	// TODO Auto-generated constructor stub
	cout << "test" << "\n";
	this->x = x;
	this->y = y;
	this->path = path;
}

SDLEntity::~SDLEntity() {
	// TODO Auto-generated destructor stub
}



void SDLEntity::MediaPath(std::string path){

}

void SDLEntity::Visualize(a::ADisplayControl *_video){

}

void SDLEntity::Update(a::ADisplayControl *_video){

}

void SDLEntity::Free(a::ADisplayControl *_video){

}

void SDLEntity::position(int x, int y){

}
