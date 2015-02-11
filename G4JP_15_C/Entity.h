#pragma once
#include "Box2D\Box2D.h"
#include <SDL_image.h>
#include <stdlib.h>     
#include <time.h>  
#include "KeyboardManager.h"

class Entity
{
private:	
	
	b2Vec2 mSize;
	SDL_Renderer* mRenderer;
	b2World* mWorld;
	b2Body* mBody;
	//SDL_Rect * viewRect;
	SDL_Texture* mTexture;
	b2Vec2 direction;
public:
	b2Vec2 originalPos;
	bool playerDetected;
	b2Vec2 mPos;
	SDL_Rect * stretchRect;
	SDL_Texture* mSprite;
	Entity(b2Vec2 pos, b2Vec2 size, SDL_Renderer* renderer, b2World* world);
	~Entity(void);
	//

	bool Collision(Entity * ent);
	void CheckViewPos(Entity * v);
	void Update();
	void SetDirection(b2Vec2 ent);
	void UpdateEnemy(Entity * v);
	void Draw();
	void Draw(int angle);
	void Reaction(Entity * wall);
	static Entity* CreateWall(b2Vec2 pos, b2Vec2 size, SDL_Renderer* renderer, b2World* world);
	b2Vec2 getSize();
};

