#include "pch.h"
#include "Game.h"
#include <iostream>
#include <iomanip>

using namespace std;

Game::Game() {

}


Game::~Game() {

}

void Game::start() {
	player.resetShipsCount();
	pc.resetShipsCount();
}

void Game::end() {
	if (!pc.hasShips()) {
		cout << "You win!" << endl;
	}
	else {
		cout << "You lost!" << endl;
	}
}

bool Game::over() {
	if (!player.hasShips() || !pc.hasShips()) {
		return true;
	}
	else {
		return false;
	}
}

bool Game::pcHasShips() {
	if (pc.hasShips()) {
		return true;
	}
	else {
		return false;
	}
}

bool Game::playerHasShips() {
	if (player.hasShips()) {
		return true;
	}
	else {
		return false;
	}
}

void Game::initplayersboard() {
	for (int size = 4, count = 1; size >= 1, count <= 4; size--, count++) {
		for (int f = count; f >= 1; f--) {
			cout << "Let's launch your " << size << "-size ship" << endl;
			cout << "Enter position of the first cell (for example, A2) of ship and direction (h or v):" << endl;
			Position pi;
			char x;
			int y;
			cin >> x >> y;
			pi.y = y - 1;
			if (x >= 'a' && x <= 'j') {
				pi.x = x - 'a';
			}
			else if (x >= 'A' && x <= 'J') {
				pi.x = x - 'A';
			}
			char direct;
			cin >> direct;
			if (direct != 'h' && direct != 'H' && direct != 'v' && direct != 'V') {
				cout << "You entered not right direction, ship will be launched automatically in vertical position" << endl;
			}
			Ship ship(pi, size, direct);
			if (player.can_launch_ship(pi.x, pi.y, ship.getDir(), size)) {
				player.launch_ship(ship);
			}
			else {
				cout << "You can't launch ship here" << endl;
				f++;
			}
		}
	}
}

void Game::initpcboard() {

}

void Game::showboards() {
	system("CLS");
	cout << "It's your board and board of your enemy\n";
	cout << "   ";
	for (char i = 'A'; i <= 'A' + 9; i++) {
		cout << setw(3) << i;
	}
	/*cout << "     ";
	for (char i = 'A'; i <= 'A' + 9; i++) {
		cout << setw(3) << i;
	}*/
	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << setw(3) << i + 1;
		for (int g = 0; g < 10; g++) {
			cout << setw(3) << player.getBoardStatus(i, g);
		}

		/*cout << setw(5) << i + 1;
		for (int g = 0; g < 10; g++) {
			cout << setw(3) << player.getBoardStatus(i, g);
		}*/

		cout << endl;
	}
}

void Game::pcshoot() {

}

void Game::playershoot() {

}

bool Game::again() {
	char answer = 0;
	do {
		cout << "Do U wanna play again?" << endl;
		cin >> answer;
	} while (answer != 'n' && answer != 'N' && answer != 'y' && answer != 'Y');
	if (answer == 'n' || answer == 'N') {
		return false;
	}
	else {
		return true;
	}
}
