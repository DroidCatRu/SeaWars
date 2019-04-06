#pragma once
#include "board.h"
#include "ship.h"

class Player {
protected:
	int shipscount;
	Board board;
	int score;
public:
	void launch_ship(Ship &ship, bool visible);
	bool can_launch_ship(int column, int row, direction direction, int size);
	char getBoardStatus(int i, int g);
	bool hasShips();
	void resetShipsCount();
	void decrementShipsCount();
	int getShipsCount();
	void initVisible(int i, int g);
	void showShipPerimeter(Ship ship);
	int setKilled(int i, int g);
	Ship getShip(int i);
	int getScore();
	void increaseScore();
	Player();
	~Player();
};

