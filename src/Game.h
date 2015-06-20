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
#include <stdlib.h>
#include <time.h>

using namespace std;

#ifndef SRC_GAME_H_
#define SRC_GAME_H_


	class Game {
		protected:
			vector<a::AEntity*> _Entities;

		private:
			a::AFact* aFact;
			a::ADisplayControl *gDisplayControl;
			a::AEventControl *gEventControl;
			a::AEntity *gBG[2];
			a::AEntity *gPlayer;
			a::AEntity *gEnemy[10];
			a::AEntity *gBonus;

			void generateRandomEnemy(int i);
			int updateRandomEnemy(int type);

			int _offset;
		public:
			Game(a::AFact* a);
			~Game();
			void Start();
			void Init();
			void Close();

			void background();
			void objects();

	};


#endif /* SRC_GAME_H_ */
