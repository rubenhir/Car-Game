/*
 * Game.h
 *
 *  Created on: 9-mrt.-2015
 *      Author: ruben
 */

#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "AFact.h"
#include "ADisplayControl.h"
#include "AEventControl.h"
#include "AEntity.h"
#include "AUserInterfaceControl.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

#ifndef SRC_GAME_H_
#define SRC_GAME_H_


	class Game {
		protected:
			vector<a::AEntity*> _Entities;
			vector<a::AUserInterfaceControl*> _UIs;

		private:
			a::AFact* aFact;
			a::ADisplayControl *gDisplayControl;
			a::AEventControl *gEventControl;
			a::ALevelControl *gLevelControl;
			a::AEntity *gBG[2];
			a::AEntity *gPlayer;
			a::AEntity *gEnemy[10];
			a::AEntity *gBonus;
			a::AUserInterfaceControl *gUIScore;
			a::AUserInterfaceControl *gUITime;
			a::AUserInterfaceControl *gUILevel;

			void generateRandomEnemy(int i);
			int updateRandomEnemy(int type);
			bool checkCollision(int x, int y, int ypadding, int xpadding, int j, int mode);

			int _offset, score_to_speed,number_of_cops;

		public:
			Game(a::AFact* a);
			~Game();
			void Start();
			void Init();
			void Close();

			void background(int level);
			void objects();
			void userinterface();

	};


#endif /* SRC_GAME_H_ */
