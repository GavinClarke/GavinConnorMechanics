#pragma once
#include "Box2D\Box2D.h"
#include <stddef.h>
#include "SDL.h"
using namespace std;
class KeyboardManager
{
private:
	static KeyboardManager* me;

public:
	static KeyboardManager* getKeys();
	static bool Key_Left;
	static bool Key_Right;
	static bool Key_Up;
	static bool Key_Space;
	static bool Key_Down;
	static bool Key_S;
	static bool Key_Q;
	static bool Key_R;
	static bool leftMouseDown;
	static bool KeyboardManager::QUIT;
	static bool canShootBullet;
	void Update(SDL_Event eHandler);
	KeyboardManager(void);
	~KeyboardManager(void);
	b2Vec2 mouseClickPos;
};

