#include <SDL_image.h>

#include "assets.h"

SDL_Texture* loadTexture(const char* texturePath, SDL_Renderer* renderer)
{
	SDL_Surface* surface_tmp = IMG_Load(texturePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface_tmp);
	return texture;
}