#pragma once

#include <SDL.h>

class Game {
public:
	Game();
	~Game();

	void init();

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() const;

private:
	bool isRunning;

	bool fullscreen;

	SDL_Window *window;
	SDL_Renderer *renderer;
};
