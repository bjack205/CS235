#pragma once

class Cell {
private:
	int value;
public:
	Cell() : value(0) {};
	Cell(int value) : value(value) {};
	int getValue() {
		return value;
	}
};