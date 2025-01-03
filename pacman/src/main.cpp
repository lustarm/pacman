#include "game.h"

Game* game = nullptr;

int main(int argc, char *argv[])
{

	game = new Game();
	game->init();

	Uint64 ct = SDL_GetPerformanceCounter();
	Uint64 lst = 0;
	float dt = 0.0f;

	while (game->running())
	{
		lst = ct;
		ct = SDL_GetPerformanceCounter();
		dt = (float)((ct - lst) * 1000 / (float)SDL_GetPerformanceFrequency());

		game->setDeltaTime(dt);

		game->handleEvents();
		game->update();

		game->render();
	}

	game->clean();

	return 0;
}