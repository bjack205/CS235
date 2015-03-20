#include <iostream>
#include <string>

#include "Header.h"

using namespace std;

Tree testTree1() {
	Tree tree;
	tree.add(3);
	tree.add(2);
	tree.add(5);
	tree.add(6);
	tree.add(7);
	tree.add(3);
	tree.add(1);
	return tree;
}
Tree testTree2() {
	Tree tree;
	tree.add(1);
	return tree;
}
Tree testTree3() {
	Tree tree;
	tree.add(3);
	tree.add(2);
	tree.add(5);
	tree.add(7);
	tree.add(9);
	tree.add(3);
	tree.add(1);
	tree.add(8);
	tree.add(4);
	tree.add(6);
	return tree;
}
Tree testTree4() {
	Tree tree;
	tree.add(4);
	tree.add(10);
	tree.add(7);
	tree.add(5);
	tree.add(6);
	tree.add(9);
	tree.add(8);
	tree.add(1);
	tree.add(3);
	tree.add(2);
	tree.add(12);
	tree.add(13);
	tree.add(11);
	return tree;
}
int main() {


	Tree tree = testTree4();
	string treeString = tree.printTree();
	cout << treeString << endl;
	cout << "Max: " << tree.getMax(tree.getRootNode()) << endl;
	cout << "Remove: " << tree.remove(10) << endl;
	cout << tree.printTree() << endl;
	string input;
	cout << "Would you like to exit? (y/n): ";
	cin >> input;
	return 0;
}