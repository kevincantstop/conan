#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

using namespace std;

class Game
{
private:
	bool running;

	SDL_Renderer* renderer;
	SDL_Window* window;

	int animFrame;
public:
	Game(const char* title, int width, int height);
	~Game();

	void init();
	void render();
	void update();
	void handleEvents();
	void down();

	bool isRunning()
	{
		return running;
	}
};
