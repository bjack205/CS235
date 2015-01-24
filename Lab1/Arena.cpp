#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
#include <stdlib.h>
#include "Header.h"
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

	//Strength
	strm >> input;
	strength = atoi(input.c_str());
	if (strength <= 0 || !check_int(input))
	{
		cout << "**Error. Strength must be a positive integer**" << endl;
		return false;
	}
	if (strm.fail()) return false;

	//Speed
	strm >> input;
	speed = atoi(input.c_str());
	if (speed <= 0 || !check_int(input))
	{
		cout << "**Error. Speed must be a positive integer**" << endl;
		return false;
	}
	if (strm.fail()) return false;

	//Magic
	strm >> input;
	magic = atoi(input.c_str());
	if (magic <= 0 || !check_int(input))
	{
		cout << "**Error. Magic must be a positive integer**" << endl;
		return false;
	}
	if (strm.fail()) return false;
	
	strm >> input;
	if (!strm.fail())
	{
		cout << "**Error. Additional Input**" << endl;
		return false;
	}

	
	if (type == "A") {
		list[name] = new Archer(name, hp, strength, speed, magic);
	}
	else if (type == "R") {
		list[name] = new Robot(name, hp, strength, speed, magic);
	}
	else if (type == "C") {
		list[name] = new Fighter(name, hp, strength, speed, magic);
	}
	cout << name << " has " << hp << " HP, " << strength << " Strength, " << speed << " Speed, and " << magic << " Magic." << endl;
	return true;
}
bool Arena::removeFighter(string name) {
	if (list.count(name) == 1) {
		list.erase(name);
		return true;
	}
	else {
		return false;
	}
}
FighterInterface* Arena::getFighter(string name) {
	if (list.count(name) == 1) {
		return list[name];
	}
	else return NULL;

	Fighter* fighterpoint = new Fighter();
	return fighterpoint;
}
int Arena::getSize() {
	return list.size();
}
