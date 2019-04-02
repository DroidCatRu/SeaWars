#include "pch.h"
#include "board.h"


Board::Board() {
	vector<cell> rows;
	for (uint16_t row = 0; row < 10; row++) {
		for (uint16_t column = 0; column < 10; column++) {
			cell cell;
			cell.initEmpty();
			rows.push_back(cell);
		}
		gameboard.push_back(rows);
	}
}


Board::~Board() {

}

void Board::launch_ship(Ship ship, bool visible) {
	if (can_launch_ship(ship.getPos().x, ship.getPos().y, ship.getDir(), ship.getSize())) {

		if (ship.getDir() == h) {
			for (uint16_t j = 0, ship_size = ship.getSize(); j < ship_size; j++) {
				gameboard.at(ship.getPos().y).at(ship.getPos().x + j).initShip();
				if (visible) {
					gameboard.at(ship.getPos().y).at(ship.getPos().x + j).initVisible();
				}
			}
		}
		else {
			for (uint16_t j = 0, ship_size = ship.getSize(); j < ship_size; j++) {
				gameboard.at(ship.getPos().y + j).at(ship.getPos().x).initShip();
				if (visible) {
					gameboard.at(ship.getPos().y + j).at(ship.getPos().x).initVisible();
				}
			}
		}
		Ship s = ship;
		ships.push_back(s);
	}
}

bool Board::can_launch_ship(int column, int row, direction direction, int size)
{
	if (shipIsOnBoard(column, row, direction, size) && !shipIsNear(column, row, direction, size)) {
		return true;
	}

	return false;
}

bool Board::shipIsOnBoard(int column, int row, direction direction, int size) {
	if (direction == h) {
		for (uint16_t j = 0; j < size; j++) {
			if ((column + size) > 10)
				return false;
			else if (!gameboard.at(row).at(column + j).isEmpty())
				return false;
		}
	}
	else {
		for (uint16_t j = 0; j < size; j++) {
			if ((row + size) > 10)
				return false;
			else if (!gameboard.at(row + j).at(column).isEmpty())
				return false;
		}
	}

	return true;
}

