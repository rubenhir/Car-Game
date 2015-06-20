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
		a::AEntity *car = aFact->getEntity("car", 450, 500);
		car->Visualize(gDisplayControl);
		cout << "Start game \n" << endl;

		if(aFact->isReady()==1){

			objects();

			while(gEventControl->running()){

				cout << "Move BG \n" << endl;

				background(); //moving bg!
				cout << "Moved BG \n" << endl;

				cout << "Event Control \n" << endl;
				gEventControl->delay();
				cout << "Event Control Delayed \n" << endl;
				gEventControl->handleEvents();
				cout << "Event Control Handled Events \n" << endl;

				int key = gEventControl->keyselection();
				cout << "Event Control Key selected \n" << endl;
				int _x = gPlayer->getX();
				cout << "Player Got X \n" << endl;

				/*
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
				*/

				gPlayer->position(_x,480);
				cout << "Player Positioned \n" << endl;
				cout << _Entities.size() << endl;
				for(vector<a::AEntity*>::size_type i=0; i!=_Entities.size(); i++){
					cout << "For lus" << endl;
					_Entities[i]->Update(gDisplayControl);

				}
				cout << "For lus" << endl;


				gDisplayControl->putrender();

			}
		}
		else{
			//game couldnt start up!
		}
	}


	void Game::background(){
		//Scroll background
		cout << "ScrollBG \n" << endl;
		++_offset;
		if( _offset > 600)
			_offset = 0;
		cout << "End IF \n" << endl;
		//Render background
		gBG[0]->position(0,_offset);
		cout << "BGPos 0 \n" << endl;
		gBG[1]->position(0,_offset-600);
		cout << "BGPos1 \n" << endl;
		cout << "Bg done \n" << endl;
	}

	void Game::objects(){
		cout << "Objects" << endl;
		gBG[0] = aFact->getEntity("background", 0, 0);
		cout << "background entity" << endl;
		gBG[0]->MediaPath("img/bg2.png");
		cout << "MediaPath loaded" << endl;
		gBG[0]->Visualize(gDisplayControl);
		_Entities.push_back(gBG[0]);
		cout << "Pushed back" << endl;

		gBG[1] = aFact->getEntity("background", 0, 0);
		gBG[1]->Visualize(gDisplayControl);
		_Entities.push_back(gBG[1]);

		gPlayer = aFact->getEntity("player", 275, 450);
		gPlayer->MediaPath("img/car.png");
		gPlayer->Visualize(gDisplayControl);
		_Entities.push_back(gPlayer);
	}
