#pragma once
#include <ctime>
#include <cstdlib>
#include <map>
#include <windows.h>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

struct Position {
	int x;
	int y;
	Position(int column = 0, int row = 0): x(column), y(row) {}
};

void setcolor(unsigned int color, unsigned int background_color);