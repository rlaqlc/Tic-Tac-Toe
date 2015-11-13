#include "Tile.h"



Tile::Tile()
{
	currentSprite = TILE_SPRITE_BLANK;
	renderer = NULL;

	letter = 'n';

	// clip
	spriteSheetClips[0].x = 3;
	spriteSheetClips[0].y = 2;
	spriteSheetClips[0].w = 28;
	spriteSheetClips[0].h = 27;

	spriteSheetClips[1].x = 2;
	spriteSheetClips[1].y = 51;
	spriteSheetClips[1].w = 25;
	spriteSheetClips[1].h = 28;

	spriteSheetClips[2].x = 35;
	spriteSheetClips[2].y = 3;
	spriteSheetClips[2].w = 15;
	spriteSheetClips[2].h = 15;

}

void Tile::setRenderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

void Tile::draw()
{
	texture.setRenderer(renderer);
	texture.loadFromFile("resources/sprite.png");
	texture.render(pos.x, pos.y, &spriteSheetClips[currentSprite]);
}

void Tile::draw(int w, int h)
{
	spriteSheetClips[currentSprite].h = h;
	spriteSheetClips[currentSprite].h = w;
	texture.setRenderer(renderer);
	texture.loadFromFile("resources/sprite.png");
	texture.render(pos.x, pos.y, &spriteSheetClips[currentSprite]);

}

SDL_Rect Tile::getCurrentSpriteClip()
{
	SDL_Rect spriteClip = spriteSheetClips[currentSprite];
	return spriteClip;
}

// sets the letter
void Tile::setLetter(char letter)
{
	this->letter = letter;
}

void Tile::setPosition(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

// returns the letter. if it's O it returns O. if it's X, it returns x.
char Tile::getLetter()
{
	return letter;
}

bool Tile::empty()
{
	// if it contains initial value 'n' 
	// then it means it's empty
	if (letter == 'n')
	{
		return true;
	}
	else
	{
		return false;
	}
}

SDL_Point Tile::getPosition()
{
	return this->pos;
}

// receives integer value
void Tile::setSprite(int n)
{
	if (n == 1)
	{
		currentSprite = TILE_SPRITE_O;
	}
	else if (n == 2)
	{
		currentSprite = TILE_SPRITE_X;
	}
	else
	{
		currentSprite = TILE_SPRITE_BLANK;
	}
}