#pragma once

#include <iostream>
#include <string>
#include "NodeInterface.h"

class Node : public NodeInterface {
public:
	int data;
	Node* left;
	Node* right;

	Node() : data(0), left(NULL), right(NULL) {};
	Node(int data) : data(data), left(NULL), right(NULL) {};
	int getData() {
		return data;
	}
	Node* getLeftChild() {
		return left;
	}
	Node* getRightChild() {
		return right;
	}


};