#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ArenaInterface.h"
using namespace std;

class Arena : public ArenaInterface
{
private:
	map<string, FighterInterface*> list;
public:
	Arena(){};
	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();
};
