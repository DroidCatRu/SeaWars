#include "pch.h"
#include "aiplayer.h"


aiplayer::aiplayer() {}


aiplayer::~aiplayer() {}

Position aiplayer::getShoot() {
	Position p;
	if (recpool.size() == 0) {
		p.x = rand() % 10;
		p.y = rand() % 10;
	}
	else {
		int s = recpool.size() - 1;
		p = recpool.at(s);
		recpool.pop_back();
	}
	return p;
}

void aiplayer::wounded(int y, int x) {
	if (recpool.size() == 0) {
		Position p;
		if (y > 0) {
			p.x = x;
			p.y = y - 1;
			recpool.push_back(p);
		}
		if (y < 9) {
			p.x = x;
			p.y = y + 1;
			recpool.push_back(p);
		}
		if (x > 0) {
			p.x = x - 1;
			p.y = y;
			recpool.push_back(p);
		}
		if (x < 9) {
			p.x = x + 1;
			p.y = y;
			recpool.push_back(p);
		}
	}
}