#include <iostream>
#include "SDLFact.h"
#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[]){

	Game* testgame = new Game(new SDLFact());
	testgame->Init();
	testgame->Start();

	return 0;
}

