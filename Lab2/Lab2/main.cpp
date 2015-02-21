#include <iostream>
#include <string>
#include "Header.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using std::count;
using std::cin;

int main() {
	string input;
	List<int> numbers;
	numbers.insertTail(1);
	numbers.clear();

	/*
	numbers.PrintList();
	numbers.insertHead(0);
	numbers.insertHead(5);
	numbers.insertHead(2);
	numbers.insertHead(1);
	numbers.insertTail(10);
	numbers.insertAfter(3, 4);

	numbers.remove(0);
	numbers.PrintList();

	numbers.remove(numbers.getHead());
	numbers.PrintList();
	numbers.remove(numbers.getTail());
	numbers.PrintList();
	numbers.remove(numbers.getHead());
	numbers.PrintList();
	numbers.remove(numbers.getHead());
	numbers.PrintList();

	numbers.insertHead(0);
	numbers.insertHead(5);
	numbers.insertHead(2);
	numbers.insertHead(1);
	numbers.insertTail(10);
	numbers.insertAfter(3, 4);
	numbers.PrintList();
	*/

	
	//cout << numbers.InList(2) << endl;
	cout << "Head: " << numbers.getHead() << " Tail: " << numbers.getTail() << endl;
	cout << "Size: " << numbers.size() << endl;

	cout << "Exit? (y/n) ";
	cin >> input;
	
	_CrtDumpMemoryLeaks();
	if (input == "y")
		return 0;
	else
		return 0;
	
}
