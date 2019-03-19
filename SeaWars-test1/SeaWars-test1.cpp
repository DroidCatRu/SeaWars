// SeaWars-test1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include "Game.h"
#include "Player.h"

using namespace std;

/*void show_board(cell board[10][10]) {
	system("CLS");
	cout << "It's your board and board of your enemy\n";
	cout << "   ";
	for (char i = 'A'; i <= 'A' + 9; i++) {
		cout << setw(3) << i;
	}
	cout << "     ";
	for (char i = 'A'; i <= 'A' + 9; i++) {
		cout << setw(3) << i;
	}
	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << setw(3) << i + 1;
		for (int g = 0; g < 10; g++) {
			cout << setw(3) << board[g][i].getStatus();
		}

		cout << setw(5) << i + 1;
		for (int g = 0; g < 10; g++) {
			cout << setw(3) << board[g][i].getStatus();
		}

		cout << endl;
	}
}*/

int main() {
	/*cell board[10][10];
	show_board(board);
	int x, y, len;
	char dir;
	cout << "Enter x, y, length and direction(h or v)" << endl;
	cin >> x >> y >> len >> dir;
	ship ship1(x, y, len, dir);
	for (;;) {
		int x, y;
		cin >> x >> y;
		int state = rand() % 2 + 1;
		if (state == 1) {
			board[x - 1][y - 1].setShooted();
		}
		else {
			board[x - 1][y - 1].setEmpty();
		}
		show_board(board);
	}*/

	Game game;

	game.start();
	game.initplayersboard();
	game.initpcboard();
	game.showboards();

	/*while (1) {
		game.start();
		game.initplayersboard();
		game.initpcboard();
		game.showboards();
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
