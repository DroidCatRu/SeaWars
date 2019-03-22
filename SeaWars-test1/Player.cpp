#include "pch.h"
#include "Player.h"


Player::Player() {

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

void Player::decrementShipsCount() {
	shipscount--;
}

void Player::initVisible(int i, int g) {
	board.initVisible(i, g);
}

void Player::setKilled(int i, int g) {
	board.setKilled(i, g);
}
