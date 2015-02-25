#include <iostream>
#include <string>

#include "Station.h"

using namespace std;

void testList() {
	List<int> list;
	list.insertTail(4);
	list.insertTail(5);
	list.insertHead(1);
	list.removeTail();
	list.removeTail();
	/*
	list.insertTail(2);
	list.insertAfter(3, 1);
	list.removeHead();
	list.removeHead();
	list.removeHead();
	cout << "Is empty? " << list.isEmpty() << endl;
	list.insertTail(4);
	cout << "Is empty? " << list.isEmpty() << endl;
	list.insertTail(3);

	cout << "Is empty? " << list.isEmpty() << endl;
	*/
	list.PrintList();
}
void testStack() {
	Stack stack;
	stack.pop();
	cout << "Top: " << stack.top() << endl;
	stack.push(0);
	stack.push(1);
	stack.push(2);
	stack.push(4);
	stack.PrintStack();
	cout << "Is Empty? " << stack.isEmpty() << endl;
	stack.pop();
	cout << "Top: " << stack.top() << endl;
	stack.pop();
	stack.PrintStack();
	stack.push(5);
	stack.PrintStack();
	stack.pop();
	stack.pop();
	cout << "Top: " << stack.top() << endl;
	stack.clear();
	cout << "Is Empty? " << stack.isEmpty() << endl;
	stack.push(10);
	stack.pop();
	cout << "Is Empty? " << stack.isEmpty() << endl;
}

void testQueue() {
	Queue stack;
	stack.pop();
	cout << "Top: " << stack.top() << endl;
	stack.push(0);
	stack.push(1);
	stack.push(2);
	stack.push(4);
	stack.PrintQueue();
	cout << "Is Empty? " << stack.isEmpty() << endl;
	stack.pop();
	cout << "Top: " << stack.top() << endl;
	stack.pop();
	stack.PrintQueue();
	stack.push(5);
	stack.PrintQueue();
	stack.pop();
	stack.pop();
	cout << "Top: " << stack.top() << endl;
	stack.clear();
	cout << "Is Empty? " << stack.isEmpty() << endl;
	stack.push(10);
	stack.pop();
	cout << "Is Empty? " << stack.isEmpty() << endl;
}
void testDeque() {
	Deque dq;
	dq.addLeft(1);
	dq.addLeft(2);
	dq.addRight(4);
	dq.addRight(10);
	dq.addLeft(5);
	dq.addLeft(2);
	dq.PrintDeque();
	dq.removeLeft();
	dq.removeLeft();
	dq.PrintDeque();
	dq.removeRight();
	dq.removeRight();
	dq.PrintDeque();
}
void testStation() {
	Station station;
	station.addtoStation(1);
}
int main() {
	
	string input;
	testDeque();
	cout << "Press key to exit: ";
	cin >> input;
	
	return 0;
}