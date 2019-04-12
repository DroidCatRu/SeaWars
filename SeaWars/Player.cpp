#include "pch.h"
#include "Player.h"


Player::Player() {
	shipscount = 10;
	score = 0;
}

Player::~Player() {

}

void Player::launch_ship(Ship &ship, bool visible) {
	board.launch_ship(ship, visible);
}

bool Player::can_launch_ship(int column, int row, direction direction, int size) {
	if(board.can_launch_ship(column, row, direction, size))
		return true;
	else
		return false;
}

char Player::getBoardStatus(int i, int g) {
	return board.getCellStatus(i, g);
}

bool Player::hasShips() {
	if (shipscount > 0) {
		return true;
	}
	else
		return false;
}

void Player::resetShipsCount() {
	shipscount = 10;
}

int Player::getShipsCount() {
	return shipscount;
}

void Player::decrementShipsCount() {
	shipscount--;
}

void Player::initVisible(int i, int g) {
	board.initVisible(i, g);
}

int Player::setKilled(int i, int g) {
	int f = board.setKilled(i, g);
	if (f != -1) {
		decrementShipsCount();
	}
	return f;
}

int Player::ShipsLeft(int size) {
	return board.ShipsLeft(size);
}

Ship Player::getShip(int i) {
	return board.getShip(i);
}

void Player::showShipPerimeter(Ship ship) {
	direction direction = ship.getDir();
	int row = ship.getPos().y;
	int column = ship.getPos().x;
	int size = ship.getSize();


	if (direction == h) {

		//vertical checking
		if (row - 1 < 0) {
			for (uint16_t j = 0; j < size; j++) {
				initVisible(column + j, row + 1);
			}
		}
		else if (row + 1 > 9) {
			for (uint16_t j = 0; j < size; j++) {
				initVisible(column + j, row - 1);
			}
		}
		else {
			for (uint16_t j = 0; j < size; j++) {
				initVisible(column + j, row - 1);
				initVisible(column + j, row + 1);
			}
		}

		//horizontal checking
		if (column - 1 < 0) {
			initVisible(column + size, row);
		}
		else if (column + size > 9) {
			initVisible(column - 1, row);
		}
		else {
			initVisible(column + size, row);
			initVisible(column - 1, row);
		}

		//diagonal checking
		//top left corner
		if (row - 1 < 0 && column - 1 < 0) {
			initVisible(column + size, row + 1);
		}
		//top right corner
		else if (row - 1 < 0 && column + size > 9) {
			initVisible(column - 1, row + 1);
		}
		//bottom left corner
		else if (row + 1 > 9 && column - 1 < 0) {
			initVisible(column + size, row - 1);
		}
		//bottom right corner
		else if (row + 1 > 9 && column + size > 9) {
			initVisible(column - 1, row - 1);
		}
		//left border of the field
		else if (column - 1 < 0 && row >= 0 && row <= 9) {
			initVisible(column + size, row - 1);
			initVisible(column + size, row + 1);
		}
		//right border of the field
		else if (column + size > 9 && row >= 0 && row <= 9) {
			initVisible(column - 1, row - 1);
			initVisible(column - 1, row + 1);
		}
		//top border of the field
		else if (row - 1 < 0 && column - 1 >= 0 && column + size <= 9) {
			initVisible(column - 1, row + 1);
			initVisible(column + size, row + 1);
		}
		//bottom border of the field
		else if (row + 1 > 9 && column - 1 >= 0 && column + size <= 9) {
			initVisible(column - 1, row - 1);
			initVisible(column + size, row - 1);
		}
		//not in the corner and not near the border of the field
		else {
			initVisible(column + size, row - 1);
			initVisible(column + size, row + 1);
			initVisible(column - 1, row + 1);
			initVisible(column - 1, row - 1);
		}
	}
	else {
		//vertical checking
		if (row - 1 < 0) {
			initVisible(column, row + size);
		}
		else if (row + size > 9) {
			initVisible(column, row - 1);
		}
		else {
			initVisible(column, row - 1);
			initVisible(column, row + size);
		}

		//horizontal checking
		if (column - 1 < 0) {
			for (uint16_t j = 0; j < size; j++) {
				initVisible(column + 1, row + j);
			}
		}
		else if (column + 1 > 9) {
			for (uint16_t j = 0; j < size; j++) {
				initVisible(column - 1, row + j);
			}
		}
		else {
			for (uint16_t j = 0; j < size; j++) {
				initVisible(column + 1, row + j);
				initVisible(column - 1, row + j);
			}
		}

		//diagonal checking
		//top left corner
		if (row - 1 < 0 && column - 1 < 0) {
			initVisible(column + 1, row + size);
		}
		//top right corner
		else if (row - 1 < 0 && column + 1 > 9) {
			initVisible(column - 1, row + size);
		}
		//bottom left corner
		else if (row + size > 9 && column - 1 < 0) {
			initVisible(column + 1, row - 1);
		}
		//bottom right corner
		else if (row + size > 9 && column + 1 > 9) {
			initVisible(column - 1, row - 1);
		}
		//left border of the field
		else if (column - 1 < 0 && row - 1 >= 0 && row + size <= 9) {
			initVisible(column + 1, row - 1);
			initVisible(column + 1, row + size);
		}
		//right border of the field
		else if (column + 1 > 9 && row - 1 >= 0 && row + size <= 9) {
			initVisible(column - 1, row - 1);
			initVisible(column - 1, row + size);
		}
		//top border of the field
		else if (row - 1 < 0 && column - 1 >= 0 && column + 1 <= 9) {
			initVisible(column - 1, row + size);
			initVisible(column + 1, row + size);
		}
		//bottom border of the field
		else if (row + size > 9 && column - 1 >= 0 && column + 1 <= 9) {
			initVisible(column - 1, row - 1);
			initVisible(column + 1, row - 1);
		}
		//not in the corner
		else {
			initVisible(column - 1, row - 1);
			initVisible(column + 1, row - 1);
			initVisible(column - 1, row + size);
			initVisible(column + 1, row + size);
		}
	}
}

void Player::increaseScore() {
	score++;
}
int Player::getScore() {
	return score;
}