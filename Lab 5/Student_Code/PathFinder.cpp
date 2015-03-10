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
vector<string> PathFinder::solveMaze() {
	vector<string> solution;
	return solution;
}

//Extras
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
