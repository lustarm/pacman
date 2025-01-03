#pragma once

#include <SDL.h>

class Game {
public:
	Game();
	~Game();

	void init();

	void handleEvents();
	void update() const;
	void render();
	void clean();

	bool running() const;

	float getMovementSpeed() const;
	void setTime(float);
	float getFramerate() const;

	float getDeltaTime() const;
	void setDeltaTime(float);

private:
	bool isRunning;
	bool fullscreen;

	float movementSpeed = 1.0f;
	float time_;
	float framerate;
	float deltaTime;
	float movement;

	SDL_Window *window;
	SDL_Renderer *renderer;
};
