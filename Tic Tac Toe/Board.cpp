#include "Board.h"
#include <iostream>



Board::Board()
{
	renderer = NULL;	
}

void Board::setRenderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
	texture.setRenderer(renderer);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tile[i][j].setRenderer(renderer);
		}
	}

	writings[ROUND].setRenderer(renderer);
	writings[PLAYER_SCORE].setRenderer(renderer);
	writings[CPU_SCORE].setRenderer(renderer);
	writings[TIE_COUNT].setRenderer(renderer);
	writings[CROSS].setRenderer(renderer);

}

void Board::draw()
{
	// draw the main board artwork
	texture.loadFromFile(BOARD_FILE_PATH);
	texture.render(0, 0);

	// draw each tiles
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tile[i][j].draw();
		}
	}
	
	// draw writings on the board
	writings[ROUND].draw();
	writings[PLAYER_SCORE].draw();
	writings[CPU_SCORE].draw();
	writings[TIE_COUNT].draw();
	writings[CROSS].draw();
}

void Board::setRound(int round)
{
	if (round > 0 && round <= 3)
	{
		switch (round)
		{
		case 1:
			writings[0].setSprite(1);
			break;
		case 2:
			writings[0].setSprite(2);
			break;
		case 3:
			writings[0].setSprite(3);
			break;
		}
	}
}

void Board::setPlayerScore(int score)
{
	if (score >= 0 && score <= 3)
	{
		switch (score)
		{
		case 0:
			writings[PLAYER_SCORE].setSprite(7);
			break;
		case 1:
			writings[PLAYER_SCORE].setSprite(4);
			break;
		case 2:
			writings[PLAYER_SCORE].setSprite(5);
			break;
		case 3:
			writings[PLAYER_SCORE].setSprite(6);
			break;
		}
	}
}

void Board::setNumTies(int numTies)
{
	if (numTies >= 0 && numTies <= 3)
	{
		switch (numTies)
		{
		case 0:
			writings[TIE_COUNT].setSprite(7);
			break;
		case 1:
			writings[TIE_COUNT].setSprite(4);
			break;
		case 2:
			writings[TIE_COUNT].setSprite(5);
			break;
		case 3:
			writings[TIE_COUNT].setSprite(6);
			break;
		}
	}
}

void Board::setCpuScore(int score)
{
	if (score >= 0 && score <= 3)
	{
		switch (score)
		{
		case 0:
			writings[CPU_SCORE].setSprite(7);
			break;
		case 1:
			writings[CPU_SCORE].setSprite(4);
			break;
		case 2:
			writings[CPU_SCORE].setSprite(5);
			break;
		case 3:
			writings[CPU_SCORE].setSprite(6);
			break;
		}
	}
}

void Board::setTile(int x, int y)
{
	if (x < 213 && y < 150 && x > 155 && y > 90 && tile[0][0].empty())
	{
		/*
		[*][ ][ ]
		[ ][ ][ ]
		[ ][ ][ ]
		*/
		tile[0][0].setLetter('O');
		tile[0][0].setSprite(1);
	}
	else if (x < 287 && y < 150 && x > 215 && y > 90 && tile[0][1].empty())
	{
		/*
		[ ][*][ ]
		[ ][ ][ ]
		[ ][ ][ ]
		*/
		tile[0][1].setLetter('O');
		tile[0][1].setSprite(1);
	}
	else if (x < 344 && y < 150 && x > 292 && y > 90 && tile[0][2].empty())
	{
		/*
		[ ][ ][*]
		[ ][ ][ ]
		[ ][ ][ ]
		*/
		tile[0][2].setLetter('O');
		tile[0][2].setSprite(1);
	}
	else if (x < 210 && y < 214 && x > 156 && y > 154 && tile[1][0].empty())
	{

		/*
		[ ][ ][ ]
		[*][ ][ ]
		[ ][ ][ ]
		*/
		tile[1][0].setLetter('O');
		tile[1][0].setSprite(1);
	}
	else if (x < 282 && y < 214 && x > 216 && y > 154 && tile[1][1].empty())
	{

		/*
		[ ][ ][ ]
		[ ][*][ ]
		[ ][ ][ ]
		*/
		tile[1][1].setLetter('O');
		tile[1][1].setSprite(1);
	}
	else if (x < 348 && y < 211 && x > 288 && y > 154 && tile[1][2].empty())
	{
		/*
		[ ][ ][ ]
		[ ][ ][*]
		[ ][ ][ ]
		*/
		tile[1][2].setLetter('O');
		tile[1][2].setSprite(1);
	}
	else if (x < 212 && y < 269 && x > 150 && y > 223 && tile[2][0].empty())
	{
		/*
		[ ][ ][ ]
		[ ][ ][ ]
		[*][ ][ ]
		*/
		tile[2][0].setLetter('O');
		tile[2][0].setSprite(1);
	}
	else if (x < 280 && y < 269 && x > 218 && y > 223 && tile[2][1].empty())
	{
		/*
		[ ][ ][ ]
		[ ][ ][ ]
		[ ][*][ ]
		*/
		tile[2][1].setLetter('O');
		tile[2][1].setSprite(1);
	}
	else if (x < 344 && y < 265 && x > 288 && y > 219 && tile[2][2].empty())
	{

		/*
		[ ][ ][ ]
		[ ][ ][ ]
		[ ][ ][*]
		*/
		tile[2][2].setLetter('O');
		tile[2][2].setSprite(1);
	}

}

