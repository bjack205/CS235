#pragma once

#include <iostream>
#include <string>

#include "List.h"

class Deque {
private:
	List<int> list;
public:
	Deque(){};
	~Deque(){
		this->clear();
	}
	void addLeft(int item);
	void addRight(int item);
	void removeLeft();
	void removeRight();
	int getLeft();
	int getRight();
	int size();
	bool inDeque(int item);
	bool isEmpty();
	void clear();
	void PrintDeque();
};