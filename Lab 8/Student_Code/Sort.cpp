#include <iostream>
#include <string>
#include <sstream>

#include "Sort.h"

using namespace std;

void Sort::sortAll() {
	if (size > 0)
		sort(0, size - 1);
}
void Sort::sort(int left, int right) {
	if ((right - left) > 0) {
		int pivotIndex = medianOfThree(left, right);
		pivotIndex = partition(left, right, pivotIndex);
		sort(left, pivotIndex - 1);
		sort(pivotIndex + 1, right);
	}
}
int Sort::medianOfThree(int left, int right) {
	cout << "Median of 3: (" << left << "," << right << ")" << endl;
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
	cout << "Partition: (" << left << "," << right << "," << pivotIndex << ")" << endl;
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
			}
		} while (up < down);
		swapVals(left, down);
		return down;
	}
}
string Sort::getArray() {
	ostringstream out;
	if (size > 0) {
		for (int i = 0; i < size - 1; i++) {
			out << list[i] << ",";
		}
		out << list[size - 1];
	}
	cout << "Get Array: {" << out.str() << "}" << endl;
	return out.str();
}
int Sort::getSize() {
	cout << "GetSize" << endl;
	return size;
}
void Sort::addToArray(int value) {
	cout << "addToArray: " << value << endl;
	if (size < capacity) {
		list[size] = value;
		size++;
	}
}
bool Sort::createArray(int capacity) {
	cout << "Create Array: " << capacity << endl;
	if (capacity >= 0) {
		delete[] list;
		list = new int[capacity];
		this->capacity = capacity;
		return true;
	}
	return false;
}
void Sort::clear() {
	delete[] list;
}
