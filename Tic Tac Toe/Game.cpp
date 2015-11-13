#include "Game.h"

/***************************************************
 * Default Constructor
 * -------------------
 * Initiailizes window and renderer pointers to NULL
 ***************************************************/
Game::Game()
{
	// initialize
	window = NULL;
	renderer = NULL;

	round = 1;
	playerScore = 0;
	cpuScore = 0;
	numTies = 0;

	waitTime = 0.0;

	// SDL system
	init();
}

/***************************************************
 * Destructor
 * ----------
 * Destroys the application's window and its renderer
 ***************************************************/
Game::~Game()
{
	// destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	// destroy renderer
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	// quit
	SDL_Quit();
}

/******************************************************
 * GAME LOOP
 *
 * A game loop runs continuously during gameplay. Each 
 * turn of the loop, it processes user input without
 * blocking, updates the game state, and renders the 
 * game. It tracks the passage of time to control the 
 * rate of gameplay.
 *
 * Taken from: 
 * http://gameprogrammingpatterns.com/game-loop.html
 *
 * PSEUDOCODE:
 *
 * WHILE NOT ENDED
 *    PROCESS USER INPUT
 *    "UPDATE" GAME LOGIC/VALUES
 *    "DRAW" CHANGES
 * END
 ******************************************************/
void Game::start()
{
	// flag
	bool ended = false;

	float oldTime = SDL_GetTicks() / 1000.f;

	// the main loop!
	while (!ended)
	{
		// Update the timing information
		float currentTime = SDL_GetTicks() / 1000.f;
		float elapsedTime = currentTime - oldTime;

		processInput(ended);
		update(elapsedTime);
		draw();

		oldTime = currentTime;
	}
}

void Game::processInput(bool &ended)
{
	// mouse pos
	int x;
	int y;

	// process input & event
	while (SDL_PollEvent(&event))
	{
		// QUIT
		if (event.type == SDL_QUIT)
		{
			ended = true;
		}
		// MOUSE BUTTON DOWN
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			// left button is pressed
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseInput.setButtonLeft(true);
			}
		}
		// MOUSE BUTTON UP
		else if (event.type == SDL_MOUSEBUTTONUP)
		{
			// left button is released
			if (event.button.button = SDL_BUTTON_LEFT)
			{
				mouseInput.setButtonLeft(false);
			}
		}
		// MOUSE MOTION
		else if (event.type == SDL_MOUSEMOTION)
		{
			SDL_GetMouseState(&x, &y);
			mouseInput.setMousePos(x, y);
		}
	}
}

// MAGIC HAPPENS HERE!
void Game::update(float ftime)
{
	// keep track of mouse events
	int mX = mouseInput.getMousePosX(); // cursor hori position
	int mY = mouseInput.getMousePosY(); // cursor verti position
	bool leftBtnPressed = mouseInput.getButtonLeft(); // left button press
	bool isOnBoard = board.isOnBoard(mX, mY); // cursor position on tile
	
	// reset values after 3rd round
	if (round == 4)
	{
		// return to initial valuses;
		round = 1;
		playerScore = 0;
		cpuScore = 0;
		numTies = 0;
	}
	
	// set the game's values to our board
	board.setRound(round);             // game round
	board.setPlayerScore(playerScore); // player's score
	board.setCpuScore(cpuScore);       // CPU's score
	board.setNumTies(numTies);         // a number of tie games
	board.setCrossingLine(0);          // crossing line

	// if board isn't full and no winner is found, update the game
	if (!board.isFull() && board.checkWinner() == 0)
	{
		// Human's turn!
		if (player.isHuman())
		{
			// set hover on each tiles based on user's mouse cursor position
			board.setSprite(mX, mY);

			if (leftBtnPressed && isOnBoard)
			{
				// set the tile based on mouse pos
				board.setTile(mX, mY);

				// cpu turn now
				player.setAsHumanTurn(false);
			}
		}
		// AI's turn!
		else
		{
			// cpu (palyer) will set the tile for us
			board.setTile(player);

			// player's turn!
			player.setAsHumanTurn(true);
		}
	}
	// if board is full and a winner is found, then it means the round is over w/ a winner
	else if (board.isFull() && board.checkWinner() != 0)
	{
		waitTime += ftime;
	
		// get the position of where we have to cross out
		int n = board.getCrossingPos();
		// set the crossing line in the appropriate position
		board.setCrossingLine(n);

		// wait..
		if (int(waitTime) == 2)
		{
			// check before the board gets cleared
			if (board.checkWinner() == 1)
			{
				playerScore++;
			}
			else if (board.checkWinner() == 2)
			{
				cpuScore++;
			}

			board.clear(); // clear the board
			player.setAsHumanTurn(true); // human's turn
			round++; // increment the round

			waitTime = 0;
		}
	}
	// if board isn't full and a winner is found, then it means the round is over w/ a winner
	else if (!board.isFull() && board.checkWinner() != 0)
	{
		waitTime += ftime;

		int n = board.getCrossingPos();
		board.setCrossingLine(n);
		// wait
		if (int(waitTime) == 2)
		{
			// check before the board gets cleared
			if (board.checkWinner() == 1)
			{
				playerScore++;
			}
			else if (board.checkWinner() == 2)
			{
				cpuScore++;
			}

			board.clear();
			player.setAsHumanTurn(true);
			round++;

			waitTime = 0;
		}
	}
	// if board is full and winner isn't found, then it means the round is tied
	else
	{
		numTies++;
		board.clear();
		player.setAsHumanTurn(true);
		round++;
	}
}

void Game::draw()
{
	// board has everything that needs to be drawn
	board.draw();
	// now show it on the screen
	SDL_RenderPresent(renderer);
}

/***************************************************
 * Init
 * ----
 * The function first initializes SDL system. If it's
 * initialized, it would create window for the app.
 * If window is created, then it would create a surface
 * and fill the surface with solid color. Then, it will
 * create a texture using the surface. 
 ***************************************************/
void Game::init()
{
	 /* 
		Initialize SDL. If the function retuns -1, 
		then it means it failed to initialize.
	 */
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) 
	{
		// print error and halt
		fprintf(stderr, "\nUnable to initialize SDL: %S\n");
		return;
	}
	// if it succeed initializing SDL
	else
	{
		// create window
		window = SDL_CreateWindow(
			                      "Tic Tac Toe",          // title: "Tic Tac Toe"
			                      SDL_WINDOWPOS_CENTERED, // x position: center
			                      SDL_WINDOWPOS_CENTERED, // y position: center
			                      640,                    // width: 640
			                      452,                    // height: 452
			                      SDL_WINDOW_SHOWN        // flag: window is visible
		                         );

		// if window is NULL, it means it failed to create window
		if (window == NULL)
		{
			// print error and halt
			printf("Could not create window: %s\n", SDL_GetError());
			return;
		}
		// created window
		else
		{
			// create renderer
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;

			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				return;
			}

			board.setRenderer(renderer);
		}
	}
}
