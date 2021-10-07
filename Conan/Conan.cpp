#include "Game.h"

int main(int argc, char* args[])
{
	Game* game = new Game("Conan", 640, 480);

	game->init();

	while (game->isRunning())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->down();
	return 0;
}