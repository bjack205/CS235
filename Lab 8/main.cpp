#include <iostream>
#include <string>


#include "Header.h"

using namespace std;

int main() {
	Sort sort;
	sort.createArray(5);
	sort.addToArray(1);
	sort.addToArray(2);
	sort.addToArray(10);
	sort.addToArray(5);
	sort.addToArray(6);
	cout << "Median of 3: " << sort.medianOfThree(0, 4) << endl;
	cout << "Partition: " << sort.partition(0, 4, sort.medianOfThree(0, 4)) << endl;

	cout << sort.getArray() << endl;
	cout << "Capacity: " << sort.getCapacity() << endl;
	cout << "Size: " << sort.getSize() << endl;

	string input;
	cout << "Would you like to exit? ";
	cin >> input;
	return 0;
}