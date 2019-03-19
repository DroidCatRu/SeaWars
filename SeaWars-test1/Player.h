#pragma once
#include "board.h"
#include "ship.h"

class Player {
private:
	int shipscount = 10;
	Board board;
public:
	void launch_ship(Ship &ship);
	bool can_launch_ship(int column, int row, char direction, int size);
	char getBoardStatus(int i, int g);
	bool hasShips();
	void resetShipsCount();
	void decrementShipsCount();
	Player();
	~Player();
};

