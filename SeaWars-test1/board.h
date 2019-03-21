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
	void launch_ship(Ship &ship, bool visible);
	bool can_launch_ship(int column, int row, direction direction, int size);
	bool shipIsOnBoard(int column, int row, direction direction, int size);
	bool shipIsNear(int column, int row, direction direction, int size);
	char getCellStatus(int i, int g);
	void initVisible(int i, int g);
	Board();
	~Board();
};

