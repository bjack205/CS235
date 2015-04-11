#pragma once

#include <iostream>
#include <string>

#include "Node.h"

using std::string;

class Tree {
private:
	Node* root;

	//Extras
	string preOrder(Node* n);
	//Recursive Functions
	bool add(Node*& n, int data);
	bool removeNode(Node*& n, int data, bool balanceTree = true);

public:
	//Constructor
	Tree() : root(NULL) {};
	//Destructor
	~Tree(){ clear(); }

	//BST Functions
	Node* getRootNode();
	bool add(int data);
	bool remove(int data);
	void clear();

	//Balancing
	void balance(Node*& n);
	void balanceRight(Node*& n);
	void balanceLeft(Node*& n);
	void rotateRight(Node*& n);
	void rotateLeft(Node*& n);

	//Extras
	string printTree();
	int getMax(Node* n);
	int getNodeHeight(Node* n);
	int updateHeight(Node* n);
};
