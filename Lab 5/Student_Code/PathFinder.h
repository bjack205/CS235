#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "Cell.h"
#include "PathfinderInterface.h"

//#define MAZELENGTH 5

const int MAZELENGTH = 5;

using namespace std;

class PathFinder : public PathfinderInterface {
private:
	int maze[MAZELENGTH][MAZELENGTH][MAZELENGTH];
	bool mazeLoaded;
public:

	PathFinder() : mazeLoaded(false) { resetMaze(); };

	//Part I
	string getMaze();
	void createRandomMaze();

	//Part II
	bool importMaze(string file_name);

	//Part III
	vector<string> solveMaze();

	//Extras
	void resetMaze();
	bool validMaze();
};