void Board::setTile(Player player)
{
	bool done = false;

	while (!done)
	{
		int x = player.getCpuColValue();
		int y = player.getCpuRowValue();

		if (tile[y][x].empty())
		{
			tile[y][x].setLetter('X');
			tile[y][x].setSprite(2);
			done = true;
		}
	}

}

void Board::loadSpriteSheet()
{
	tile[0][0].setPosition(170, 108);
	tile[0][1].setPosition(237, 108);
	tile[0][2].setPosition(304, 108);

	tile[1][0].setPosition(170, 176);
	tile[1][1].setPosition(237, 174);
	tile[1][2].setPosition(304, 173);

	tile[2][0].setPosition(170, 238);
	tile[2][1].setPosition(237, 235);
	tile[2][2].setPosition(304, 233);

	writings[0].setPosition(455, 187);
	writings[1].setPosition(150, 340);
	writings[2].setPosition(452, 340);
	writings[3].setPosition(295, 340);
}

// checks if the mouse cursor is in a tile boundary
bool Board::isOnBoard(int x, int y)
{
	bool onBoard = false;

	if (x < 213 && y < 150 && x > 155 && y > 90 && tile[0][0].empty())
	{
		onBoard = true;
	}
	else if (x < 287 && y < 150 && x > 215 && y > 90 && tile[0][1].empty())
	{
		onBoard = true;
	}
    else if (x < 344 && y < 150 && x > 292 && y > 90 && tile[0][2].empty())
	{
		onBoard = true;
	}
	else if (x < 210 && y < 214 && x > 156 && y > 154 && tile[1][0].empty())
	{
		onBoard = true;
	}
	else if (x < 282 && y < 214 && x > 216 && y > 154 && tile[1][1].empty())
	{
		onBoard = true;
	}
	else if (x < 348 && y < 211 && x > 288 && y > 154 && tile[1][2].empty())
	{
		onBoard = true;
	}
	else if (x < 212 && y < 269 && x > 150 && y > 223 && tile[2][0].empty())
	{
		onBoard = true;
	}
	else if (x < 280 && y < 269 && x > 218 && y > 223 && tile[2][1].empty())
	{
		onBoard = true;
	}
	else if (x < 344 && y < 265 && x > 288 && y > 219 && tile[2][2].empty())
	{
		onBoard = true;
	}

	return onBoard;
}

