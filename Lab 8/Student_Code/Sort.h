#pragma once

#include <iostream>
#include <string>

#include "QSInterface.h"

using namespace std;

class Sort : public QSInterface {
private:
	int *list;
	int capacity;
	int size;
protected:
	void sort(int left, int right);
public:
	//Constructor
	Sort() : capacity(0), size(0) {};

	//Functions
	void sortAll();
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray();
	int getSize();
	void addToArray(int value);
	bool createArray(int capacity);
	void clear();

	//Extras
	int getCapacity() { return capacity; }
	void swapVals(int index1, int index2) {
		int swap;
		swap = list[index1];
		list[index1] = list[index2];
		list[index2] = swap;
	}
};