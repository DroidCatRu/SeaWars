#include "pch.h"
#include "ship.h"


Ship::Ship(Position &pos, int length, char direct): coordinates(pos), size(length), dir(setDir(direct)) {
	killed = 0;
}

direction Ship::setDir(char direct) {
	if (direct == 'h' || direct == 'H') {
		return h;
	}
	else if (direct == 'v' || direct == 'V') {
		return v;
	}
	return v;
}

Position Ship::getPos() {
	return coordinates;
}
direction Ship::getDir() {
	return dir;
}
int Ship::getSize() {
	return size;
}

Ship::~Ship() {

}
