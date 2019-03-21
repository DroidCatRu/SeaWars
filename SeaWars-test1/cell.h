#pragma once
class cell {
private:
	bool empty;
	bool unknown;
	bool ship;
	bool visible;
public:
	void initEmpty();
	void initShip();
	void initVisible();
	bool isEmpty();
	bool isShip();
	bool isShooted();
	char getStatus();
	cell();
	~cell();
};
