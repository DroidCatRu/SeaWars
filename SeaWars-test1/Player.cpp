#include "pch.h"
#include "Player.h"


Player::Player() {
	shipscount = 10;
	shootsuccess = false;
	lastpcshoot = NULL;
	lastshootsuccess = NULL;
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

Ship Player::getShip(int i) {
	return board.getShip(i);
}
