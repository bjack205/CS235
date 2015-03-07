#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

#include "Student_Code\Cell.h"
#include "Student_Code\PathFinder.h"


using namespace std;

int main() {
	
	PathFinder finder;
	//cout <<	finder.importMaze("Invalid1.txt") << endl;
	string mazestring = finder.getMaze();
	//cout << mazestring << endl;
	for (int i = 0; i < 2; i++) {
		finder.createRandomMaze();
		mazestring = finder.getMaze();
		cout << mazestring;
		cout << "* * * * * * * * * * * * * * *" << endl;
	}
	cout << endl;

	

	string input;
	cout << "Would you like to exit? (y/n): ";
	cin >> input;
	return 0;
}