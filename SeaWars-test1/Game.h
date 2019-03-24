#pragma once
#include "Player.h"
#include "ship.h"
#include "utils.h"

class Game {
private:
	Player player, pc;
public:
	void start();
	void end();
	bool over();
	bool pcHasShips();
	bool playerHasShips();
	void initplayersboard();
	void initpcboard();
	void showShipPerimeter(Ship ship, Player &player);
	void showboards();
	bool playershoot();
	bool pcshoot();
	bool again();
	Game();
	~Game();
};

