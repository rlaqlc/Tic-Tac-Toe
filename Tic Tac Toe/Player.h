#pragma once
#include <cstdlib>
class Player
{
public:
	Player();
	void setAsHumanTurn(bool human);
	int getCpuColValue();
	int getCpuRowValue();
	bool isHuman() const;
	~Player();
private:
	bool human;
};

