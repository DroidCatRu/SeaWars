#include "pch.h"
#include "Player.h"


Player::Player() {

}


Player::~Player() {

}

void Player::launch_ship(Ship &ship) {
	board.launch_ship(ship);
}

bool Player::can_launch_ship(int column, int row, char direction, int size) {
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

void Player::decrementShipsCount() {
	shipscount--;
}
