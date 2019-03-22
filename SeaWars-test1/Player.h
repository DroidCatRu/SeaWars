#pragma once
#include "board.h"
#include "ship.h"

class Player {
private:
	int shipscount = 10;
	Board board;
public:
	void launch_ship(Ship &ship, bool visible);
	bool can_launch_ship(int column, int row, direction direction, int size);
	char getBoardStatus(int i, int g);
	bool hasShips();
	void resetShipsCount();
	void decrementShipsCount();
	void initVisible(int i, int g);
	void setKilled(int i, int g);
	Player();
	~Player();
};

