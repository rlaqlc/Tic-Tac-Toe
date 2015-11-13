#include "MouseInput.h"



MouseInput::MouseInput()
{
	isButtonLeft = false;
	isButtonRight = false;
	isButtonUp = false;
	isButtonDown = false;
}

void MouseInput::setButtonLeft(bool isButtonLeft)
{
	this->isButtonLeft = isButtonLeft;
}

bool MouseInput::getButtonLeft() const
{
	return isButtonLeft;
}

void MouseInput::setButtonRight(bool isButtonRight)
{
	this->isButtonRight = isButtonRight;
}

bool MouseInput::getButtonRight() const
{
	return isButtonRight;
}

void MouseInput::setButtonUp(bool isButtonUp)
{
	this->isButtonUp = isButtonUp;
}

bool MouseInput::getButtonUp() const
{
	return isButtonUp;
}

void MouseInput::setButtonDown(bool isButtonDown)
{
	this->isButtonDown = isButtonDown;
}

bool MouseInput::getButtonDown() const
{
	return isButtonDown;
}

void MouseInput::setMousePos(int x, int y)
{
	this->x = x;
	this->y = y;
}

int MouseInput::getMousePosX() const
{
	return x;
}

int MouseInput::getMousePosY() const
{
	return y;
}


void MouseInput::reset()
{
	isButtonLeft = false;
	isButtonRight = false;
	isButtonUp = false;
	isButtonDown = false;
	x = 0;
	y = 0;
}

MouseInput::~MouseInput()
{
}
