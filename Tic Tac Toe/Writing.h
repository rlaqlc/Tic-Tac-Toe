#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"

class Writing
{
public:
	enum WritingSpriteClips
	{
		WRITING_SPRITE_BLANK,
		WRITING_SPRITE_ONE_THIRD,
		WRITING_SPRITE_TWO_THIRD,
		WRITING_SPRITE_THREE_THIRD,
		WRITING_SPRITE_ONE,
		WRITING_SPRITE_TWO,
		WRITING_SPRITE_THREE,
		WRITING_SPRITE_ZERO,
		WRITING_SPRITE_CROSS_1,
		WRITING_SPRITE_CROSS_2,
		WRITING_SPRITE_TOTAL
	};
	Writing();
	void setRenderer(SDL_Renderer * renderer);
	void setPosition(int x, int y);
	void setSprite(int n);
	void clipSpriteSheet();
	void draw();
	~Writing();
private:
	int currentWidth;
	SDL_Renderer *renderer;
	SDL_Point pos;
	WritingSpriteClips currentClip;
	SDL_Rect spriteClips[WRITING_SPRITE_TOTAL];
	Texture texture;

};