bool Board::shipIsNear(int column, int row, direction direction, int size) {
	if (direction == h) {
		
		//vertical checking
		if (row - 1 < 0) {
			for (uint16_t j = 0; j < size; j++) {
				if (!gameboard.at(row + 1).at(column + j).isEmpty()) {
					return true;
				}
			}
		}
		else if (row + 1 > 9) {
			for (uint16_t j = 0; j < size; j++) {
				if (!gameboard.at(row - 1).at(column + j).isEmpty()) {
					return true;
				}
			}
		}
		else {
			for (uint16_t j = 0; j < size; j++) {
				if (!gameboard.at(row - 1).at(column + j).isEmpty() || !gameboard.at(row + 1).at(column + j).isEmpty()) {
					return true;
				}
			}
		}

		//horizontal checking
		if (column - 1 < 0) {
			if (!gameboard.at(row).at(column + size).isEmpty()) {
				return true;
			}
		}
		else if (column + size > 9) {
			if (!gameboard.at(row).at(column - 1).isEmpty()) {
				return true;
			}
		}
		else {
			if (!gameboard.at(row).at(column + size).isEmpty() || !gameboard.at(row).at(column - 1).isEmpty()) {
				return true;
			}
		}

		//diagonal checking
		//top left corner
		if (row - 1 < 0 && column - 1 < 0) {
			if (!gameboard.at(row + 1).at(column + size).isEmpty()) {
				return true;
			}
		}
		//top right corner
		else if (row - 1 < 0 && column + size > 9) {
			if (!gameboard.at(row + 1).at(column - 1).isEmpty()) {
				return true;
			}
		}
		//bottom left corner
		else if (row + 1 > 9 && column - 1 < 0) {
			if (!gameboard.at(row - 1).at(column + size).isEmpty()) {
				return true;
			}
		}
		//bottom right corner
		else if (row + 1 > 9 && column + size > 9) {
			if (!gameboard.at(row - 1).at(column - 1).isEmpty()) {
				return true;
			}
		}
		//left border of the field
		else if (column - 1 < 0 && row >= 0 && row <= 9) {
			if (!gameboard.at(row - 1).at(column + size).isEmpty() || !gameboard.at(row + 1).at(column + size).isEmpty()) {
				return true;
			}
		}
		//right border of the field
		else if (column + size > 9 && row >= 0 && row <= 9) {
			if (!gameboard.at(row - 1).at(column - 1).isEmpty() || !gameboard.at(row + 1).at(column - 1).isEmpty()) {
				return true;
			}
		}
		//top border of the field
		else if ( row - 1 < 0 && column - 1 >= 0 && column + size <= 9) {
			if (!gameboard.at(row + 1).at(column - 1).isEmpty() || !gameboard.at(row + 1).at(column + size).isEmpty()) {
				return true;
			}
		}
		//bottom border of the field
		else if (row + 1 > 9 && column - 1 >= 0 && column + size <= 9) {
			if (!gameboard.at(row - 1).at(column - 1).isEmpty() || !gameboard.at(row - 1).at(column + size).isEmpty()) {
				return true;
			}
		}
		//not in the corner and not near the border of the field
		else {
			if (!gameboard.at(row - 1).at(column + size).isEmpty() ||
				!gameboard.at(row + 1).at(column + size).isEmpty() ||
				!gameboard.at(row + 1).at(column - 1).isEmpty() ||
				!gameboard.at(row - 1).at(column - 1).isEmpty()) {
				return true;
			}
		}
	}
	else {
		//vertical checking
		if (row - 1 < 0) {
			if (!gameboard.at(row + size).at(column).isEmpty()) {
				return true;
			}
		}
		else if (row + size > 9) {
			if (!gameboard.at(row - 1).at(column).isEmpty()) {
				return true;
			}
		}
		else {
			if (!gameboard.at(row - 1).at(column).isEmpty() || !gameboard.at(row + size).at(column).isEmpty()) {
				return true;
			}
		}

		//horizontal checking
		if (column - 1 < 0) {
			for (uint16_t j = 0; j < size; j++) {
				if (!gameboard.at(row + j).at(column + 1).isEmpty()) {
					return true;
				}
			}
		}
		else if (column + 1 > 9) {
			for (uint16_t j = 0; j < size; j++) {
				if (!gameboard.at(row + j).at(column - 1).isEmpty()) {
					return true;
				}
			}
		}
		else {
			for (uint16_t j = 0; j < size; j++) {
				if (!gameboard.at(row + j).at(column + 1).isEmpty() || !gameboard.at(row + j).at(column - 1).isEmpty()) {
					return true;
				}
			}
		}

		//diagonal checking
		//top left corner
		if (row - 1 < 0 && column - 1 < 0) {
			if (!gameboard.at(row + size).at(column + 1).isEmpty()) {
				return true;
			}
		}
		//top right corner
		else if (row - 1 < 0 && column + 1 > 9) {
			if (!gameboard.at(row + size).at(column - 1).isEmpty()) {
				return true;
			}
		}
		//bottom left corner
		else if (row + size > 9 && column - 1 < 0) {
			if (!gameboard.at(row - 1).at(column + 1).isEmpty()) {
				return true;
			}
		}
		//bottom right corner
		else if (row + size > 9 && column + 1 > 9) {
			if (!gameboard.at(row - 1).at(column - 1).isEmpty()) {
				return true;
			}
		}
		//left border of the field
		else if (column - 1 < 0 && row - 1 >= 0 && row + size <= 9) {
			if (!gameboard.at(row - 1).at(column + 1).isEmpty() || !gameboard.at(row + size).at(column + 1).isEmpty()) {
				return true;
			}
		}
		//right border of the field
		else if (column + 1 > 9 && row - 1 >= 0 && row + size <= 9) {
			if (!gameboard.at(row - 1).at(column - 1).isEmpty() || !gameboard.at(row + size).at(column - 1).isEmpty()) {
				return true;
			}
		}
		//top border of the field
		else if (row - 1 < 0 && column - 1 >= 0 && column + 1 <= 9) {
			if (!gameboard.at(row + size).at(column - 1).isEmpty() || !gameboard.at(row + size).at(column + 1).isEmpty()) {
				return true;
			}
		}
		//bottom border of the field
		else if (row + size > 9 && column - 1 >= 0 && column + 1 <= 9) {
			if (!gameboard.at(row - 1).at(column - 1).isEmpty() || !gameboard.at(row - 1).at(column + 1).isEmpty()) {
				return true;
			}
		}
		//not in the corner
		else {
			if (!gameboard.at(row - 1).at(column - 1).isEmpty() ||
				!gameboard.at(row - 1).at(column + 1).isEmpty() ||
				!gameboard.at(row + size).at(column - 1).isEmpty() ||
				!gameboard.at(row + size).at(column + 1).isEmpty()) {
				return true;
			}
		}
	}
	return false;
}

char Board::getCellStatus(int i, int g) {
	return gameboard.at(i).at(g).getStatus();
}

void Board::initVisible(int i, int g) {
	gameboard.at(g).at(i).initVisible();
}

int Board::setKilled(int i, int g) {
	gameboard.at(i).at(g).setKilled();
	int f = 0;
	while (f < 10) {
		int z = 0;
		int s = ships.at(f).getSize();
		//looking for cell in ships array
		while (z < s) {
			if (ships.at(f).getCellPos(z).y == i && ships.at(f).getCellPos(z).x == g) { //found position
				z++;
				break;
			}
			z++;
		}
		z--;
		if (ships.at(f).getCellPos(z).y == i && ships.at(f).getCellPos(z).x == g) {
			ships.at(f).setCellStatus(z); //set cell killed and check if the whole ship is killed
			break;
		}
		f++;
	}

	//ship killed
	if (ships.at(f).isKilled()) {
		cout << "Ship killed!" << endl;
		return f;
	}

	//ship not killed
	return -1;
}

Ship Board::getShip(int i) {
	return ships.at(i);
}