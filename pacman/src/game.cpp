#include <iostream>
#include <iomanip>

#include "game.h"
#include "assets.h"

SDL_Texture* playerTexture;
SDL_Rect srcRect, dstRect;

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
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	std::cout << "Created renderer" << std::endl;

	// Create surface
	playerTexture = TextureManager::LoadTexture("assets/TinySwords/Factions/Knights/Troops/Warrior/Blue/Warrior_Blue.png", renderer);
	if (!playerTexture)
	{
		std::cout << "Failed to load player texture" << std::endl;
		isRunning = false;
		return;
	}
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
		case SDL_KEYDOWN:
			break;
		default:
			break;
	}
}

void Game::update() const
{
    if (dstRect.h == 0 && dstRect.w == 0) // Example check to initialize only once
    {
        dstRect.h = 32;
        dstRect.w = 32;
    }
	std::cout << deltaTime << std::endl;
	
	float speed = 1.0f;
	// dstRect.x += speed * deltaTime;
}

void Game::render()
{
	SDL_RenderClear(renderer);

	/* == Render here == */
	SDL_RenderCopy(renderer, playerTexture, NULL, &dstRect);

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

/* == Other shit == */
float Game::getMovementSpeed() const
{
	return movementSpeed;
}

float Game::getFramerate() const
{
	return framerate;
}

float Game::getDeltaTime() const
{
	return deltaTime;
}

void Game::setDeltaTime(float dt)
{
	deltaTime = dt;
}

void Game::setTime(float t_)
{
	time_ = t_;
}
