#include <iostream>
#include <SDL_image.h>

#include "game.h"
#include "assets.h"

SDL_Texture* TextureManager::LoadTexture(const char* texturePath)
{

	SDL_Surface* surface_tmp = IMG_Load(texturePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface_tmp);
	SDL_FreeSurface(surface_tmp);

	if (!texture)
	{
		std::cout << "failed to load texture: " << texturePath << std::endl;
	}
	else
	{
		std::cout << "Loaded texture: " << texturePath << std::endl;
	}
	return texture;
}

void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst)
{
	SDL_RenderCopy(Game::renderer, texture, &src, &dst);
}
