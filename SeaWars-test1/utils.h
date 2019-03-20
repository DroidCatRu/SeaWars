#pragma once
#include <ctime>
#include <cstdlib>
#include <map>
#include <windows.h>

struct Position {
	int x;
	int y;
	Position(int row = 0, int column = 0): x(column), y(row) {}
};
class utils
{
public:
	utils();
	~utils();
};

void setcolor(unsigned int color, unsigned int background_color);