#include "Game.h"


Game::Game(SDL_Renderer* renderer,b2World* bworld) : mRenderer(renderer), mWorld(bworld){
	player = new Entity(b2Vec2(100, 100), b2Vec2(50, 50), mRenderer, mWorld);
	view = new Entity(b2Vec2(400, 400), b2Vec2(100, 100), mRenderer, mWorld);
	enemy = new Entity(b2Vec2(600, 400), b2Vec2(50, 50), mRenderer, mWorld);
	hidingSpot = new Entity(b2Vec2(600, 600), b2Vec2(50, 50), mRenderer, mWorld);
}


Game::~Game(void){}

void Game::update(double deltaTime){	
	float32 timeStep = deltaTime;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	
	mWorld->Step(timeStep, velocityIterations, positionIterations);	

	SDL_RenderClear( mRenderer );
	//draw stuff
	player->Update();
	
	if (true == view->Collision(player) ||true == enemy->playerDetected )
	{
		enemy->SetDirection(player->mPos);
		enemy->playerDetected = true;
	}
	if (true == hidingSpot->Collision(player))
	{
		enemy->playerDetected = false;
	}
	enemy->UpdateEnemy(view);
	player->Draw();
	view->Draw();
	enemy->Draw();
	hidingSpot->Draw();
	SDL_RenderPresent( mRenderer );
}
