#pragma once

#include <iostream>
#include <string>

#include "Node.h"
#include "BSTInterface.h"

using std::string;

class Tree : public BSTInterface {
private:
	Node* root;

	//Extras
	string preOrder(Node* n);
	//Recursive Functions
	bool add(Node*& n, int data);
	bool remove(Node*& n, int data);

public:
	Tree() : root(NULL) {};
	Node* getRootNode();
	bool add(int data);
	bool remove(int data);
	void clear();

	string printTree();
	int getMax(Node* n);

};
