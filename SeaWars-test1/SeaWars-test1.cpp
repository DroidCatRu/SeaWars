#include "pch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Game.h"
#include "Player.h"

using namespace std;

int main() {
	srand((int)time(NULL));
	Game game;

	while (1) {
		game.start();
		game.initplayersboard();
		game.initpcboard();
		bool gameover = false;
		while (!gameover) {
			gameover = game.over();
			while(1) {
				if (!game.playershoot()) {
					break;
				}
				if (game.over()) {
				gameover = true;
				break;
				}
			}
			if(gameover) {
				break;
			}
			
			while(1) {
				if (!game.pcshoot()) {
					break;
				}
				if (game.over()) {
				gameover = true;
				break;
				}
			}
			if(gameover) {
				break;
			}
		}

		game.end();
		
		if (!game.again()) {
			return 0;
		}
	}
}
