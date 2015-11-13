#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"

enum TileSpriteClips
{
	TILE_SPRITE_O = 0,
	TILE_SPRITE_X = 1,
	TILE_SPRITE_BLANK = 2,
	TILE_SPRITE_TOTAL = 3
};

/***************************************************
 * Tile
 * The class represents one of the tiles of a board.
 * It holds a data value either X or O and retuns
 * the data upon request.
 ***************************************************/
class Tile
{
public:
	Tile();
	void setRenderer(SDL_Renderer* renderer);
	void draw();
	void draw(int w, int h);
	SDL_Rect getCurrentSpriteClip();
	// sets the letter
	void setLetter(char letter);
	void setPosition(int x, int y);
	char getLetter();
	bool empty();
	SDL_Point getPosition();
	// set sprite clips 
	void setSprite(int n);
private:
	SDL_Renderer *renderer;
	SDL_Point pos;
	Texture texture;
	TileSpriteClips currentSprite;
	SDL_Rect spriteSheetClips[TILE_SPRITE_TOTAL];
	char letter; // holds a letter X or O
};
