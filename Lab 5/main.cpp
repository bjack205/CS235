#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <array>
#include <stdlib.h>

#include "Student_Code\Cell.h"
#include "Student_Code\PathFinder.h"


using namespace std;



int main() {

	PathFinder finder;
	cout << "Valid?: " << finder.importMaze("Invalid1.txt") << endl;
	cout << "Valid?: " << finder.importMaze("Invalid2.txt") << endl;
	cout << "Valid?: " << finder.importMaze("Invalid3.txt") << endl;
	cout << "Valid?: " << finder.importMaze("Invalid4.txt") << endl;
	cout << "Valid?: " << finder.importMaze("Invalid5.txt") << endl;
	cout << "Valid?: " << finder.importMaze("Solvable1.txt") << endl;
	cout << "Valid?: " << finder.importMaze("Solvable2.txt") << endl;
	cout << "Valid?: " << finder.importMaze("Solvable3.txt") << endl;
	cout << "Valid?: " << finder.importMaze("Unsolvable1.txt") << endl;
	cout << "Valid?: " << finder.importMaze("Unsolvable2.txt") << endl;
	cout << "Valid?: " << finder.importMaze("Unsolvable3.txt") << endl;
	finder.createRandomMaze();
	string mazestring = finder.getMaze();
	//cout << mazestring << endl;
	for (int i = 0; i < 4; i++) {
		finder.createRandomMaze();
		mazestring = finder.getMaze();
		//cout << mazestring;
		//cout << "* * * * * * * * * * * * * * *" << endl;
	}
	cout << endl;

	string input;
	cout << "Would you like to exit? (y/n): ";
	cin >> input;
	return 0;
}