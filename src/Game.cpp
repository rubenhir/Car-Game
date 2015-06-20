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
		gBonus = NULL;
		for(int i=0; i<6; i++) gEnemy[i]=NULL;
		_offset = 0;
	}

	Game::~Game() {
		// TODO Auto-generated destructor stub
	}


	void Game::Init(){
		//cout << "game Init \n" << endl;
		aFact->init(792, 600);

	}

	void Game::Start(){
		//cout << "Start game \n" << endl;
		srand (time(NULL));
		if(aFact->isReady()==1){

			objects();

			while(gEventControl->running()){

				//cout << "Move BG \n" << endl;

				background(); //moving bg!
				//cout << "Moved BG \n" << endl;

				//cout << "Event Control \n" << endl;
				gEventControl->delay();
				//cout << "Event Control Delayed \n" << endl;
				gEventControl->handleEvents();
				//cout << "Event Control Handled Events \n" << endl;

				int key = gEventControl->keyselection();
				//cout << "Event Control Key selected \n" << endl;
				int playerX = gPlayer->getX();
				int playerY = gPlayer->getY();

				int bonusY = gBonus->getY();
				int bonusX = gBonus->getX();
				//cout << "Player Got X \n" << endl;


				if(key==6){
					if(playerX<400)
						playerX += 5;
					key = 0;
				}
				else if(key==4){
					if(playerX>60)
						playerX -= 5;
					key = 0;
				}
				else
					key=0;
				bonusY +=2;
				gBonus->position(bonusX,bonusY);

				gPlayer->position(playerX,480);

				for(int i=0; i<6; i++){
					int enemyX = gEnemy[i]->getX();
					int enemyY = gEnemy[i]->getY();
					if(enemyX >= playerX-40 && enemyX < playerX+40 && enemyY >= playerY-100 && enemyY < playerY+100){cout << "Collision \n" << endl;}
					if(enemyY > 650){
						enemyX = updateRandomEnemy(0);
						enemyY = updateRandomEnemy(1);
					}
					else enemyY += 2;
					gEnemy[i]->position(enemyX,enemyY);
				}



				//cout << "Player Positioned \n" << endl;
				//cout << _Entities.size() << endl;
				for(vector<a::AEntity*>::size_type i=0; i!=_Entities.size(); i++){
					_Entities[i]->Update(gDisplayControl);
				}
				//cout << "For lus" << endl;


				gDisplayControl->putrender();

			}
		}
		else{
			//game couldnt start up!
		}
	}


	void Game::background(){
		//Scroll background
		//cout << "ScrollBG \n" << endl;
		int speed = 3;
		_offset = _offset + speed;
		if( _offset > 600)
			_offset = 0;
		//cout << "End IF \n" << endl;
		//Render background
		gBG[0]->position(0,_offset);
		//cout << "BGPos 0 \n" << endl;
		gBG[1]->position(0,_offset-600);
		//cout << "BGPos1 \n" << endl;
		//cout << "Bg done \n" << endl;
	}

	void Game::objects(){
		//cout << "Objects" << endl;
		gBG[0] = aFact->getEntity("background", 0, 0);
		//cout << "background entity" << endl;
		gBG[0]->MediaPath("img/bg2.png");
		//cout << "MediaPath loaded" << endl;
		gBG[0]->Visualize(gDisplayControl);
		_Entities.push_back(gBG[0]);
		//cout << "Pushed back" << endl;

		gBG[1] = aFact->getEntity("background", 0, 0);
		gBG[1]->Visualize(gDisplayControl);
		_Entities.push_back(gBG[1]);

		gPlayer = aFact->getEntity("player", 275, 450);
		gPlayer->MediaPath("img/car.png");
		gPlayer->Visualize(gDisplayControl);
		_Entities.push_back(gPlayer);

		int lane = updateRandomEnemy(0);
		int height = updateRandomEnemy(1);
		gBonus = aFact->getEntity("bonus", lane, height);
		gBonus->MediaPath("img/th.png");
		gBonus->Visualize(gDisplayControl);
		_Entities.push_back(gBonus);

		for(int i=0; i<6; i++){
			generateRandomEnemy(i);
		}
	}

	void Game::generateRandomEnemy(int i){
		int lane, r1,r2;
		r1 = rand() % 4 +1;
		//cout << r1 << endl;
		r2 = rand() % 500 - 800;
		if (r1 == 1) lane = 85;
		else if (r1 == 2) lane = 180;
		else if (r1 == 3) lane = 275;
		else if (r1 == 4) lane = 370;
		gEnemy[i] = aFact->getEntity("enemy", lane, r2);
		gEnemy[i]->MediaPath("img/car.png");
		gEnemy[i]->Visualize(gDisplayControl);
		_Entities.push_back(gEnemy[i]);
	}

	int Game::updateRandomEnemy(int type){
		if(type == 0){
			int lane;
			int r1 = rand() % 4 +1;
			if (r1 == 1) lane = 85;
			else if (r1 == 2) lane = 180;
			else if (r1 == 3) lane = 275;
			else if (r1 == 4) lane = 370;
			return lane;
		}else{
			int r2 = rand() % 500 - 800;
			return r2;
		}


	}
