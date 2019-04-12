#include "pch.h"
#include "aiplayer.h"


aiplayer::aiplayer() {
	shipdetected = false;
	dirdetected = false;
	stage = unknown;
	for (int i = 0; i < 10; i++) {
		for (int g = 0; g < 10; g++) {
			Position p;
			p.y = i;
			p.x = g;
			cellsleft.push_back(p);
		}
	}
}

aiplayer::~aiplayer() {}

Position aiplayer::getShoot() {
	Position p;
	int s = cellsleft.size();
	p = cellsleft.at(rand() % s);
	recpool.shrink_to_fit();
	if (recpool.size() > 0 && shipdetected) {
		int s = (int)(recpool.size() - 1);
		p = recpool.at(s);
	}
	return p;
}

void aiplayer::wounded(int y, int x) {
	if (!shipdetected) {
		shipdetected = true;
		dirdetected = false;
		firstshoot.x = x;
		firstshoot.y = y;
		stage = one;

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
		return;
	}
	
	if (stage == one) {
		if (firstshoot.x != x) {
			dir = h;
		}
		else if (firstshoot.y != y) {
			dir = v;
		}
		recpool.clear();
		dirdetected = true;
		stage = two;
	}

	if (stage == two) {
			Position p;
			if (dir == h) {
				if (x < firstshoot.x) {
					if (x - 2 >= 0) {
						p.x = x - 2;
						p.y = y;
						recpool.push_back(p);
					}
					if (x - 1 >= 0) {
						p.x = x - 1;
						p.y = y;
						recpool.push_back(p);
					}
					if (firstshoot.x + 2 <= 9) {
						p.x = firstshoot.x + 2;
						p.y = y;
						recpool.push_back(p);
					}
					if (firstshoot.x + 1 <= 9) {
						p.x = firstshoot.x + 1;
						p.y = y;
						recpool.push_back(p);
					}
				}
				else if (x > firstshoot.x) {
					if (firstshoot.x - 2 >= 0) {
						p.x = firstshoot.x - 2;
						p.y = y;
						recpool.push_back(p);
					}
					if (firstshoot.x - 1 >= 0) {
						p.x = firstshoot.x - 1;
						p.y = y;
						recpool.push_back(p);
					}
					if (x + 2 <= 9) {
						p.x = x + 2;
						p.y = y;
						recpool.push_back(p);
					}
					if (x + 1 <= 9) {
						p.x = x + 1;
						p.y = y;
						recpool.push_back(p);
					}
				}
			}
			else if (dir == v) {
				if (y < firstshoot.y) {
					if (y - 2 >= 0) {
						p.y = y - 2;
						p.x = x;
						recpool.push_back(p);
					}
					if (y - 1 >= 0) {
						p.y = y - 1;
						p.x = x;
						recpool.push_back(p);
					}
					if (firstshoot.y + 2 <= 9) {
						p.y = firstshoot.y + 2;
						p.x = x;
						recpool.push_back(p);
					}
					if (firstshoot.y + 1 <= 9) {
						p.y = firstshoot.y + 1;
						p.x = x;
						recpool.push_back(p);
					}
				}
				else if (y > firstshoot.y) {
					if (firstshoot.y - 2 >= 0) {
						p.y = firstshoot.y - 2;
						p.x = x;
						recpool.push_back(p);
					}
					if (firstshoot.y - 1 >= 0) {
						p.y = firstshoot.y - 1;
						p.x = x;
						recpool.push_back(p);
					}
					if (y + 2 <= 9) {
						p.y = y + 2;
						p.x = x;
						recpool.push_back(p);
					}
					if (y + 1 <= 9) {
						p.y = y + 1;
						p.x = x;
						recpool.push_back(p);
					}
				}
			}
			stage = three;
			return;
		}

	if (stage == three && recpool.size() > 0) {
		recpool.pop_back();
		return;
	}
}

void aiplayer::empty(int y, int x) {
	if (stage == one && recpool.size() > 0) {
		recpool.pop_back();
	}
	if (stage == three) {
		if (recpool.size() == 4 && recpool.at(3).x == x && recpool.at(3).y == y) {
			recpool.pop_back();
			recpool.pop_back();
		}
		else if ((recpool.size() == 2 || recpool.size() == 4) && recpool.at(1).x == x && recpool.at(1).y == y) {
			if ((recpool.at(0).x == x + 1) || (recpool.at(0).x == x - 1) || (recpool.at(0).y == y + 1) || (recpool.at(0).y == y - 1)) {
				if (recpool.size() == 2) {
					recpool.pop_back();
					recpool.pop_back();
				}
				else {
					recpool.at(0) = recpool.at(2);
					recpool.at(1) = recpool.at(3);
					recpool.pop_back();
					recpool.pop_back();
				}
			}
			else {
				recpool.pop_back();
			}
		}
		else if (recpool.size() > 0) {
			recpool.pop_back();
		}
	}
}

