/*
 * Game.cpp
 *
 *  Created on: 9-mrt.-2015
 *      Author: ruben
 */

#include "Game.h"


	Game::Game(a::AFact *a) {
		aFact = a;
		gDisplayControl = aFact->getDisplayControl();
		gEventControl = aFact->getEventControl();
		gBG[0] = NULL;
		gBG[1] = NULL;
		gPlayer = NULL;
		_offset = 0;
	}

	Game::~Game() {
		// TODO Auto-generated destructor stub
	}


	void Game::Init(){
		cout << "game Init \n" << endl;
		aFact->init(792, 600);

	}

	void Game::Start(){
		cout << "Test" << endl;
		a::AEntity *car = aFact->getEntity("car", 450, 500);
		car->Visualize(gDisplayControl);
		cout << "Start game \n" << endl;

		if(aFact->isReady()==1){

			objects();

			while(gEventControl->running()){

				gDisplayControl->free();

				//background(); //moving bg!

				gEventControl->delay();
				gEventControl->handleEvents();

				int key = gEventControl->keyselection();
				int _x = gPlayer->getX();

				if(key==6){
					if(_x<400)
						_x += 1;
					key = 0;
				}
				else if(key==4){
					if(_x>155)
						_x -= 1;
					key = 0;
				}
				else
					key=0;

				gPlayer->position(_x,480);

				for(vector<a::AEntity*>::size_type i=0; i!=_Entities.size(); i++)
					_Entities[i]->Update(gDisplayControl);
				cout << "Render" << endl;


				gDisplayControl->putrender();

			}
		}
		else{
			//game couldnt start up!
		}
	}


	void Game::background(){
		//Scroll background
		++_offset;
		if( _offset > 600)
			_offset = 0;

		//Render background
		gBG[0]->position(0,_offset);
		gBG[1]->position(0,_offset-600);
		std::cout << "Bg done \n";
	}

	void Game::objects(){
		cout << "Objects" << endl;
		gBG[0] = aFact->getEntity("background", 0, 0);
		gBG[0]->MediaPath("img/bg.png");
		gBG[0]->Visualize(gDisplayControl);
		_Entities.push_back(gBG[0]);
		cout << "Pushed back" << endl;

		//gBG[1] = aFact->getEntity("background", 0, 0);
		//gBG[1]->Visualize(gDisplayControl);
		//_Entities.push_back(gBG[1]);



		gPlayer = aFact->getEntity("player", 275, 450);
		gPlayer->MediaPath("img/car.png");
		gPlayer->Visualize(gDisplayControl);
		_Entities.push_back(gPlayer);
	}
