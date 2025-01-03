#pragma once
#include <SDL.h>

class GameObject {
public:
	GameObject(const char*, int, int);
	~GameObject();

	void update();
	void render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, dstRect;
};
