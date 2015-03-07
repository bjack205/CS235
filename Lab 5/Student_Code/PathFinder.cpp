#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

#include "PathFinder.h"


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
	maze[MAZELENGTH][MAZELENGTH][MAZELENGTH] = 1;
}

bool PathFinder::importMaze(string file_name) {
	ifstream mazefile(file_name);
	if (mazefile.is_open()) {
		for (int k = 0; k < MAZELENGTH; k++) {
			for (int j = 0; j < MAZELENGTH; j++) {
				for (int i = 0; i < MAZELENGTH; i++) {
					mazefile >> maze[i][j][k];
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
	
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