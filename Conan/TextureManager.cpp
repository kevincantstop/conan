#include "TextureManager.h"

TextureManager* TextureManager::self = 0;

void TextureManager::init(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	path = string(SDL_GetBasePath());
}

bool TextureManager::load(string image, string name)
{
	SDL_Surface* surface = IMG_Load((path + image).c_str());

	if (surface == 0)
	{
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	if (texture != 0)
	{
		textures[name] = texture;
		return true;
	}

	return false;
}

void TextureManager::draw(string name, int x, int y, int w, int h, SDL_RendererFlip flip)
{
	SDL_Rect sourceRect;
	SDL_Rect targetRect;

	sourceRect.x = 0;
	sourceRect.y = 0;

	targetRect.x = x;
	targetRect.y = y;

	targetRect.w = sourceRect.w = w;
	targetRect.h = sourceRect.h = h;

	SDL_RenderCopyEx(renderer, textures[name], &sourceRect, &targetRect, 0, 0, flip);
}

void TextureManager::drawFrame(string name, int x, int y, int w, int h, int row, int frame, SDL_RendererFlip flip)
{
	SDL_Rect sourceRect;
	SDL_Rect targetRect;

	sourceRect.x = w * frame;
	sourceRect.y = h * (row - 1);

	targetRect.x = x;
	targetRect.y = y;

	targetRect.w = sourceRect.w = w;
	targetRect.h = sourceRect.h = h;

	SDL_RenderCopyEx(renderer, textures[name], &sourceRect, &targetRect, 0, 0, flip);
}