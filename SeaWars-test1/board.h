#pragma once
#include "cell.h"
#include "ship.h"
#include <vector>
#include <iostream>

using namespace std;

class Board {
private:
	vector<Ship> ships;
	vector< vector<cell> > gameboard;
public:
	void launch_ship(Ship &ship);
	bool can_launch_ship(int column, int row, direction direction, int size);
	bool shipIsOnBoard(int column, int row, direction direction, int size);
	bool shipIsNear();
	char getCellStatus(int i, int g);
	void show();
	Board();
	~Board();
};

