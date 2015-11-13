#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>

class Texture
{
public:
	//Initializes variables
	Texture();

	//Deallocates memory
	~Texture();

	//Loads image at specified path
	bool loadFromFile(std::string path);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL);

	//Gets image dimensions
	int getWidth();
	int getHeight();

	void setRenderer(SDL_Renderer * gRenderer);

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	SDL_Renderer * gRenderer;

	//Image dimensions
	int mWidth;
	int mHeight;
};

