#pragma once
class cell {
private:
	bool empty;
	bool unknown;
	bool ship;
	bool killed;
	bool visible;
public:
	void initEmpty();
	void initShip();
	void initVisible();
	bool isEmpty();
	bool isShip();
	bool isShooted();
	bool isKilled();
	void setKilled();
	char getStatus();
	cell();
	~cell();
};
