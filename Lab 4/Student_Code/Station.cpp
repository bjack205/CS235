#include <iostream>
#include <string>

#include "Station.h"

using namespace std;

bool Station::validCar(int car) {
	if (car < 0)
		return false;
	if (stack.inStack(car))
		return false;
	if (queue.inQueue(car))
		return false;
	if (deque.inDeque(car))
		return false;
	return true;
}
bool Station::portOpen() {
	if (current_car == -1)
		return true;
	else
		return false;
}
void Station::clearPort() {
	current_car = -1;
}

//Part 1
bool Station::addToStation(int car) {
	//cout << "Add to Station: " << car << endl;
	if (portOpen() && validCar(car)) {
		current_car = car;
		return true;
	}
	else
		return false;
}
int Station::showCurrentCar() {
	//cout << "Show Current Car: " << current_car << endl;
	return current_car;
}
bool Station::removeFromStation() {
	//cout << "Remove From Station: " << (current_car) << endl;
	if (portOpen())
		return false;
	else {
		clearPort();
		return true;
	}
}

//Part 2
bool Station::addToStack() {
	//cout << "Add to Stack: " << current_car << endl;
	if ((stack.size() < MAX_CAPACITY) && (!portOpen())) {
		stack.push(current_car);
		clearPort();
		return true;
	}
	else
		return false;
}
bool Station::removeFromStack() {
	//cout << "Remove from Stack: " << stack.top() << endl;
	if (!stack.isEmpty() && portOpen()) {
		current_car = stack.top();
		stack.pop();
		return true;
	}
	else
		return false;
}
int Station::showTopOfStack() {
	//cout << "Show Stack: " << stack.top() << endl;
	if (stack.isEmpty())
		return -1;
	else {
		return stack.top();
	}
}
int Station::showSizeOfStack() {
	//cout << "Stack Size: " << stack.size() << endl;
	return stack.size();
}

//Part 3
bool Station::addToQueue() {
	//cout << "Add to Queue: " << current_car << endl;
	if ((queue.size() < MAX_CAPACITY) && (!portOpen())) {
		queue.push(current_car);
		clearPort();
		return true;
	}
	else
		return false;
}
bool Station::removeFromQueue() {
	//cout << "Remove from Queue: " << queue.top() << endl;
	if (!queue.isEmpty() && portOpen()) {
		current_car = queue.top();
		queue.pop();
		return true;
	}
	else
		return false;
}
int Station::showTopOfQueue() {
	//cout << "Top of Queue: " << queue.top()	 << endl;
	if (queue.isEmpty())
		return -1;
	else {
		return queue.top();
	}
}
int Station::showSizeOfQueue() {
	//cout << "Queue Size: " << queue.size() << endl;
	return queue.size();
}

//Part 4
bool Station::addToDequeLeft() {
	//cout << "addDequeLeft " << current_car << endl;
	if ((deque.size() < MAX_CAPACITY) && (!portOpen())) {
		deque.addLeft(current_car);
		clearPort();
		return true;
	}
	else
		return false;
}
bool Station::addToDequeRight() {
	//cout << "addDequeRight " << current_car << endl;
	if ((deque.size() < MAX_CAPACITY) && (!portOpen())) {
		deque.addRight(current_car);
		clearPort();
		return true;
	}
	else
		return false;
}
bool Station::removeFromDequeLeft() {
	//cout << "removeDequeLeft " << deque.getLeft() << endl;
	if (!deque.isEmpty() && portOpen()) {
		current_car = deque.getLeft();
		deque.removeLeft();
		return true;
	}
	else
		return false;
}
bool Station::removeFromDequeRight() {
	//cout << "removeDequeRight " << deque.getRight() << endl;
	if (!deque.isEmpty() && portOpen()) {
		current_car = deque.getRight();
		deque.removeRight();
		return true;
	}
	else
		return false;
}
int Station::showTopOfDequeLeft() {
	//cout << "showDequeLeft " << deque.getLeft() << endl;
	if (!deque.isEmpty()) {
		return deque.getLeft();
	}
	else
		return -1;
}
int Station::showTopOfDequeRight() {
	//cout << "showDequeRight " << deque.getRight() << endl;
	if (!deque.isEmpty()) {
		return deque.getRight();
	}
	else
		return -1;
}
int Station::showSizeOfDeque() {
	return deque.size();
}
