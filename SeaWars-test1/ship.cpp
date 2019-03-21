#include "pch.h"
#include "ship.h"


Ship::Ship(Position &pos, int length, char direct): coordinates(pos), size(length), dir(setDir(direct)) {
	killed = false;
	for (unsigned i = 0; i < size; i++) {
		Position pi = pos;
		if (dir == h) {
			pi.x = pos.x + i;
			pi.y = pos.y;
		}
		else {
			pi.x = pos.x;
			pi.y = pos.y + i;
		}
		cells.push_back(pi);
		status.push_back(true);
	}
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
