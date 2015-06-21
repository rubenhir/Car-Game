/*
 * SDLDisplayControl.cpp
 *
 *  Created on: 15-apr.-2015
 *      Author: ruben
 */

#include "SDLDisplayControl.h"

using namespace std;


SDLDisplayControl::SDLDisplayControl(SDLFact *fact) {
	//Initialize
	mTexture = NULL;
	this->sdlfact = fact;
	_dest = new SDL_Rect();
	_surface = NULL;
	_Tsurface = NULL;
	gFont = NULL;
}

SDLDisplayControl::~SDLDisplayControl() {
	//Deallocate
}

bool SDLDisplayControl::loadMedia(string path, string type){

	//string tester = "img/bg2.png";
	//printf( "testdispcontr");
	//Load image at specified path
	//cout << path << endl;
	_surface = IMG_Load( path.c_str() );
	//cout << loadedSurface << endl;

	if( _surface == NULL )
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	else{
		//Color key image
		SDL_SetColorKey( _surface, SDL_TRUE, SDL_MapRGB( _surface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(sdlfact->getgRenderer(), _surface );
		if( mTexture == NULL )
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		else{
			//Get image dimensions
			size[0] = _surface->w;
			size[1] = _surface->h;
			_textureMap[type] = mTexture;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( _surface );
	}
	//Return success
	return mTexture != NULL;
}

bool SDLDisplayControl::drawText(string textureText, int xPos, int yPos, string type){
	if( TTF_Init() == -1 )
	{
		printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
	}

	gFont = TTF_OpenFont( "fonts/OpenSans_Regular.ttf", 24 );
	SDL_Color textColor = { 0, 0, 0 };

    //Render text surface
	_Tsurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    //SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, "test", textColor );
    if( _Tsurface == NULL ){
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }else{
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(sdlfact->getgRenderer(), _Tsurface );
        if( mTexture == NULL ){
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }else{
			//Get image dimensions
			size[0] = _Tsurface->w;
			size[1] = _Tsurface->h;
			_textureMap[type] = mTexture;
        }

        //Get rid of old surface
        SDL_FreeSurface( _Tsurface );

    }

    //Return success
    return mTexture != NULL;
}

void SDLDisplayControl::free(string type)
{
	SDL_Texture* _texture = _textureMap[type];
	SDL_FreeSurface(_surface);
	SDL_FreeSurface(_Tsurface);
	SDL_DestroyTexture(_texture);
}

void SDLDisplayControl::render(string type, int x, int y, int w, int h)
{
	//cout << "Render space todo" << "\n" << endl;
	//Set rendering space and render to screen
	_dest->w = w;
	_dest->h = h;
	_dest->x = x;
	_dest->y = y;
	//cout << "Render Copy todo" << "\n" << endl;
	//Render to screen
	SDL_RenderCopy(sdlfact->getgRenderer(), _textureMap[type], NULL, _dest);
	//cout << "Render Copy done" << "\n" << endl;
}

void SDLDisplayControl::renderText(string type, int x, int y)
{
	//Render to screen
	_dest->x = x;
	_dest->y = y;
	_dest->w = size[0];
	_dest->h = size[1];
	SDL_RenderCopy(sdlfact->getgRenderer(), _textureMap[type], NULL, _dest);
	//cout << "Render Copy done" << "\n" << endl;
}



void SDLDisplayControl::clearRender(){
	SDL_RenderClear(sdlfact->getgRenderer());
}


void SDLDisplayControl::putrender()
{
	SDL_RenderPresent(sdlfact->getgRenderer());
}
