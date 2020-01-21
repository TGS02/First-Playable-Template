#include "Engine.h"
#include "Player.h"
#include "Map.h"
#include "TextureManager.h"
#include <iostream>
#include <vector>

#define WIDTH 1024
#define HEIGHT 768
#define FPS 60
using namespace std;

Engine::Engine():g_bRunning(false)                          //class initializer way
{
	cout << "Constructing engine class...\n";
	
}



bool Engine::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	cout << "Initializing game." << endl;
	// Attempt to initialize SDL.
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		// Create the window.
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (g_pWindow != nullptr) // Window init success.
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			if (g_pRenderer != nullptr) // Renderer init success.
			{
				m_pTexture = IMG_LoadTexture(g_pRenderer, "../Assets/Textures/Background.png");
				map = new Map(g_pRenderer);
				player = new Player();
				player->loadPlayer(g_pRenderer);
			}
			else return false; // Renderer init fail.
		}
		else return false; // Window init fail.
	}
	else return false; // SDL init fail.
	g_fps = (Uint32)round((1 / (double)FPS) * 1000); // Sets FPS in milliseconds and rounds.
	g_iKeystates = SDL_GetKeyboardState(nullptr);
	m_src = { 0,0, 800, 400 };
	m_dst = { 0,0, WIDTH, HEIGHT };
	m_round = 0;
	g_bRunning = true; // Everything is okay, start the engine.
	cout << "Success!" << endl;
	return true;
}

void Engine::wake()
{
	g_start = SDL_GetTicks();
}

void Engine::sleep()
{
	g_end = SDL_GetTicks();
	g_delta = g_end - g_start;
	if (g_delta < g_fps) // Engine has to sleep.
		SDL_Delay(g_fps - g_delta);
}

void Engine::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT: // User pressed window's 'x' button.
			g_bRunning = false;
			break;
		case SDL_KEYDOWN: // Try SDL_KEYUP instead.
			if (event.key.keysym.sym == SDLK_ESCAPE)
				g_bRunning = false;
			break;
		}
	}
}

// Keyboard utility function.
bool Engine::keyDown(SDL_Scancode c)
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

void Engine::update()
{
	player->playerUpdate(map);
	
}

void Engine::render()
{
	vector<int> num = { 1,2,3,5,12,13,14,15 };
	SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(g_pRenderer); // Clear the screen with the draw color.
	SDL_RenderCopy(g_pRenderer, m_pTexture, &m_src, &m_dst);
	map->DrawMap(g_pRenderer, num); 
	// Render stuff.
	player->playerDraw(g_pRenderer);
	num.clear();
	num = { 21,22 };
	map->DrawMap(g_pRenderer, num);
	// Draw anew.
	SDL_RenderPresent(g_pRenderer);
}

void Engine::clean()
{
	cout << "Cleaning game." << endl;
	SDL_DestroyRenderer(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_Quit();
}

int Engine::run()
{
	if (init("GAME1007_SDL_Setup", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0) == false)
		return 1;
	while (g_bRunning)
	{
		wake();
		handleEvents();
		update();
		render();
		if (g_bRunning)
			sleep();
	}
	clean();
	return 0;
}

Engine::~Engine()
{
}
