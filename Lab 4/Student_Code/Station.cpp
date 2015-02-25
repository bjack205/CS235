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
	if (current_car == -1 && validCar(car)) {
		current_car = car;
		return true;
	}
	else
		return false;
}
int Station::showCurrentCar() {
	return current_car;
}
bool Station::removeFromStation() {
	if (current_car > -1) {
		clearPort();
		return true;
	}
	else
		return false;
}

//Part 2
bool Station::addToStack() {
	if ((stack.size() < MAX_CAPACITY) && (!portOpen())) {
		stack.push(current_car);
		clearPort();
		return true;
	}
	else
		return false;
}
bool Station::removeFromStack() {
	if (stack.isEmpty() && portOpen()) {
		current_car = stack.top();
		stack.pop();
		return true;
	}
	else
		return false;
}
int Station::showTopOfStack() {
	if (stack.isEmpty())
		return -1;
	else {
		int car;
		car = stack.top();
		stack.pop();
		return car;
	}
}
int Station::showSizeOfStack() {
	return stack.size();
}

//Part 3
bool Station::addToQueue() {
	if ((queue.size() < MAX_CAPACITY) && (!portOpen())) {
		queue.push(current_car);
		clearPort();
		return true;
	}
	else
		return false;
}
bool Station::removeFromQueue() {
	if (queue.isEmpty() && portOpen()) {
		current_car = queue.top();
		stack.pop();
		return true;
	}
	else
		return false;
}
int Station::showTopOfQueue() {
	if (queue.isEmpty())
		return -1;
	else {
		int car;
		car = queue.top();
		queue.pop();
		return car;
	}
}
int Station::showSizeOfQueue() {
	return queue.size();
}

//Part 4
bool Station::addToDequeLeft() {
	if ((deque.size() < MAX_CAPACITY) && (!portOpen())) {
		deque.addLeft(current_car);
		clearPort();
		return true;
	}
	else
		return false;
}
bool Station::addToDequeRight() {
	if ((deque.size() < MAX_CAPACITY) && (!portOpen())) {
		deque.addRight(current_car);
		clearPort();
		return true;
	}
	else
		return false;
}
bool Station::removeFromDequeLeft() {
	if (deque.isEmpty() && portOpen()) {
		current_car = deque.getLeft();
		deque.removeLeft();
		return true;
	}
	else
		return false;
}
bool Station::removeFromDequeRight() {
	if (deque.isEmpty() && portOpen()) {
		current_car = deque.getRight();
		deque.removeRight();
		return true;
	}
	else
		return false;
}
int Station::showTopOfDequeLeft() {
	if (deque.isEmpty() && portOpen()) {
		current_car = deque.getLeft();
		deque.removeLeft();
		return true;
	}
	else
		return false;
}
int Station::showTopOfDequeRight() {
	if (deque.isEmpty() && portOpen()) {
		current_car = deque.getRight();
		deque.removeRight();
		return true;
	}
	else
		return false;
}
int Station::showSizeOfDeque() {
	return deque.size();
}