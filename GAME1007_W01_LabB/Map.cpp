#include "Map.h"
#include "TextureManager.h"
#include <vector>

int mapArr[24][32] = {
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,13,14,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,13,13,14,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,1,2,3,0,0,0,0,0,0,0,1,2,3,0,0,0,0,0,0,0,0,0,0 },
{ 2,2,2,2,2,2,2,2,2,2,2,2,2,21,21,21,21,2,2,5,5,5,2,2,2,2,2,2,2,2,2,2 },
{ 5,5,5,5,5,5,5,5,5,5,5,5,5,22,22,22,22,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 } };

int ColMapArr[24][32] = {
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };

Map::Map(SDL_Renderer* m_pRenderer)
{
	tile2 = TextureManager::LoadTexture	( m_pRenderer,"../Assets/Textures/Tile2.png");
	tile3  = TextureManager::LoadTexture( m_pRenderer,"../Assets/Textures/Tile3.png");
	tile5  = TextureManager::LoadTexture( m_pRenderer,"../Assets/Textures/Tile5.png");
	tile12 = TextureManager::LoadTexture( m_pRenderer,"../Assets/Textures/Tile12.png");
	tile13 = TextureManager::LoadTexture( m_pRenderer,"../Assets/Textures/Tile13.png");
	tile1  = TextureManager::LoadTexture( m_pRenderer,"../Assets/Textures/Tile1.png");
	tile14 = TextureManager::LoadTexture( m_pRenderer,"../Assets/Textures/Tile14.png");
	tile15 = TextureManager::LoadTexture( m_pRenderer,"../Assets/Textures/Tile15.png");
	acid1   = TextureManager::LoadTexture( m_pRenderer,"../Assets/Textures/Acid1.png");
	acid2= TextureManager::LoadTexture(m_pRenderer, "../Assets/Textures/Acid2.png");
	src.x = src.y = 0;
	src.w = dst.w = 32; 
	src.h = dst.h = 32;
	dst.x = dst.y = 0;
	loadMap(mapArr);
	checkColMap(ColMapArr);
}

Map::~Map()
{
	
}

void Map::checkColMap(int arr[24][32])
{
	for (int row = 0; row < 24; row++)
		for (int column = 0; column < 32; column++)
		{
			colMap[row][column] = ColMapArr[row][column];
		}
}

void Map::loadMap(int arr[24][32])
{
	for (int row=0; row< 24; row++)
		for(int column=0; column<32;column++)
		{
			map[row][column] = arr[row][column];
		}
}

void Map::DrawMap(SDL_Renderer* g_pRenderer, vector<int> numTile)
{
	int type = 0;
	for (int row = 0; row < 24; row++)
		for (int column = 0; column < 32; column++)
		{
			type = map[row][column]; 
			dst.x = column * 32;
			dst.y = row * 32;
			for (int i=0; i< numTile.size(); i++)
				if (type == numTile[i]) {
					switch (type)
					{
					case 0:
						break;
					case 1:
						TextureManager::Draw(g_pRenderer, tile1, &src, &dst);
						break;
					case 2:
						TextureManager::Draw(g_pRenderer, tile2, &src, &dst);
						break;
					case 3:
						TextureManager::Draw(g_pRenderer, tile3, &src, &dst);
						break;
					case 5:
						TextureManager::Draw(g_pRenderer, tile5, &src, &dst);
						break;
					case 12:
						TextureManager::Draw(g_pRenderer, tile12, &src, &dst);
						break;
					case 13:
						TextureManager::Draw(g_pRenderer, tile13, &src, &dst);
						break;
					case 14:
						TextureManager::Draw(g_pRenderer, tile14, &src, &dst);
						break;
					case 15:
						TextureManager::Draw(g_pRenderer, tile15, &src, &dst);
						break;
					case 21:
						SDL_SetTextureAlphaMod(acid1, 128);
						TextureManager::Draw(g_pRenderer, acid1, &src, &dst);
						break;
					case 22:
						SDL_SetTextureAlphaMod(acid2, 128);
						TextureManager::Draw(g_pRenderer, acid2, &src, &dst);
						break;
					default:
						break;
					}
				}
		}
}
 
void Map:: update(int round)
{
	
}

string Map::checkMiddlePlatforms(int tmpRow, int tmpCol)
{
	string pos;
	if (map[tmpRow][tmpCol - 1] != 0 && map[tmpRow][tmpCol + 1] == 0)
		return "left";
	else if (map[tmpRow][tmpCol - 1] == 0 && map[tmpRow][tmpCol + 1] != 0)
		return "right";
	else if (map[tmpRow][tmpCol - 1] != 0 && map[tmpRow][tmpCol + 1] != 0)
		return  "both";
	else return  "none";
	

	
}
