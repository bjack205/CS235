#pragma once
#include <iostream>
#include <string>
#include "StationInterface.h"
#include "Deque.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

class Station : public StationInterface {
private:
	int current_car;
	const int MAX_CAPACITY = 5;
	Stack stack;
	Queue queue;
	Deque deque;
public:
	Station() : current_car(-1) {};

	//Part 1
	bool addToStation(int car);
	int showCurrentCar();
	bool removeFromStation();

	//Part 2
	bool addToStack();
	bool removeFromStack();
	int showTopOfStack();
	int showSizeOfStack();

	//Part 3
	bool addToQueue();
	bool removeFromQueue();
	int showTopOfQueue();
	int showSizeOfQueue();

	//Part 4
	bool addToDequeLeft();
	bool addToDequeRight();
	bool removeFromDequeLeft();
	bool removeFromDequeRight();
	int showTopOfDequeLeft();
	int showTopOfDequeRight();
	int showSizeOfDeque();
protected:
	bool validCar(int car);
	bool portOpen();
	void clearPort();
};