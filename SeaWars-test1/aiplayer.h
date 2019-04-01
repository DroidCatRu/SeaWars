#pragma once
#include "Player.h"

class aiplayer : public Player{
private:
	vector<Position> recpool;
public:
	Position getShoot();
	void wounded(int y, int x);
	aiplayer();
	~aiplayer();
};

