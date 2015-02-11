#include "Entity.h"


Entity::Entity(b2Vec2 pos, b2Vec2 size, SDL_Renderer* renderer, b2World* world)
	: mPos(pos), mSize(size), mRenderer(renderer), mWorld(world)
{
	b2BodyDef bodyDef;
	bodyDef.position = mPos;//+b2Vec2(mSize.x/2,mSize.y/2);
	//bodyDef.fixedRotation = true;
	mBody = world->CreateBody(&bodyDef);

	b2BodyDef BodyDef;
	BodyDef.type = b2_dynamicBody;
	BodyDef.position = mPos;
	//BodyDef.fixedRotation = true;


	b2Body* body = world->CreateBody(&BodyDef);
	b2PolygonShape Box;
	//sets box with position centered and given width and height in each direction(hence /2)

	Box.SetAsBox(mSize.x, mSize.y);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &Box;
	mBody->CreateFixture(&fixtureDef);
	mSprite = SDL_CreateTextureFromSurface(mRenderer, IMG_Load("C:\\Users\\Gavin\\Desktop\\G4JP_15_C\\G4JP_15_C\\images\\block.png"));
	stretchRect = new SDL_Rect();
	stretchRect->x = mPos.x;//mBody->GetPosition().x;
	stretchRect->y = mPos.y;//mBody->GetPosition().y;
	stretchRect->w = mSize.x;
	stretchRect->h = mSize.y;
	direction = b2Vec2(0, 0);
	originalPos = mPos;
}


Entity::~Entity(void){}

void Entity::Update()
{

	if (true == KeyboardManager::getKeys()->Key_Up)
	{
		mPos.y -= 0.1;
	}
	if (true == KeyboardManager::getKeys()->Key_Down)
	{
		mPos.y += 0.1;
	}
	if (true == KeyboardManager::getKeys()->Key_Left)
	{
		mPos.x -= 0.1;
	}
	if (true == KeyboardManager::getKeys()->Key_Right)
	{
		mPos.x += 0.1;
	}

}
/*void SetDirection(Entity * ent);
	void UpdateEnemy();*/

void Entity::SetDirection(b2Vec2 ent)
{
	direction = (ent - mPos);
	direction.Normalize();
}

void Entity::UpdateEnemy(Entity * v)
{
	if (false == playerDetected &&
		(int)mPos.x != (int)originalPos.x &&
		(int)mPos.y != (int)originalPos.y)
	{
		SetDirection(originalPos);
	}
	if (playerDetected || (!playerDetected && (int)mPos.x != (int)originalPos.x &&
		(int)mPos.y != (int)originalPos.y)){
		mPos.x += direction.x / 100;
		mPos.y += direction.y / 100;
	}
	else if (!playerDetected && (int)mPos.x == (int)originalPos.x &&
		(int)mPos.y == (int)originalPos.y){//
		
	}
	CheckViewPos(v);
}

void Entity::CheckViewPos(Entity * v)
{
	v->mPos.y = (direction.y*100) + (mPos.y - (mSize.y * 0.5f));
	v->mPos.x = (direction.x*100) + (mPos.x - (mSize.x * 0.5f));
}

bool Entity::Collision(Entity * ent)
{
	bool caught = false;
	SDL_Rect * PlayerRect = ent->stretchRect;
	SDL_Rect * ViewRect = stretchRect;

	if (PlayerRect->x + PlayerRect->w > ViewRect->x &&
		PlayerRect->x < ViewRect->x + ViewRect->w &&
		PlayerRect->y + PlayerRect->h > ViewRect->y &&
		PlayerRect->y < ViewRect->y + ViewRect->h)
	{
		return true;
	}
	
	return false;
}

void Entity::Draw(){

	//SDL_Rect stretchRect;
	stretchRect->x = mPos.x;//mBody->GetPosition().x;
	stretchRect->y = mPos.y;//mBody->GetPosition().y;
	stretchRect->w = mSize.x;
	stretchRect->h = mSize.y;

	SDL_RenderCopy ( mRenderer, mSprite, NULL, stretchRect); 
}

void Entity::Draw(int angle)
{

	stretchRect->x = mPos.x;//mBody->GetPosition().x;
	stretchRect->y = mPos.y;//mBody->GetPosition().y;
	stretchRect->w = mSize.x;
	stretchRect->h = mSize.y;

	SDL_RenderCopyEx(mRenderer, mSprite, NULL, stretchRect, angle, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
}


b2Vec2 Entity::getSize()
{
	return mSize;
}
