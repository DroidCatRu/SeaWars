#include "pch.h"
#include "cell.h"


cell::cell() {
	empty = false;
	unknown = true;
	killed = false;
	ship = false;
	visible = false;
}


cell::~cell() {
}

void cell::initEmpty() {
	empty = true;
	unknown = false;
	ship = false;
}

void cell::initShip() {
	ship = true;
	unknown = false;
	empty = false;
}

void cell::initVisible() {
	visible = true;
}

bool cell::isEmpty() {
	return empty;
}

bool cell::isShooted() {
	return !unknown;
}

bool cell::isShip() {
	return ship;
}

bool cell::isKilled() {
	return killed;
}

void cell::setKilled() {
	killed = true;
}

char cell::getStatus() {
	if (visible) {
		if (ship) {
			if (killed) {
				return 'O';
			}
			else {
				return 'X';
			}
		}
		else if (empty) {
			return '*';
		}
	}
	return '+';
}