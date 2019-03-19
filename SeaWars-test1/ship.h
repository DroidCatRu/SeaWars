#pragma once
#include "utils.h"
#include <string>

using namespace std;
enum direction { h, v };

class Ship {
private:
	Position coordinates;
	unsigned size;
	direction dir;
	string status;
	bool killed;
public:
	Ship(Position &pos, int length, char direct);
	Position getPos();
	char getDir();
	int getSize();
	direction setDir(char direct);
	~Ship();
};

