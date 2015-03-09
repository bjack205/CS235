#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>

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

bool PathFinder::importMaze(string file_name) {
	string line;
	string input;
	ifstream myfile(file_name.c_str());
	int numinput;
	int zeros = 0;
	int ones = 0;
	int i = 0, j = 0, k = 0;
	while (getline(myfile, line)) {
		istringstream lstream;
		lstream.str(line);
		i = 0;
		while (lstream >> input) {
			if (check_int(input)) {
				numinput = atoi(input.c_str());
				if (numinput == 0)
					zeros++;
				else if (numinput == 1)
					ones++;
				else
					return false;
				//cout << i << " " << j << " " << k << endl;
				maze[i][j][k] = numinput;
			}
			else
				return false;
			i++;
		}
		if (i == 0) {
			if (j != MAZELENGTH)
				return false;
			j = -1;
			k++;
		}
		else if (i != MAZELENGTH)
			return false;
		j++;
		if (k > MAZELENGTH)
			return false;
	}
	if (k != MAZELENGTH - 1)
		return false;
	if ((maze[0][0][0] != 1) || (maze[MAZELENGTH - 1][MAZELENGTH - 1][MAZELENGTH - 1] != 1))
		return false;
	
	return true;
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
