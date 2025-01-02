#include <iostream>

#include "game.h"

Game::Game()
{
	// Why not just init here??
}

Game::~Game()
{

}

void Game::init()
{
	isRunning = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Failed to initalize SDL" << std::endl;
		isRunning = false;
		return;
	}
	std::cout << "Initialized SDL" << std::endl;

	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 600, flags);
	if (!window)
	{
		std::cout << "Failed to create window" << std::endl;
		isRunning = false;
		return;
	}
	std::cout << "Created window" << std::endl;
	
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		std::cout << "Failed to create renderer" << std::endl;
		isRunning = false;
		return;
	}
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	std::cout << "Created renderer" << std::endl;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update()
{

}

void Game::render()
{
	SDL_RenderClear(renderer);

	/* == Render here == */

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

bool Game::running() const
{
	return isRunning;
}
