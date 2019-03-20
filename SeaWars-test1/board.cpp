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

void Board::launch_ship(Ship &ship) {
	if (can_launch_ship(ship.getPos().x, ship.getPos().y, ship.getDir(), ship.getSize())) {
		ships.push_back(ship);

		if (ship.getDir() == h) {
			for (uint16_t j = 0, ship_size = ship.getSize(); j < ship_size; j++) {
				gameboard.at(ship.getPos().x + j).at(ship.getPos().y).initShip();
			}
		}
		else {
			for (uint16_t j = 0, ship_size = ship.getSize(); j < ship_size; j++) {
				gameboard.at(ship.getPos().x).at(ship.getPos().y + j).initShip();
			}
		}
	}
}

bool Board::can_launch_ship(int column, int row, direction direction, int size)
{
	if (!shipIsOnBoard(column, row, direction, size) || shipIsNear()) {
		return false;
	}

	return true;
}

bool Board::shipIsOnBoard(int column, int row, direction direction, int size) {
	if (direction == h) {
		for (uint16_t j = 0; j < size; j++) {
			if ((column + size) > 10)
				return false;
			else if (gameboard.at(column).at(row + j).isEmpty() == false)
				return false;
		}
	}
	else {
		for (uint16_t j = 0; j < size; j++) {
			if ((row + size) > 10)
				return false;
			else if (gameboard.at(column + j).at(row).isEmpty() == false)
				return false;
		}
	}

	return true;
}

bool Board::shipIsNear() {
	return false;
}

char Board::getCellStatus(int i, int g) {
	return gameboard.at(g).at(i).getStatus();
}

void Board::show() {

}
