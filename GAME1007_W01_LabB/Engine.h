#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "Player.h"
class Engine
{
private:   //Properties
	bool g_bRunning; // Loop control flag.
	int g_iSpeed = 5; // Speed of box.
	const Uint8* g_iKeystates; // Keyboard state container.
	Uint32 g_start, g_end, g_delta, g_fps; // Fixed timestep variables.
	SDL_Window* g_pWindow; // This represents the SDL window.
	SDL_Renderer* g_pRenderer; // This represents the buffer to draw to.
	SDL_Texture* m_pTexture;
	SDL_Rect m_src, m_dst;
	Player player;

private:   //methods
	bool init(const char* , int , int , int , int, int);        //you could define all these functions inline(copy the whole function including its body here)
	void wake();
	void sleep();
	void handleEvents();
	bool keyDown(SDL_Scancode c);
	void update();
	void render();
	void clean();


public:
	Engine();
	int run();
	~Engine();
};

