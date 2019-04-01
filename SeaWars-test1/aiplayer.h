#pragma once
#include "Player.h"
enum stage {one, two, three, unknown};

class aiplayer : public Player {
private:
	vector<Position> recpool;
	Position firstshoot;
	bool shipdetected;
	bool dirdetected;
	direction dir;
	stage stage;
	vector<Position> cellsleft;
public:
	Position getShoot();
	void shipKilled(Ship ship);
	void wounded(int y, int x);
	void removecell(int x, int y);
	void removeShipPerimeter(Ship ship);
	void empty(int y, int x);
	aiplayer();
	~aiplayer();
};

