#pragma once

#include "game.h"

class Map
{
public:
	Map();
	~Map();

	void loadMap(int [20][25]);
	void drawMap();

private:
	SDL_Rect src, dst;
	SDL_Texture* dirt;
	SDL_Texture* water;

	int map[20][25];
};
