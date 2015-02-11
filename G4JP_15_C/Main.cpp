#include <iostream>
#include <SDL.h>
#include "Box2D\Box2D.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <ctime>
#include <SDL_mixer.h>
#include "Game.h"
#include "KeyboardManager.h"
//Screen dimension constants 
const int SCREEN_WIDTH = 1280; 
const int SCREEN_HEIGHT = 720;
//The window we'll be rendering to 
SDL_Window* window = NULL; 
SDL_Renderer* renderer = NULL; 

SDL_Event eHandler;
Game* game;
void gameLoop();
int main(int argc, char **argv){
	bool QUIT = true;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	//Initialize SDL
	if( SDL_Init( SDL_INIT_AUDIO ) < 0 ){
		std::cout <<( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	}
	//Initialize SDL_mixer
	//if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
		//std::cout <<( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
	//}

	window = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); 
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED ); 
	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF ); 

	//Initialize PNG loading 
	if(!( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG )){ 		
		std::cout <<( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
	} 
	TTF_Init();

	
	

	b2Vec2 gravity =  b2Vec2(0.0f,4.981f);
	bool doSleep = true;
	b2World* world = new b2World(gravity);
	/*world->SetContactListener(CollisionListener::getListener());
	CollisionListener::getListener()->setWorld(world);*/
	game = new Game(renderer,world);

	double mClock = SDL_GetTicks();
	while(QUIT){
		KeyboardManager::getKeys()->Update(eHandler);
		double deltaTime = SDL_GetTicks() - mClock;
		game->update(deltaTime/1000.0f);
		mClock += deltaTime;
	}
	SDL_Quit();

	return 0;
}