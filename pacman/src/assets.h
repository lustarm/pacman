#pragma once
#include <SDL.h>

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* texturePath);
	static void DrawTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
};
