#include <iostream>

#include "game.h"
#include "gameobject.h"
#include "assets.h"

GameObject::GameObject(const char* texturePath, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturePath);

	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{

}

void GameObject::update()
{
	srcRect.h = 256;
	srcRect.w = 256;

	dstRect.h = srcRect.h * 2;
	dstRect.w = srcRect.w * 2;

	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.x = xpos;
	dstRect.y = ypos;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &dstRect);
}

