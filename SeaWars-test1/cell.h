#pragma once
class cell
{
private:
	bool empty;
	bool unknown;
	bool ship;
public:
	void initEmpty();
	void initShip();
	bool isEmpty();
	bool isShip();
	bool isShooted();
	char getStatus();
	cell();
	~cell();
};
