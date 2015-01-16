#include <iostream>
#include <string>
#include <sstream>
#include "Arena.h"
#include "FighterInterface.h"
#include "Fighter.h"
using namespace std;

bool Arena::addFighter(string info) {
	string name;
	char type;
	int hp;
	int strength;
	int speed;
	int magic;
	
	istringstream strm;
	strm.str(info);
	strm >> name;
	strm >> type;
	strm >> hp >> strength >> speed >> magic;

	return true;
}
bool Arena::removeFighter(string name) {
	return false;
}
FighterInterface* Arena::getFighter(string name) {
	Fighter* fighterpoint = new Fighter();
	return fighterpoint;
}
int Arena::getSize() {
	return 1;
}