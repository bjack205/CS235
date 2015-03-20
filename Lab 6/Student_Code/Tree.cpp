#include <iostream>
#include <string>

#include "Tree.h"

using namespace std;

Node* Tree::getRootNode() {
	return root;
}
bool Tree::add(int data) {
	add(root, data);
	return true;
}
bool Tree::add(Node*& n, int data) {
	if (n == NULL) {
		n = new Node(data);
		return true;
	}
	else if (n->data == data) {
		return false;
	}
	else if (data < n->data) {
		return add(n->left, data);
	}
	else if (data > n->data) {
		return add(n->right, data);
	}
	return false;
}
bool Tree::remove(int data) {
	return remove(root,data);
}
bool Tree::remove(Node*& n, int data) {
	if (n == NULL) {
		return false;
	}
	else if (data < n->data) {
		return remove(n->left, data);
	}
	else if (data > n->data) {
		return remove(n->right, data);
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
			n->data = replacement;
		}
		return true;
	}
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