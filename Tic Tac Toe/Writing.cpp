#include "Writing.h"



Writing::Writing()
{
	currentWidth = 0;
	renderer = NULL;
	pos.x = 0;
	pos.y = 0;
	currentClip = WRITING_SPRITE_BLANK;

	// clips from spritesheet
	clipSpriteSheet();
}

void Writing::setRenderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
	texture.setRenderer(renderer);
}

void Writing::setPosition(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

void Writing::setSprite(int n)
{
	switch (n)
	{
	case 0:
		currentClip = WRITING_SPRITE_BLANK;
		break;
	case 1:
		currentClip = WRITING_SPRITE_ONE_THIRD;
		break;
	case 2:
		currentClip = WRITING_SPRITE_TWO_THIRD;
		break;
	case 3:
		currentClip = WRITING_SPRITE_THREE_THIRD;
		break;
	case 4:
		currentClip = WRITING_SPRITE_ONE;
		break;
	case 5:
		currentClip = WRITING_SPRITE_TWO;
		break;
	case 6:
		currentClip = WRITING_SPRITE_THREE;
		break;
	case 7:
		currentClip = WRITING_SPRITE_ZERO;
		break;
	case 8:
		currentClip = WRITING_SPRITE_CROSS_1;
		break;
	case 9:
		currentClip = WRITING_SPRITE_CROSS_2;
		break;
	}

	currentWidth = spriteClips[currentClip].w;
}

void Writing::clipSpriteSheet()
{

	/*
	CLIP
	*/
	spriteClips[0].x = 35;
	spriteClips[0].y = 3;
	spriteClips[0].h = 15;
	spriteClips[0].w = 15;

	spriteClips[1].x = 3;
	spriteClips[1].y = 95;
	spriteClips[1].h = 28;
	spriteClips[1].w = 58;

	spriteClips[2].x = 3;
	spriteClips[2].y = 137;
	spriteClips[2].h = 28;
	spriteClips[2].w = 58;

	spriteClips[3].x = 3;
	spriteClips[3].y = 179;
	spriteClips[3].h = 28;
	spriteClips[3].w = 58;

	spriteClips[4].x = 2;
	spriteClips[4].y = 220;
	spriteClips[4].h = 17;
	spriteClips[4].w = 12;

	spriteClips[5].x = 2;
	spriteClips[5].y = 247;
	spriteClips[5].h = 17;
	spriteClips[5].w = 13;

	spriteClips[6].x = 3;
	spriteClips[6].y = 274;
	spriteClips[6].h = 17;
	spriteClips[6].w = 12;

	spriteClips[7].x = 2;
	spriteClips[7].y = 296;
	spriteClips[7].h = 14;
	spriteClips[7].w = 14;

	spriteClips[8].x = 4;
	spriteClips[8].y = 318;
	spriteClips[8].h = 7;
	spriteClips[8].w = 152;

	spriteClips[9].x = 112;
	spriteClips[9].y = 24;
	spriteClips[9].h = 156;
	spriteClips[9].w = 7;
}

void Writing::draw()
{
	texture.loadFromFile("resources/sprite.png");
	texture.render(pos.x, pos.y, &spriteClips[currentClip]);
}

Writing::~Writing()
{
}
