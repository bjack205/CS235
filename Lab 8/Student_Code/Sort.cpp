#include <iostream>
#include <string>
#include <sstream>

#include "Sort.h"

using namespace std;

int Sort::medianOfThree(int left, int right) {
	int mid;
	int swap;
	//Validation
	if ((left > right) || (left < 0) || (right >= size) || (size == 0)) {
		return -1;
	}
	else {
		mid = (left + right) / 2;
		//Sort left, mid, right
		if (list[left] > list[mid])
			swapVals(left, mid);
		if (list[mid] > list[right])
			swapVals(mid, right);
		if (list[left] > list[mid])
			swapVals(left, mid);
		return mid;
	}
}
int Sort::partition(int left, int right, int pivotIndex) {
	//Validation
	if ((left > right) || (left < 0) || (right >= size) || (size == 0) || (pivotIndex < left) || (pivotIndex > right)) {
		return -1;
	}
	else {
		int pivotValue = list[pivotIndex];
		int up = left + 1;
		int down = right;
		swapVals(left, pivotIndex);
		do {
			while (list[up] <= pivotValue) {
				up++;
			}
			while (list[down] > pivotValue) {
				down--;
			}
			if (up < down) {
				swapVals(up, down);
				cout << getArray() << endl;
			}
		} while (up < down);
		swapVals(left, down);
		return down;
	}
}
string Sort::getArray() {
	ostringstream out;
	for (int i = 0; i < size - 1; i++) {
		out << list[i] << ",";
	}
	out << list[size - 1];
	return out.str();
}
int Sort::getSize() {
	return size;
}
void Sort::addToArray(int value) {
	if (size < capacity) {
		list[size] = value;
		size++;
	}
}
bool Sort::createArray(int capacity) {
	if (capacity >= 0) {
		delete[] list;
		list = new int[capacity];
		this->capacity = capacity;
		return true;
	}
	return false;
}
