#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Map.h"
using namespace std;


class Player
{

private:

	SDL_Texture* m_pTexture;
	int m_iSpeed;
	int velX, velY;
	SDL_Rect m_src, m_dst;
	int m_frame, 
		m_frameMax, 
		m_sprite, 
		m_spriteMax; 
	const Uint8* g_iKeystates;
	bool left;
	bool onGround;
	int m_lastPosition;
	float jumpVel ;
	bool  jumping;
    float gravity ;





public:

	Player();
	~Player();
	SDL_Texture* loadPlayer(SDL_Renderer*);
	bool keyDown(SDL_Scancode);
	void playerUpdate(Map* map);
	void jump();
	void playerDraw(SDL_Renderer*);
	void animate();
	void checkCollision(int x, int y, Map* map);
	void checkBound();

};

