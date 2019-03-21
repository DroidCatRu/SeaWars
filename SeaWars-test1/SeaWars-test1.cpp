#include "pch.h"
#include <iostream>
#include <iomanip>
#include "Game.h"
#include "Player.h"

using namespace std;

int main() {

	Game game;

	game.start();
	game.initplayersboard();
	game.initpcboard();

	/*while (1) {
		game.start();
		game.initplayersboard();
		game.initpcboard();
		while (!game.over()) {
			cout << "We're in game!" << endl;
			game.playershoot();
			game.showboards();
			if (!game.pcHasShips()) {
				continue;
			}
			else {
				game.pcshoot();
				game.showboards();
				if (!game.playerHasShips()) {
					continue;
				}
			}
		}

		game.end();
		
		if (!game.again()) {
			return 0;
		}
	}*/
}
