#include "Player.h"



Player::Player()
{
	human = true;
}

void Player::setAsHumanTurn(bool human)
{
	this->human = human;
}

// returns 0, 1, or 2 upon request
int Player::getCpuColValue()
{
	return (rand() % 3 + 0);
}

// retuns 0, 1, or 2 upon reqeust
int Player::getCpuRowValue()
{
	return (rand() % 3 + 0);
}

// if its cpu, it returns true
bool Player::isHuman() const
{
	return human;
}


Player::~Player()
{
}
