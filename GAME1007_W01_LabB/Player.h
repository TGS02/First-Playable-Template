#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

using namespace std;


class Player
{

private:

	SDL_Texture* m_pTexture;
	int m_iSpeed;
	SDL_Rect m_src, m_dst;
	int m_frame, 
		m_frameMax, 
		m_sprite, 
		m_spriteMax; 
	const Uint8* g_iKeystates;




public:

	Player();
	~Player();
	SDL_Texture* loadPlayer(SDL_Renderer*);
	bool keyDown(SDL_Scancode);
	void playerUpdate();
	void playerDraw(SDL_Renderer*);
	void animate();


};

