#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "Cell.h"
#define MAZELENGTH 5

using namespace std;

class PathFinder {
private:
	int maze[MAZELENGTH][MAZELENGTH][MAZELENGTH
	];
	bool mazeLoaded;
public:
	PathFinder() : mazeLoaded(false) { resetMaze(); };

	//Part I
	string getMaze();
	void createRandomMaze();

	//Part II
	bool importMaze(string file_name);

	//Extras
	void resetMaze();
	bool validMaze();
};