void aiplayer::removecell(int x, int y) {
	int g = -1;
	for (int i = 0; i < cellsleft.size(); i++) {
		if (cellsleft.at(i).x == x && cellsleft.at(i).y == y) {
			g = i;
			break;
		}
	}
	if (g != -1) {
		cellsleft.erase(cellsleft.begin() + g);
		cellsleft.shrink_to_fit();
	}
	cout << "Cells left: " << cellsleft.size() << endl;
}

void aiplayer::shipKilled(Ship ship) {
	recpool.clear();
	shipdetected = false;
	dirdetected = false;
	stage = unknown;
	removeShipPerimeter(ship);
}

void aiplayer::removeShipPerimeter(Ship ship) {
	direction direction = ship.getDir();
	int row = ship.getPos().y;
	int column = ship.getPos().x;
	int size = ship.getSize();


	if (direction == h) {

		//vertical checking
		if (row - 1 < 0) {
			for (uint16_t j = 0; j < size; j++) {
				removecell(column + j, row + 1);
			}
		}
		else if (row + 1 > 9) {
			for (uint16_t j = 0; j < size; j++) {
				removecell(column + j, row - 1);
			}
		}
		else {
			for (uint16_t j = 0; j < size; j++) {
				removecell(column + j, row - 1);
				removecell(column + j, row + 1);
			}
		}

		//horizontal checking
		if (column - 1 < 0) {
			removecell(column + size, row);
		}
		else if (column + size > 9) {
			removecell(column - 1, row);
		}
		else {
			removecell(column + size, row);
			removecell(column - 1, row);
		}

		//diagonal checking
		//top left corner
		if (row - 1 < 0 && column - 1 < 0) {
			removecell(column + size, row + 1);
		}
		//top right corner
		else if (row - 1 < 0 && column + size > 9) {
			removecell(column - 1, row + 1);
		}
		//bottom left corner
		else if (row + 1 > 9 && column - 1 < 0) {
			removecell(column + size, row - 1);
		}
		//bottom right corner
		else if (row + 1 > 9 && column + size > 9) {
			removecell(column - 1, row - 1);
		}
		//left border of the field
		else if (column - 1 < 0 && row >= 0 && row <= 9) {
			removecell(column + size, row - 1);
			removecell(column + size, row + 1);
		}
		//right border of the field
		else if (column + size > 9 && row >= 0 && row <= 9) {
			removecell(column - 1, row - 1);
			removecell(column - 1, row + 1);
		}
		//top border of the field
		else if (row - 1 < 0 && column - 1 >= 0 && column + size <= 9) {
			removecell(column - 1, row + 1);
			removecell(column + size, row + 1);
		}
		//bottom border of the field
		else if (row + 1 > 9 && column - 1 >= 0 && column + size <= 9) {
			removecell(column - 1, row - 1);
			removecell(column + size, row - 1);
		}
		//not in the corner and not near the border of the field
		else {
			removecell(column + size, row - 1);
			removecell(column + size, row + 1);
			removecell(column - 1, row + 1);
			removecell(column - 1, row - 1);
		}
	}
	else {
		//vertical checking
		if (row - 1 < 0) {
			removecell(column, row + size);
		}
		else if (row + size > 9) {
			removecell(column, row - 1);
		}
		else {
			removecell(column, row - 1);
			removecell(column, row + size);
		}

		//horizontal checking
		if (column - 1 < 0) {
			for (uint16_t j = 0; j < size; j++) {
				removecell(column + 1, row + j);
			}
		}
		else if (column + 1 > 9) {
			for (uint16_t j = 0; j < size; j++) {
				removecell(column - 1, row + j);
			}
		}
		else {
			for (uint16_t j = 0; j < size; j++) {
				removecell(column + 1, row + j);
				removecell(column - 1, row + j);
			}
		}

		//diagonal checking
		//top left corner
		if (row - 1 < 0 && column - 1 < 0) {
			removecell(column + 1, row + size);
		}
		//top right corner
		else if (row - 1 < 0 && column + 1 > 9) {
			removecell(column - 1, row + size);
		}
		//bottom left corner
		else if (row + size > 9 && column - 1 < 0) {
			removecell(column + 1, row - 1);
		}
		//bottom right corner
		else if (row + size > 9 && column + 1 > 9) {
			removecell(column - 1, row - 1);
		}
		//left border of the field
		else if (column - 1 < 0 && row - 1 >= 0 && row + size <= 9) {
			removecell(column + 1, row - 1);
			removecell(column + 1, row + size);
		}
		//right border of the field
		else if (column + 1 > 9 && row - 1 >= 0 && row + size <= 9) {
			removecell(column - 1, row - 1);
			removecell(column - 1, row + size);
		}
		//top border of the field
		else if (row - 1 < 0 && column - 1 >= 0 && column + 1 <= 9) {
			removecell(column - 1, row + size);
			removecell(column + 1, row + size);
		}
		//bottom border of the field
		else if (row + size > 9 && column - 1 >= 0 && column + 1 <= 9) {
			removecell(column - 1, row - 1);
			removecell(column + 1, row - 1);
		}
		//not in the corner
		else {
			removecell(column - 1, row - 1);
			removecell(column + 1, row - 1);
			removecell(column - 1, row + size);
			removecell(column + 1, row + size);
		}
	}
}
