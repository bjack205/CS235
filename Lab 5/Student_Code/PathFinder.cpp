#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <math.h>

#include "PathFinder.h"

using namespace std;

//Extra Functions
bool check_int(string input)
{

	for (int i = 0; i < input.length(); i++)
	{
		char letter = input[i];
		if (!isdigit(letter))
		{
			//cout << "Not Integer" << endl;
			return false;
		}
	}
	return true;
}
//Part I
string PathFinder::getMaze() {
	ostringstream out;
	for (int k = 0; k < MAZELENGTH; k++) {
		for (int j = 0; j < MAZELENGTH; j++) {
			for (int i = 0; i < MAZELENGTH; i++) {
				out << maze[i][j][k] << " ";
			}
			out << endl;
		}
		out << endl;
	}
	return out.str();
}
void PathFinder::createRandomMaze() {
	for (int k = 0; k < MAZELENGTH; k++) {
		for (int j = 0; j < MAZELENGTH; j++) {
			for (int i = 0; i < MAZELENGTH; i++) {
				maze[i][j][k] = rand() % 2;
			}
		}
	}
	maze[0][0][0] = 1;
	maze[MAZELENGTH-1][MAZELENGTH-1][MAZELENGTH-1] = 1;
}


//Part II
string PathFinder::readMazeFile(string file_name) {
	string line;
	string input;
	ifstream myfile(file_name.c_str());
	ostringstream out;
	int numinput;
	int i = 0, j = 0, k = 0;
	while (getline(myfile, line)) {
		istringstream lstream;
		lstream.str(line);
		while (lstream >> input) {
			out << input << " ";
		}
		out << endl;
	}
	return out.str();
}
bool PathFinder::validMaze(string mazeString) {
	istringstream mazeStr;
	string line;
	string input;
	int count = 0;
	int x = 0;
	int y = 0;
	int z = 0;

	mazeStr.str(mazeString);
	while (getline(mazeStr, line)) {
		istringstream lstream;
		lstream.str(line);
		x = 0;
		// Read in row
		while (lstream >> input) {
			if (check_int(input)) {
				int numInput = atoi(input.c_str());
				if ((numInput != 0) && (numInput != 1))
					return false; //Integer other than 1 or 0
				x++;
				count++;
				if ((count == 1) && (numInput != 1))
					return false; //Start value not 1
				if ((count == pow(MAZELENGTH, 3)) && (numInput != 1))
					return false; //Last value not 1
			}
			else
				return false; //Non-integer
		}
		if (x == 0) { //Blank line
			if (y != MAZELENGTH)
				return false; //more or less than 5 rows
			y = -1;
			z++;
		}
		else if (x != MAZELENGTH)
			return false; //more or less than 5 columns
		y++;
	}
	if (z != MAZELENGTH - 1)
		return false; //more or less than 5 sets
	return true;
}
void PathFinder::readInMazeString(string mazeString) {
	istringstream mazeStr;
	string output;
	mazeStr.str(mazeString);
	for (int k = 0; k < MAZELENGTH; k++){
		for (int j = 0; j < MAZELENGTH; j++) {
			for (int i = 0; i < MAZELENGTH; i++) {
				mazeStr >> output;
				maze[i][j][k] = atoi(output.c_str());
			}
		}
	}
}
bool PathFinder::importMaze(string file_name) {
	string mazeString = readMazeFile(file_name);
	bool valid = validMaze(mazeString);
	if (valid) {
		readInMazeString(mazeString);
		return true;
	}
	return false;
}

