#pragma once
#include "utils.h"
#include <vector>

using namespace std;
enum direction { h, v };

class Ship {
private:
	Position coordinates;
	unsigned size;
	direction dir;
	vector<Position> cells;
	vector<bool> status;
	bool killed;
public:
	Ship(Position &pos, int length, char direct);
	Position getPos();
	direction getDir();
	int getSize();
	direction setDir(char direct);
	~Ship();
};

