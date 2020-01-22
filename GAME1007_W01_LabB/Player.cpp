#include "Player.h"
#include "TextureManager.h"
#include <iostream>
#include "Map.h"
using namespace std;

#define WIDTH 1024
#define HEIGHT 768
#define FPS 60
float accGravity = 0.4;
float maxGravity = 1.9;
float velocityX = 0,velocityY=0;
bool platform =false;

Player::Player():m_iSpeed(5), m_src{ 0, 0, 32, 64 }, g_iKeystates(SDL_GetKeyboardState(nullptr)), m_dst{ m_src.w, HEIGHT - 5*32-m_src.h  , m_src.w, m_src.h}
{
	    m_frame = 0,
		m_frameMax = 12,
		m_sprite = 0,
		m_spriteMax = 6;
		velX = 0,
		velY = 0;
		left = false;
		onGround = false;
		m_lastPosition = m_dst.y +m_dst.h;
		jumpVel = 4.0f;
		jumping = false;
		gravity = 0.04f;
	    cout << "Constructing player class...\n";
}

SDL_Texture* Player::loadPlayer(SDL_Renderer* m_pRenderer)
{
	m_pTexture= TextureManager::LoadTexture(m_pRenderer, "../Assets/Textures/CowboyCadet.png");
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
		m_src.x = 32 * m_sprite; // Set the new src x.
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



void Player::playerUpdate(Map *map)
{
	// This is the main game stuff.
	if (keyDown(SDL_SCANCODE_W))
		velocityY = -1.0f;
	if (keyDown(SDL_SCANCODE_SPACE) && onGround)
		velocityY = jumpVel * -1;
	if (!onGround)
	{
		velocityY += accGravity;
		if (velocityY> maxGravity)
		{
			velocityY = maxGravity;
		}
	}
	if (keyDown(SDL_SCANCODE_S))
		velocityY = 1.0f;
	if (keyDown(SDL_SCANCODE_A)) {
		left = true;
		velocityX = -1.0f;
	}
	if (keyDown(SDL_SCANCODE_D)) {
		left = false;
		velocityX = 1.0f;
	}
	if (!(keyDown(SDL_SCANCODE_A) || keyDown(SDL_SCANCODE_D)))
		velocityX = 0;

	velX = m_iSpeed * velocityX;
	velY = m_iSpeed * velocityY;
	
	m_dst.x += velX;
	checkCollision(velX, 0, map);
	onGround = false;
	m_dst.y += velY;
	checkCollision(0, velY, map);
	checkBound();
	animate();
	
}
void Player::checkBound()
{
	if (m_dst.x <= 0)
		m_dst.x = 0;
	if (m_dst.x + m_dst.w >= WIDTH)
		m_dst.x = WIDTH-m_dst.w;
	if (m_dst.y <= 0)
		m_dst.y = 0;
	if (m_dst.y+m_dst.h >= HEIGHT)
		m_dst.y = HEIGHT;
	
}

void Player::checkCollision(int x, int y, Map* map)
{
	int type = 0,top=0,left=0,right=0,bottom=0;
	SDL_Rect newDst = { m_dst.x+5,m_dst.y,m_dst.w - 5, m_dst.h };
	for (int row = 0; row < 24; row++)
		for (int column = 0; column < 32; column++)
		{
			type = map->colMap[row][column];
			top = row * 32;
			bottom = row * 32 + 32;
			left = column * 32;
			right = column * 32 + 32;
			SDL_Rect tile = { left,top,32,32 };
				//	cout << "tile Collision " << row << "  " << column << endl;
				if (SDL_HasIntersection(&newDst, &tile)) {
					if (type==1) {
					if (x > 0) {
							m_dst.x = left - m_dst.w;
							velocityX = 0;
					}
					if (x < 0)
					{
							m_dst.x= right-5;
							velocityX = 0;
					}
					if (y > 0)
					{
						m_dst.y = top - m_dst.h;
						velocityY = 0;
						onGround = true;
					}
					if (y < 0)
					{
						m_dst.y = bottom;
						velocityY = 0;
					}

				}
			
			}
				tile = { left,top,32,10 };
				newDst = { m_dst.x+5,m_dst.y+15*m_dst.h/16,m_dst.w - 5, m_dst.h/16};
				if (SDL_HasIntersection(&newDst, &tile)) {
				 if(type==2)
					{
					cout << "type 2 collide : vel"<< velX << "  " << velY <<"\t" ;
					if (y > 0)
					{
						cout << row << "  " << column << endl;
						//if (m_dst.y +m_dst.h>= top) {
						m_dst.y = top - m_dst.h;
						velocityY = 0;
						onGround = true;
						//}
					}
				}
			}
		}
}

void Player::playerDraw(SDL_Renderer* g_pRenderer)
{
	if (!left)
		TextureManager::Draw(g_pRenderer, m_pTexture, &m_src, &m_dst);
	else
		TextureManager::DrawLeft(g_pRenderer, m_pTexture, &m_src, &m_dst);
}

Player::~Player()
{

}