//Part III
bool isLocation(string result) {
	if (result.substr(0, 1) == "(")
		return true;
	return false;
}
string locationString(int x, int y, int z) {
	string locString = "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
	return locString;
}
vector<string> PathFinder::solveCell(int x, int y, int z) {
	vector<string> path;
	//Base Cases
	if ((x >= MAZELENGTH) || (y >= MAZELENGTH) || (z >= MAZELENGTH) ||
		(x < 0) || (y < 0) || (z < 0)) {
		path.push_back("Out of Bounds");
		cout << locationString(x, y, z) << " Out of Bounds" << endl;
		return path;
	}
	else {
		int value = maze[x][y][z];
		if (value == 0) {
			path.push_back("Wall");
			cout << locationString(x, y, z) << " Wall" << endl;
			return path;
		}
		else if (value == 2) {
			path.push_back("Visited");
			cout << locationString(x, y, z) << " Visited" << endl;
			return path;
		}
		else {
			maze[x][y][z] = 2;
			if ((x == MAZELENGTH - 1) && (y == MAZELENGTH - 1) && (z == MAZELENGTH - 1)) {
				string location = locationString(x, y, z);
				path.push_back(location);
				cout << locationString(x, y, z) << " Exit Found" << endl;
				return path;
			}
			else {
				vector<string> north = solveCell(x, y + 1, z);
				vector<string> south = solveCell(x, y - 1, z);
				vector<string> east = solveCell(x + 1, y, z);
				vector<string> west = solveCell(x - 1, y, z);
				vector<string> up = solveCell(x, y, z + 1);
				vector<string> down = solveCell(x, y, z - 1);
				if (isLocation(north.front())) {
					north.insert(north.begin(), locationString(x, y, z));
					cout << locationString(x, y, z) << " Solving" << endl;
					return north;
				}
				if (isLocation(south.front())) {
					south.insert(south.begin(), locationString(x, y, z));
					cout << locationString(x, y, z) << " Solving" << endl;
					return south;
				}
				if (isLocation(east.front())) {
					east.insert(east.begin(), locationString(x, y, z));
					cout << locationString(x, y, z) << " Solving" << endl;
					return east;
				}
				if (isLocation(west.front())) {
					west.insert(west.begin(), locationString(x, y, z));
					cout << locationString(x, y, z) << " Solving" << endl;
					return west;
				}
				if (isLocation(up.front())) {
					up.insert(up.begin(), locationString(x, y, z));
					cout << locationString(x, y, z) << " Solving" << endl;
					return up;
				}
				if (isLocation(down.front())) {
					down.insert(down.begin(), locationString(x, y, z));
					cout << locationString(x, y, z) << " Solving" << endl;
					return down;
				}
				path.push_back("No Path");
				cout << locationString(x, y, z) << " No Path" << endl;
				return path;
			}
		}
	}
}
vector<string> PathFinder::solveMaze() {
	int mazecopy[MAZELENGTH][MAZELENGTH][MAZELENGTH];
	copyArray(maze, mazecopy);
	vector<string> solution = solveCell(0, 0, 0);
	copyArray(mazecopy, maze);
	if (!isLocation(solution.front()))
		solution.clear();
	return solution;
}

//Extras
void PathFinder::copyArray(int original[MAZELENGTH][MAZELENGTH][MAZELENGTH], int copy[MAZELENGTH][MAZELENGTH][MAZELENGTH]) {
	for (int k = 0; k < MAZELENGTH; k++) {
		for (int j = 0; j < MAZELENGTH; j++) {
			for (int i = 0; i < MAZELENGTH; i++) {
				copy[i][j][k] = original[i][j][k];
			}
		}
	}
}
void PathFinder::resetMaze() {
	for (int k = 0; k < MAZELENGTH; k++) {
		for (int j = 0; j < MAZELENGTH; j++) {
			for (int i = 0; i < MAZELENGTH; i++) {
				maze[i][j][k] = 1;
			}
		}
	}
}
bool PathFinder::validMaze() {
	int zeros = 0;
	int ones = 0;
	for (int k = 0; k < MAZELENGTH; k++) {
		for (int j = 0; j < MAZELENGTH; j++) {
			for (int i = 0; i < MAZELENGTH; i++) {
				if (maze[i][j][k] == 1)
					ones++;
				else if (maze[i][j][k] == 0)
					zeros++;
				else
					return false;
			}
		}
	}
	if (maze[0][0][0] != 1)
		return false;
	if (maze[MAZELENGTH - 1][MAZELENGTH - 1][MAZELENGTH - 1] != 1)
		return false;

	return false;
}
