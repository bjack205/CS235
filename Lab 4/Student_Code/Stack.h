#pragma once

#include <iostream>
#include <string>

#include "List.h"

class Stack {
private:
	List<int> list;
public:
	Stack(){};
	~Stack() {
		this->clear();
	}
	void push(int item);
	int top();
	void pop();
	int size();
	bool inStack(int item);
	bool isEmpty();
	void clear();
	void PrintStack();
};