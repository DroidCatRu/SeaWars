#pragma once
#include "Player.h"
#include "ship.h"


class Game
{
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
	void showboards();
	void playershoot();
	void pcshoot();
	bool again();
	Game();
	~Game();
};

