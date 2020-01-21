#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* m_pRenderer, const char* fileName)
{
	return IMG_LoadTexture(m_pRenderer, fileName);
}

void TextureManager::Draw(SDL_Renderer* m_pRenderer, SDL_Texture* tex, SDL_Rect* src, SDL_Rect* dst)
{
	SDL_RenderCopy(m_pRenderer, tex, src, dst);

}

void TextureManager::DrawLeft(SDL_Renderer* m_pRenderer, SDL_Texture* tex, SDL_Rect* src, SDL_Rect* dst)
{
	
	SDL_RenderCopyEx(m_pRenderer, tex, src, dst, NULL, NULL,	SDL_FLIP_HORIZONTAL);
}