void Board::setCrossingLine(int n)
{
	switch (n)
	{
	case 0:
		writings[CROSS].setSprite(0);
		break;
	case 1:
		/*
		[O][O][O]
		[ ][ ][ ]
		[ ][ ][ ]
		*/
		writings[CROSS].setPosition(175, 120);
		writings[CROSS].setSprite(8);
		break;
	case 2:
		/*
		[ ][ ][ ]
		[0][0][0]
		[ ][ ][ ]
		*/
		writings[CROSS].setPosition(175, 185);
		writings[CROSS].setSprite(8);
		break;
	case 3:
		/*
		[ ][ ][ ]
		[ ][ ][ ]
		[0][0][0]
		*/
		writings[CROSS].setPosition(175, 245);
		writings[CROSS].setSprite(8);
		break;
	case 4:
		/*
		[O][ ][ ]
		[0][ ][ ]
		[0][ ][ ]
		*/
		writings[CROSS].setPosition(181, 111);
		writings[CROSS].setSprite(9);
		break;
	case 5:
		/*
		[ ][0][ ]
		[ ][0][ ]
		[ ][0][ ]
		*/
		writings[CROSS].setPosition(248, 108);
		writings[CROSS].setSprite(9);
		break;
	case 6:
		/*
		[ ][ ][0]
		[ ][ ][0]
		[ ][ ][0]
		*/
		writings[CROSS].setPosition(316, 107);
		writings[CROSS].setSprite(9);
		break;
	case 7:
		break;
	case 8:
		break;
	}
}

void Board::setSprite(int x, int y)
{
	loadSpriteSheet();

	/*
	[*][ ][ ]
	[ ][ ][ ]
	[ ][ ][ ]
	*/
	if (x < 213 && y < 150 && x > 155 && y > 90 && tile[0][0].empty())
	{
		tile[0][0].setSprite(1);
	}
	else 
	{
		// to prevent from already occupied tile changes
		if (tile[0][0].empty())
		{
			tile[0][0].setSprite(3);
		}
	}
	
	/*
	[ ][*][ ]
	[ ][ ][ ]
	[ ][ ][ ]
	*/
	if (x < 287 && y < 150 && x > 215 && y > 90 && tile[0][1].empty())
	{
		tile[0][1].setSprite(1);
	}
	else
	{
		if (tile[0][1].empty())
		{
			tile[0][1].setSprite(3);
		}
	}

	/*
	[ ][ ][*]
	[ ][ ][ ]
	[ ][ ][ ]
	*/
	if (x < 344 && y < 150 && x > 292 && y > 90 && tile[0][2].empty())
	{
		tile[0][2].setSprite(1);
	}
	else
	{
		if (tile[0][2].empty())
		{
			tile[0][2].setSprite(3);
		}
	}

	/*
	[ ][ ][ ]
	[*][ ][ ]
	[ ][ ][ ]
	*/
	if (x < 210 && y < 214 && x > 156 && y > 154 && tile[1][0].empty())
	{
		tile[1][0].setSprite(1);
	}
	else
	{
		if (tile[1][0].empty())
		{
			tile[1][0].setSprite(3);
		}
	}

	/*
	[ ][ ][ ]
	[ ][*][ ]
	[ ][ ][ ]
	*/
	if (x < 282 && y < 214 && x > 216 && y > 154 && tile[1][1].empty())
	{
		tile[1][1].setSprite(1);
	}
	else
	{
		if (tile[1][1].empty())
		{
			tile[1][1].setSprite(3);
		}
	}

	/*
	[ ][ ][ ]
	[ ][ ][*]
	[ ][ ][ ]
	*/
	if (x < 348 && y < 211 && x > 288 && y > 154 && tile[1][2].empty())
	{
		tile[1][2].setSprite(1);
	}
	else
	{
		if (tile[1][2].empty())
		{
			tile[1][2].setSprite(3);
		}
	}

	/*
	[ ][ ][ ]
	[ ][ ][ ]
	[*][ ][ ]
	*/
	if (x < 212 && y < 269 && x > 150 && y > 223 && tile[2][0].empty())
	{
		tile[2][0].setSprite(1);
	}
	else
	{
		if (tile[2][0].empty())
		{
			tile[2][0].setSprite(3);
		}
	}

	/*
	[ ][ ][ ]
	[ ][ ][ ]
	[ ][*][ ]
	*/
	if (x < 280 && y < 269 && x > 218 && y > 223 && tile[2][1].empty())
	{
		tile[2][1].setSprite(1);
	}
	else
	{
		if (tile[2][1].empty())
		{
			tile[2][1].setSprite(3);
		}
	}

	/*
	[ ][ ][ ]
	[ ][ ][ ]
	[ ][ ][*]
	*/
	if (x < 344 && y < 265 && x > 288 && y > 219 && tile[2][2].empty())
	{
		tile[2][2].setSprite(1);
	}
	else
	{
		if (tile[2][2].empty())
		{
			tile[2][2].setSprite(3);
		}
	}
}

