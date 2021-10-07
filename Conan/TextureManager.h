#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>

using namespace std;

class TextureManager
{
private:
	static TextureManager* self;
	SDL_Renderer* renderer;
	map<string, SDL_Texture*> textures;
	TextureManager() {};
	string path;

public:
	static TextureManager* instance()
	{
		if (self == 0) 
		{
			self = new TextureManager();
		}
		return self;
	}

	void init(SDL_Renderer* renderer);
	bool load(string path, string name);
	void draw(string name, int x, int y, int w, int h, SDL_RendererFlip flip);
	void drawFrame(string name, int x, int y, int w, int h, int row, int frame, SDL_RendererFlip flip);
};