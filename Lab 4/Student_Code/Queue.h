#pragma once

#include <iostream>
#include <string>

#include "List.h"

class Queue {
private:
	List<int> list;
public:
	Queue(){};
	~Queue(){
		this->clear();
	}
	void push(int item);
	int top();
	void pop();
	int size();
	bool inQueue(int item);
	bool isEmpty();
	void clear();
	void PrintQueue();
};