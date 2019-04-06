#pragma once
#include "Player.h"
#include "aiplayer.h"
#include "ship.h"
#include "utils.h"

class Game {
private:
	Player player;
	aiplayer pc;
public:
	void start();
	void end();
	bool over();
	bool pcHasShips();
	bool playerHasShips();
	void initplayersboard();
	void initpcboard();
	void showShipPerimeter(Ship ship, bool p);
	void showboards();
	bool playershoot();
	bool pcshoot();
	bool again();
	Game();
	~Game();
};

