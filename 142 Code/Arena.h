#pragma once
#ifndef ARENA_H
#define ARENA_H

using namespace std; 
#include <iostream> 
#include <string>
#include <vector>
#include "ArenaInterface.h"
#include "FighterInterface.h"
#include "Fighter.h"


class Arena : public ArenaInterface
{
protected:
	string name;
	vector<FighterInterface*> list;


public:
	Arena();
	bool addFighter (string info);
	bool removeFighter (string name);
	FighterInterface* getFighter (string name);
	int getSize();

};






#endif