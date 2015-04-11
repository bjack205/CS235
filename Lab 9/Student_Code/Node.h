#pragma once

#include <iostream>
#include <string>
#include "NodeInterface.h"
#include "Tree.h"

class Node : public NodeInterface {
private:
	int data;
	Node* left;
	Node* right;
	int height;
	friend class Tree;
public:
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
	int getHeight() {
		return height;
	}


};