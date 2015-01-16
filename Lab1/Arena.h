#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ArenaInterface.h"
using namespace std;

class Arena : public ArenaInterface
{
private:
	vector<FighterInterface*> roster;
public:
	Arena(){};
	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();
};
