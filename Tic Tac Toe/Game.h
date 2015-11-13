#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include "MouseInput.h"
#include "Board.h"
#include "Player.h"

using namespace std;

class Game
{
public:
	Game();
	void start();
	~Game();
private:
	void init();
	void processInput(bool &isEnded);
	void update(float ftime);
	void draw();
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Event event;
	MouseInput mouseInput;
	Board board;
	Player player;
	int round;
	int numTies;
	int playerScore;
	int cpuScore;
	float waitTime;
};

