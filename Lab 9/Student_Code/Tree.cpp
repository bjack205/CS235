#include <iostream>
#include <string>
#include <algorithm>

#include "Tree.h"

using namespace std;

Node* Tree::getRootNode() {
	return root;
}
bool Tree::add(int data) {
	bool status = add(root, data);
	//cout << "Add: " << data << " (" << status << ")" << endl;
	return status;
}
bool Tree::add(Node*& n, int data) {
	if (n == NULL) {
		n = new Node(data);
		updateHeight(root);
		balance(n);
		return true;
	}
	else if (n->data == data) {
		return false;
	}
	else if (data < n->data) {
		bool status = add(n->left, data);
		updateHeight(root);
		balance(n);
		return status;
	}
	else if (data > n->data) {
		bool status = add(n->right, data);
		updateHeight(n);
		balance(n);
		return status;
	}
	return false;
}
bool Tree::remove(int data) {
	bool status = removeNode(root,data);
	//cout << "Remove: " << data << " (" << status << ")" << endl;
	return status;
}
bool Tree::removeNode(Node*& n, int data, bool balanceTree) {
	if (n == NULL) {
		return false;
	}
	else if (data < n->data) {
		bool status = removeNode(n->left, data);
		if (balanceTree) {
			updateHeight(root);
			balance(n);
		}
		return status;
	}
	else if (data > n->data) {
		bool status = removeNode(n->right, data);
		if (balanceTree) {
			updateHeight(root);
			balance(n);
		}
		return status;
	}
	//Equal
	else {
		Node* toRemove = n;
		//Leaf Node
		if ((n->left == NULL) && (n->right == NULL)) {
			n = NULL;
			delete toRemove;
		}
		//Single Child
		else if (n->left == NULL) {
			n = n->right;
			delete toRemove;
		}
		else if (n->right == NULL) {
			n = n->left;
			delete toRemove;
		}
		//Both Children (CTL)
		else {
			int replacement = getMax(n->left);
			remove(replacement);
			replace(data,replacement);
			updateHeight(root);
			balance(n);
		}
		return true;
	}
}
void Tree::clear() {
	while (root != NULL) {
		remove(root->data);
	}
}

//Balancing
void Tree::balance(Node*& n) {
	if ((getNodeHeight(n->getLeftChild()) - getNodeHeight(n->getRightChild())) > 1) {
		balanceRight(n);
	}
	else if ((getNodeHeight(n->getRightChild()) - getNodeHeight(n->getLeftChild())) > 1) {
		balanceLeft(n);
	}
}
void Tree::balanceRight(Node*& n) {
	Node* leftGChild = n->getLeftChild()->getLeftChild();
	Node* rightGChild = n->getLeftChild()->getRightChild();
	if (getNodeHeight(leftGChild) < getNodeHeight(rightGChild)) {
		rotateLeft(n->left);
	}
	rotateRight(n);
}
void Tree::balanceLeft(Node*& n) {
	Node* leftGChild = n->getRightChild()->getLeftChild();
	Node* rightGChild = n->getRightChild()->getRightChild();
	if (getNodeHeight(leftGChild) > getNodeHeight(rightGChild)) {
		rotateRight(n->right);
	}
	rotateLeft(n);
}
void Tree::rotateRight(Node*& n) {
	Node* k = n->getLeftChild();
	n->left = k->right;
	k->right = n;
	n = k;
}
void Tree::rotateLeft(Node*& n) {
	Node* k = n->getRightChild();
	n->right = k->left;
	k->left = n;
	n = k;
}

//Extras
string Tree::printTree() {
	return preOrder(root);
}
string Tree::preOrder(Node* n) {
	string list;
	if (n == NULL) {
		list = "End";
		return list;
	}
	else {
		list = list + to_string(n->data);
		string left = preOrder(n->left);
		if (left != "End")
			list = list + left;
		string right = preOrder(n->right);
		if (right != "End")
			list = list + right;
		return list;
	}
}
int Tree::getMax(Node* n) {
	if (n->right == NULL)
		return n->data;
	else
		return getMax(n->right);
}
int Tree::getNodeHeight(Node* n) {
	if (n == NULL)
		return -1;
	return n->getHeight();
}
int Tree::updateHeight(Node* n) {
	if (n->getLeftChild() != NULL) 
		updateHeight(n->getLeftChild());
	if (n->getRightChild() != NULL)
		updateHeight(n->getRightChild());
	n->height = max(getNodeHeight(n->getLeftChild()),getNodeHeight(n->getRightChild())) + 1;
	return n->getHeight();
}
bool Tree::replace(Node*& n, int prevValue, int newValue) {
	if (n != NULL) {
		//cout << n->data << " ";
		if (n->getData() < prevValue)
			return replace(n->right, prevValue, newValue);
		else if (n->getData() > prevValue)
			return replace(n->left, prevValue, newValue);
		else {
			n->data = newValue;
			return true;
		}
	}
	return false;
}
bool Tree::replace(int prevValue, int newValue) {
	bool status = false;
	//cout << "Replace " << prevValue << " with " << newValue << " Replace Steps: ";
	status = replace(root, prevValue, newValue);
	//cout << "(" << status << ")" << endl;
	return status;
}
