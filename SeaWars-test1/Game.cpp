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
		for (int f = count; f >= 1; --f) {
			showboards();
			cout << "Let's launch your " << size << "-size ship" << endl;
			if (size > 1) {
				cout << "Enter position of the first cell (for example, A2) of ship and direction (h or v):" << endl;
			}
			else {
				cout << "Enter position of cell (for example, A2):" << endl;
			}

			char direct = 'v';
			char x = 'a';
			int y = 1;
			cin >> x >> y;
			if (x < 'a' || x > 'j' || y < 1 || y > 10) {
				cout << "Try again" << endl;
				cin.clear();
				++f;
			}
			else {
				Position pi;
				pi.y = y - 1;
				if (x >= 'a' && x <= 'j') {
					pi.x = x - 'a';
				}
				else if (x >= 'A' && x <= 'J') {
					pi.x = x - 'A';
				}
				if (size > 1) {
					cin >> direct;
					if (direct != 'h' && direct != 'H' && direct != 'v' && direct != 'V') {
						cout << "You entered not right direction, ship will be launched automatically in vertical position" << endl;
						direct = 'v';
					}
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
}

void Game::initpcboard() {

}

void Game::showboards() {
	system("CLS");
	cout << "It's your board and board of your enemy\n";
	cout << "  ";
	for (char i = 'A'; i <= 'A' + 9; i++) {
		setcolor(WHITE, BLACK);
		cout << setw(2) << i;
	}
	/*cout << "     ";
	for (char i = 'A'; i <= 'A' + 9; i++) {
		cout << setw(2) << i;
	}*/
	cout << endl;

	for (int i = 0; i < 10; i++) {
		setcolor(WHITE, BLACK);
		cout << setw(2) << i + 1;
		for (int g = 0; g < 10; g++) {
			if (player.getBoardStatus(i, g) == 'X' || player.getBoardStatus(i, g) == 'x') {
				setcolor(RED, BLACK);
				cout << setw(2) << player.getBoardStatus(i, g);
				setcolor(WHITE, BLACK);
			}
			else {
				setcolor(WHITE, BLACK);
				cout << setw(2) << player.getBoardStatus(i, g);
			}
			
		}

		/*cout << setw(5) << i + 1;
		for (int g = 0; g < 10; g++) {
			cout << setw(2) << player.getBoardStatus(i, g);
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
