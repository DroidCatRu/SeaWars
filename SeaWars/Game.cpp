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
	showboards();
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

	cout << "If you wanna complete your board automatically, enter 'a'. Else enter 'm'" << endl;
	char prof;
	cin >> prof;
	if (prof != 'a' && prof != 'm') {
		cout << "You entered not right symbol, complete your board manually" << endl;
		prof = 'm';
	}

	for (int size = 4, count = 1; size >= 1, count <= 4; size--, count++) {
		for (int f = count; f >= 1; --f) {

			if (prof == 'm') {

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
				if (x < 'A' || (x > 'J' && x < 'a') || x > 'j' || y < 1 || y > 10) {
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
						player.launch_ship(ship, true);
					}
					else {
						cout << "You can't launch ship here" << endl;
						f++;
					}

					showboards();
				}
			}
			else {
				char direct = 'v';
				Position pi;

				pi.y = rand() % 10;
				pi.x = rand() % 10;

				if (size > 1) {
					direct = rand() % 2;
					switch (direct) {
					case 0:
						direct = 'v';
						break;
					case 1:
						direct = 'h';
						break;
					}
				}
				Ship ship(pi, size, direct);
				if (player.can_launch_ship(pi.x, pi.y, ship.getDir(), size)) {
					player.launch_ship(ship, true);
				}
				else {
					f++;
				}
			}
		}
	}
	showboards();
}

void Game::initpcboard() {
	for (int size = 4, count = 1; size >= 1, count <= 4; size--, count++) {
		for (int f = count; f >= 1; --f) {

			char direct = 'v';
			Position pi;

			pi.y = rand() % 10;
			pi.x = rand() % 10;
				
			if (size > 1) {
				direct = rand() % 2;
				switch (direct) {
				case 0:
					direct = 'v';
					break;
				case 1:
					direct = 'h';
					break;
				}
			}
			Ship ship(pi, size, direct);
			if (pc.can_launch_ship(pi.x, pi.y, ship.getDir(), size)) {
				pc.launch_ship(ship, false);
			}
			else {
				f++;
			}
		}
	}
	showboards();
}

void print_line(Player &p, int i) {
	for (int g = 0; g < 10; g++) {
		if (p.getBoardStatus(i, g) == 'X' || p.getBoardStatus(i, g) == 'O') {
			setcolor(RED, BLACK);
			cout << setw(2) << p.getBoardStatus(i, g);
		}
		else if (p.getBoardStatus(i, g) == '*') {
			setcolor(BLUE, BLACK);
			cout << setw(2) << p.getBoardStatus(i, g);
		}
		else {
			setcolor(WHITE, BLACK);
			cout << setw(2) << p.getBoardStatus(i, g);
		}
		setcolor(WHITE, BLACK);
	}
}

void Game::showboards() {
	system("CLS");
	//COORD coord{ 0,0 };
	//COORD in{ 0,16 };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "It's your board and board of your enemy\n";
	cout << "  ";
	for (char i = 'A'; i <= 'A' + 9; i++) {
		setcolor(WHITE, BLACK);
		cout << setw(2) << i;
	}
	cout << "     ";
	for (char i = 'A'; i <= 'A' + 9; i++) {
		cout << setw(2) << i;
	}
	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << setw(2) << i + 1;
		print_line(player, i);

		cout << setw(5) << i + 1;
		print_line(pc, i);

		cout << endl;
	}
	cout << endl;
	cout << "Your ships left: " << player.getShipsCount() << ", your score: " << player.getScore() << endl;
	cout << "Enemy ships left: " << pc.getShipsCount() << ", enemy's score: " << pc.getScore() << endl << endl;
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), in);
}

void Game::showShipPerimeter(Ship ship, bool p) {
	
	Player *pl;
	if (p == true)
		pl = &player;
	else
		pl = &pc;

	pl->showShipPerimeter(ship);

}

bool Game::pcshoot() {

	Position pos = pc.getShoot();

	int x = pos.x;
	int y = pos.y;

	pc.removecell(x, y);

	if (player.getBoardStatus(y, x) == 'X') { //live ship cell
		pc.increaseScore();
		int i = player.setKilled(y, x);
		if (i != -1) {
			Ship s = player.getShip(i);
			showShipPerimeter(s, true);
			pc.shipKilled(s);
		}
		else {
			pc.wounded(y, x);
		}
		showboards();
		return true;
	}
	else if (player.getBoardStatus(y, x) == 'O') { //killed ship cell
		showboards();
		return true;
	}
	else if (player.getBoardStatus(y, x) == '+') { //empty cell
		player.initVisible(x, y);
		pc.empty(y, x);
		showboards();
		return false;
	}
	else {
		pc.empty(y, x);
	}
	//shoot again
	showboards();
	return true;
}

bool Game::playershoot() {
	char x = 'a';
	int y = 1;
	cin >> x >> y;

	/*x = 'a' + rand() % 10;
	y = 1 + rand() % 10;*/

	if (x < 'A' || (x > 'J' && x < 'a') || x > 'j' || y < 1 || y > 10) {
		cout << "Try again" << endl;
		cin.clear();
	}
	else {
		y = y - 1;
		if (x >= 'a' && x <= 'j') {
			x = x - 'a';
		}
		else if (x >= 'A' && x <= 'J') {
			x = x - 'A';
		}

		if (pc.getBoardStatus(y, x) == '+') {
			pc.initVisible(x, y);
			if (pc.getBoardStatus(y, x) == 'X') { //live ship cell
				player.increaseScore();
				int i = pc.setKilled(y, x);
				if (i != -1) {
					Ship s = pc.getShip(i);
					showShipPerimeter(s, false);
				}
				showboards();
				return true;
			}
			else if (pc.getBoardStatus(y, x) == 'O') { //killed ship cell
				showboards();
				return true;
			}
			else if(pc.getBoardStatus(y, x) == '*') { //empty cell
				showboards();
				return false;
			}
		}
		//shoot again
	}
	showboards();
	return true;
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