bool Board::isFull()
{
	bool full = true;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tile[i][j].empty())
			{
				full = false;
			}
		}
	}

	return full;
}

void Board::clear()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tile[i][j].setLetter('n');
		}
	}
}

int Board::checkWinner()
{
	// check col
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j += 3)
		{
			if (tile[i][j].getLetter() == 'O' &&
				tile[i][j + 1].getLetter() == 'O' &&
				tile[i][j + 2].getLetter() == 'O')
			{
				return 1;
			}
			else if (tile[i][j].getLetter() == 'X' &&
					 tile[i][j + 1].getLetter() == 'X' &&
					 tile[i][j + 2].getLetter() == 'X')
			{
				return 2;
			}
		}
	}

	// check row
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j += 3)
		{
			if (tile[j][i].getLetter() == 'O' &&
				tile[j + 1][i].getLetter() == 'O' &&
				tile[j + 2][i].getLetter() == 'O')
			{
				return 1;
			}
			else if (tile[j][i].getLetter() == 'X' &&
				     tile[j + 1][i].getLetter() == 'X' &&
				     tile[j + 2][i].getLetter() == 'X')
			{
				return 2;
			}
		}
	}

	// check 1st diagonal
	if (tile[2][0].getLetter() == 'O' &&
		tile[1][1].getLetter() == 'O' &&
		tile[0][2].getLetter() == 'O')
	{
		return 1;
	}
	else if (tile[2][0].getLetter() == 'X' &&
		   	 tile[1][1].getLetter() == 'X' &&
			 tile[0][2].getLetter() == 'X')
	{
		return 2;
	}

	// check 2nd diagonal
	if (tile[0][0].getLetter() == 'O' &&
		tile[1][1].getLetter() == 'O' &&
		tile[2][2].getLetter() == 'O')
	{
		return 1;
	}
	else if (tile[0][0].getLetter() == 'X' &&
		     tile[1][1].getLetter() == 'X' &&
		     tile[2][2].getLetter() == 'X')
	{
		return 2;
	}

	// 0 indicates no winner found
	return 0;
}

int Board::getCrossingPos()
{
	// check col
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j += 3)
		{
			if (tile[i][j].getLetter() == 'O' &&
				tile[i][j + 1].getLetter() == 'O' &&
				tile[i][j + 2].getLetter() == 'O')
			{
				return i + 1;
			}
			else if (tile[i][j].getLetter() == 'X' &&
				tile[i][j + 1].getLetter() == 'X' &&
				tile[i][j + 2].getLetter() == 'X')
			{
				return i + 1;
			}
		}
	}

	// check row
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j += 3)
		{
			if (tile[j][i].getLetter() == 'O' &&
				tile[j + 1][i].getLetter() == 'O' &&
				tile[j + 2][i].getLetter() == 'O')
			{
				return i + 4;
			}
			else if (tile[j][i].getLetter() == 'X' &&
			 		tile[j + 1][i].getLetter() == 'X' &&
			   		tile[j + 2][i].getLetter() == 'X')
			{
				return i + 4;
			}
		}
	}

	// check 1st diagonal
	if (tile[2][0].getLetter() == 'O' &&
		tile[1][1].getLetter() == 'O' &&
		tile[0][2].getLetter() == 'O')
	{
		return 0;
	}
	else if (tile[2][0].getLetter() == 'X' &&
	 		 tile[1][1].getLetter() == 'X' &&
	         tile[0][2].getLetter() == 'X')
	{
		return 0;
	}

	// check 2nd diagonal
	if (tile[0][0].getLetter() == 'O' &&
		tile[1][1].getLetter() == 'O' &&
		tile[2][2].getLetter() == 'O')
	{
		return 0;
	}
	else if (tile[0][0].getLetter() == 'X' &&
			 tile[1][1].getLetter() == 'X' &&
			 tile[2][2].getLetter() == 'X')
	{
		return 0;
	}

	// 0 indicates no winner found
	return 0;
}

Board::~Board()
{
}
