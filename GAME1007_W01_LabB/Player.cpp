#include "Player.h"

#include <iostream>
using namespace std;

#define WIDTH 1024
#define HEIGHT 768
#define FPS 60

Player::Player():m_iSpeed(5), m_src{ 0, 0, 75, 120 }, g_iKeystates(SDL_GetKeyboardState(nullptr)), m_dst{ 10, HEIGHT-150 , m_src.w/2, m_src.h/2 }
{
	    m_frame = 0,
		m_frameMax = 12,
		m_sprite = 0,
		m_spriteMax = 3;
	    cout << "Constructing player class...\n";
}

SDL_Texture* Player::loadPlayer(SDL_Renderer* m_pRenderer)
{
	m_pTexture= IMG_LoadTexture(m_pRenderer, "Player.png");
	return m_pTexture;
	
}
void Player::animate()
{
	if (m_frame == m_frameMax)
	{
		m_frame = 0; // Roll the frame ctr back to 0.
		m_sprite++; // Increment the sprite index.
		if (m_sprite == m_spriteMax)
			m_sprite = 0;
		m_src.x = 75 * m_sprite; // Set the new src x.
	}
	m_frame++; // Increment frame counter.
}




bool Player::keyDown(SDL_Scancode c)
{
	if (g_iKeystates != nullptr)
	{
		if (g_iKeystates[c] == 1)
			return true;
		else
			return false;
	}
	return false;
}



void Player::playerUpdate()
{
	// This is the main game stuff.
	if (keyDown(SDL_SCANCODE_W))
		m_dst.y -= m_iSpeed;
	if (keyDown(SDL_SCANCODE_S))
		m_dst.y += m_iSpeed;
	if (keyDown(SDL_SCANCODE_A))
		m_dst.x -= m_iSpeed;
	if (keyDown(SDL_SCANCODE_D))
		m_dst.x += m_iSpeed;
	animate();
}

void Player::playerDraw(SDL_Renderer* g_pRenderer)
{
	

	SDL_RenderCopy(g_pRenderer, m_pTexture, &m_src, &m_dst);

}

Player:: ~Player()
{

}