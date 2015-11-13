#pragma once

#include "Tile.h"
#include "Texture.h"
#include "Player.h"
#include "Writing.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

#define BOARD_FILE_PATH "resources/board.png"

class Board
{
public:
	Board();
	enum BoardWritingType
	{
		ROUND,
		PLAYER_SCORE,
		CPU_SCORE,
		TIE_COUNT,
		CROSS,
		TOTAL
	};
	// requires the app's main renderer
	void setRenderer(SDL_Renderer* renderer);
	// draw the board
	void draw();
	void setRound(int round);
	void setPlayerScore(int score);
	void setNumTies(int numTies);
	void setCpuScore(int score);
	// overloaded functions
	void setTile(int x, int y);
	void setTile(Player player);
	void loadSpriteSheet();
	bool isOnBoard(int x, int y);
	void setCrossingLine(int n);
	void setSprite(int x, int y);
	bool isFull();
	void clear(); // clears board
	// 1 == human won (o), 2 == cpu won (x)
	int checkWinner();
	int getCrossingPos();
	~Board();
private:
	/*

	tile[y][x]

	   0  1  2
	0 [ ][ ][ ]
	1 [ ][ ][ ]
	2 [ ][ ][ ]
	
	*/
	Tile tile[3][3];
	/*
	0 = rounds
	1 = human score
	2 = cpu score
	3 = tie
	*/
	Writing writings[TOTAL];
	SDL_Renderer *renderer;
	Texture texture; // using wrapper class (obj)
};

