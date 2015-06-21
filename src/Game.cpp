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
		gLevelControl = aFact->newLevel();

		// (Re)Set UI
		gUIScore = NULL;
		gUITime = NULL;
		gUILevel = NULL;

		// (Re)Set Entities
		gPlayer = NULL;
		gBonus = NULL;
		for(int i=0; i<6; i++) gEnemy[i]=NULL;


		_offset = 0;

		number_of_cops = 6;
		score_to_speed = 150;
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
			userinterface();

			while(gEventControl->running()){
				//cout << "Move BG \n" << endl;

				int score = gLevelControl->getScore();
				int level = gLevelControl->getLevel();
				int warnings = gLevelControl->getWarnings();

				background(level); //moving bg!
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
				}else if(key==4){
					if(playerX>60)
						playerX -= 5;
					key = 0;
				}else key=0;

				bonusY +=2;

				gBonus->position(bonusX,bonusY);
				gPlayer->position(playerX,480);

				// Collision check if hit other car
				if(!checkCollision(playerX, playerY, 100, 40, number_of_cops, 1)){
					gLevelControl->giveWarning();
					warnings = gLevelControl->getWarnings();
					cout << "You have " << warnings << " warnings " << endl;
				}

				// for as many times i big is
				for(int i=0; i<number_of_cops; i++){
					int enemyX = gEnemy[i]->getX();
					int enemyY = gEnemy[i]->getY();

					if(enemyY > 650){
						enemyX = updateRandomEnemy(0);
						enemyY = updateRandomEnemy(1);
						//generateRandomEnemy(number_of_cops,1);

						int enemyX, enemyY;
						bool checkcol = false;

						while(!checkcol){
							// generate new
							cout << "While" << endl;
							enemyY = updateRandomEnemy(1);
							enemyX = updateRandomEnemy(0);
							checkcol = checkCollision(enemyX, enemyY, 400, 0, number_of_cops, 0);

						}


					}else enemyY += 2;
					gEnemy[i]->position(enemyX,enemyY);
				}


				/*
				for(int i=0; i<number_of_cops; i++){
					int enemyX = gEnemy[i]->getX();
					int enemyY = gEnemy[i]->getY();
					if(enemyX >= playerX-40 && enemyX < playerX+40 && enemyY >= playerY-100 && enemyY < playerY+100){cout << "Collision \n" << endl;}
					if(enemyY > 650){
						enemyX = updateRandomEnemy(0);
						enemyY = updateRandomEnemy(1);
					}
					else enemyY += 2+score/score_to_speed;
					gEnemy[i]->position(enemyX,enemyY);
				}
				 */


				// Collision check if hit thief
				if(bonusX >= playerX-40 && bonusX < playerX+40 && bonusY >= playerY-40 && bonusY < playerY+40){
					cout << "Caught Thief \n" << endl;
					score += 50;
					gLevelControl->setScore(score);

					//generateRandomEnemy(number_of_cops,1);

					int XX, YY;
					bool checkcol = false;

					while(!checkcol){
						// generate new
						cout << "While" << endl;
						YY = updateRandomEnemy(1);
						XX = updateRandomEnemy(0);
						checkcol = checkCollision(XX, YY, 400, 0, number_of_cops, 0);
					}

					gBonus->position(XX,YY);
					cout << "Score: " << gLevelControl->getScore() << endl;

					// Check score
					if(score >= 50)			gLevelControl->setLevel(level+=1);
					else if(score >= 100)	gLevelControl->setLevel(level+=1);
					else					gLevelControl->setLevel(level+=1);
				}



				//cout << "Player Positioned \n" << endl;
				//cout << _Entities.size() << endl;
				for(vector<a::AEntity*>::size_type i=0; i!=_Entities.size(); i++){
					_Entities[i]->Update(gDisplayControl);
				}

				for(vector<a::AUserInterfaceControl*>::size_type i=0; i!=_UIs.size(); i++){
					_UIs[i]->Update(gDisplayControl);
				}

				//cout << "For lus" << endl;
				gDisplayControl->putrender();
			}
		}
		else{
			//game couldnt start up!
		}
	}


	void Game::background(int level){
		//Scroll background
		//cout << "ScrollBG \n" << endl;
		int speed = 2+level*2;
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

	void Game::userinterface(){
		gUIScore = aFact->getUI("Test", 500, 0);
		//gUIScore->setText("Test", 600, 0);
		gUIScore->Visualize(gDisplayControl);
		_UIs.push_back(gUIScore);
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
		int height = updateRandomEnemy(2);
		gBonus = aFact->getEntity("bonus", lane, height);
		gBonus->MediaPath("img/th.png");
		gBonus->Visualize(gDisplayControl);
		_Entities.push_back(gBonus);

		cout << "Score: " << gLevelControl->getScore() << endl;

		for(int i=0; i<number_of_cops; i++){
			generateRandomEnemy(i);
		}
	}

	//
	void Game::generateRandomEnemy(int i){
		int lane, r1;
		bool checkcol = false;
		r1 = updateRandomEnemy(1);
		lane = updateRandomEnemy(0);

		// Check space between other cops

		// If the to spawn isn't the first
		if(i!=0) {
			// while
			while(checkcol == false){
				// generate new
				//cout << "While" << endl;
				r1 = updateRandomEnemy(1);
				lane = updateRandomEnemy(0);
				checkcol = checkCollision(lane, r1, 400, 0, i, 0);

			}
		}


		gEnemy[i] = aFact->getEntity("enemy", lane, r1);
		gEnemy[i]->MediaPath("img/car.png");
		gEnemy[i]->Visualize(gDisplayControl);
		_Entities.push_back(gEnemy[i]);
	}

	// Type = 0 Return a random lane to spawn on
	// Type = 1 Return a random height to spawn on
	// Type = 2 Return a further away random height to spawn on
	int Game::updateRandomEnemy(int type){

		if(type == 0){
			int r1 = rand() % 4 +1;
			if (r1 == 1) 		return  85;
			else if (r1 == 2) 	return 180;
			else if (r1 == 3) 	return 275;
			else			 	return 370;
		}
		else if(type == 1) 		return (rand() % 1000 - 1200);
		else					return (rand() % 2000 - 3000);
	}

	bool Game::checkCollision(int x, int y, int ypadding, int xpadding, int j, int mode){
			// for as many times i big is
			for(int i=0; i<j; i++){
				int enemyX = gEnemy[i]->getX();
				int enemyY = gEnemy[i]->getY();
				// If this other car is on the same lane
				if(enemyX >= x-xpadding && enemyX <= x+xpadding && enemyY >= y-ypadding && enemyY <= y+ypadding){
						//cout << j << " is too close to " << i << endl;
					return false;
				}//else cout << j << " is not close to " << i << endl;
			}
			//cout << j << " can be placed" << endl;
			return true;
	}
