#include <iostream>
#include <string>
#include <algorithm>

#include "Header.h"

using namespace std;

int main() {

	Tree tree;
	tree.add(4);
	tree.add(9);
	tree.add(5);
	cout << tree.printTree() << endl;

	tree.add(1);
	tree.add(3);
	cout << tree.printTree() << endl;

	tree.add(2);
	cout << tree.printTree() << endl;

	tree.add(7);
	cout << tree.printTree() << endl;

	tree.add(8);
	cout << tree.printTree() << endl;

	tree.add(6);
	tree.updateHeight(tree.getRootNode());
	cout << tree.printTree() << endl;;
	string input;
	cout << "Would you like to exit? (y/n) ";
	cin >> input;
	return 0;
}