#include "game.h"

Game* game = nullptr;

int main(int argc, char *argv[])
{

	game = new Game();
	game->init();

	Uint32 frameStart, frameEnd;
	float deltaTime;

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

        frameEnd = SDL_GetTicks();
        deltaTime = (frameEnd - frameStart) / 1000.0f;

        // Set deltaTime, ensure it doesn't go to zero (optional safeguard)
        game->setDeltaTime(deltaTime > 0 ? deltaTime : 0.001f);
	}

	game->clean();

	return 0;
}