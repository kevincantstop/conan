#include "Game.h"
#include "TextureManager.h"

Game::Game(const char* title, int width, int height)
{
	running = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

		if (window != 0)
		{
			renderer = SDL_CreateRenderer(window, -1, 0);

			running = true;
			TextureManager::instance()->init(renderer);
		}
	}
}

Game::~Game()
{

}

void Game::init()
{
	TextureManager::instance()->load("/assets/animate-alpha.png", "animate");
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	TextureManager::instance()->draw("animate", 0, 0, 128, 82, SDL_FLIP_HORIZONTAL);

	TextureManager::instance()->drawFrame("animate", 100, 100, 128, 82, 1, animFrame, SDL_FLIP_NONE);

	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
		}
	}
}

void Game::down()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::update()
{
	animFrame = int(((SDL_GetTicks() / 100) % 6));
}