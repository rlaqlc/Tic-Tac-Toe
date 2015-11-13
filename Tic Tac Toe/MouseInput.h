#pragma once
class MouseInput
{
public:
	MouseInput();
	// left button
	void setButtonLeft(bool isButtonLeft);
	bool getButtonLeft() const;
	// right button
	void setButtonRight(bool isButtonRight);
	bool getButtonRight() const;
	// button up
	void setButtonUp(bool isButtonUp);
	bool getButtonUp() const;
	// button down
	void setButtonDown(bool isButtonDown);
	bool getButtonDown() const;
	// mouse position
	void setMousePos(int x, int y);
	int getMousePosX() const;
	int getMousePosY() const;
	// reset the values to initial values
	void reset();
	~MouseInput();
private:
	bool isButtonLeft;
	bool isButtonRight;
	bool isButtonUp;
	bool isButtonDown;
	int x;
	int y;
};

