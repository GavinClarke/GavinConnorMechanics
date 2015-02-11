#include "KeyboardManager.h"


KeyboardManager* KeyboardManager::me;
bool KeyboardManager::Key_Left;
bool KeyboardManager::Key_Right;
bool KeyboardManager::Key_Up;
bool KeyboardManager::Key_Space;
bool KeyboardManager::Key_Down;
bool KeyboardManager::Key_S;
bool KeyboardManager::Key_R;
bool KeyboardManager::Key_Q;
bool KeyboardManager::QUIT;
bool KeyboardManager::leftMouseDown;
bool KeyboardManager::canShootBullet;

KeyboardManager* KeyboardManager::getKeys()
{
	if(me==NULL)
	{
		me=new KeyboardManager();
		Key_Left=false;
		Key_Right=false;
		Key_Up=false;
		Key_Space=false;
		Key_Down=false;
		Key_S=false;
		Key_Q=false;
		Key_R=false;
		QUIT=false;
		leftMouseDown = false;
		canShootBullet = false;
	}
	return me;
}

KeyboardManager::KeyboardManager(void)
{
}


KeyboardManager::~KeyboardManager(void)
{
}

void KeyboardManager::Update(SDL_Event eHandler)
{
	while( SDL_PollEvent( &eHandler ) != 0 ) 
	{ 
		if(eHandler.type == SDL_MOUSEBUTTONDOWN){
			leftMouseDown=true;
		}
		else if(eHandler.type == SDL_MOUSEBUTTONUP && leftMouseDown){
			canShootBullet = true;			
			mouseClickPos.x = eHandler.button.x;
			mouseClickPos.y = eHandler.button.y;
			leftMouseDown=false;
		}
		else{
			canShootBullet=false;
		}
		if( eHandler.type == SDL_QUIT ){ 
			QUIT = true; 
		} 
		else if( eHandler.type == SDL_KEYDOWN )
		{ 
			switch( eHandler.key.keysym.sym )
			{
			case SDLK_ESCAPE: 
				QUIT = true;
				break; 
			case SDLK_UP:
				Key_Up=true;
				break; 
			case SDLK_DOWN:
				Key_Down=true;
				break; 
			case SDLK_LEFT:
				Key_Left=true;
				break; 
			case SDLK_RIGHT:
				Key_Right=true;
				break; 
			case SDLK_SPACE:
				Key_Space=true;
				break; 
			case SDLK_s:
				Key_S=true;
				break;
			case SDLK_q:
				Key_Q=true;
				break; 
			case SDLK_r:
				Key_R=true;
				break;
			default: 
				break; 
			}
		}
		else if( eHandler.type == SDL_KEYUP )
		{ 
			switch( eHandler.key.keysym.sym )
			{
			case SDLK_ESCAPE: 
				QUIT = false;
				break; 
			case SDLK_UP:
				Key_Up=false;
				break; 
			case SDLK_DOWN:
				Key_Down=false;
				break; 
			case SDLK_LEFT:
				Key_Left=false;
				break; 
			case SDLK_RIGHT:
				Key_Right=false;
				break; 
			case SDLK_SPACE:
				Key_Space=false;
				break; 
			case SDLK_s:
				Key_S=false;
				break;
			case SDLK_q:
				Key_Q=false;
				break; 
			case SDLK_r:
				Key_R=false;
				break;
			default: 
				break; 
			}
		}
	}							
}