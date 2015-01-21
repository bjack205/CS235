#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
#include <stdlib.h>
#include "Arena.h"
#include "FighterInterface.h"
#include "Fighter.h"
using namespace std;

bool check_int (string input)
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

bool Arena::addFighter(string info) {
	string name;
	string type;
	int hp;
	int strength;
	int speed;
	int magic;
	
	istringstream strm;
	string input;
	strm.str(info);

	//Name
	strm >> input;
	name = input;
	if (list.count(name) == 1) {
		cout << "Name already used" << endl;
		return false;
	}
	if (strm.fail()) return false;

	//Class
	strm >> input;
	type = input;
	if (type != "R" && type != "C" && type != "A") {
		cout << "Invalid Type" << endl;
		return 0;
	}
	if (strm.fail()) return false;

	//HP
	strm >> input;
	hp = atoi(input.c_str());
	if (hp <= 0 || !check_int(input))
	{
		cout << "**Error. HP must be a positive integer**" << endl;
		return false;
	}
	if (strm.fail()) return false;


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
