#include "Arena.h"
#include "Fighter.h"
#include "Robot.h"
#include "Archer.h"
#include "Cleric.h"
#include <sstream>
#include <cctype>

int find_name (vector<FighterInterface*> list, string name)
{
	for (int i =- 0; i < list.size(); i++)
	{
		if (name == list[i]->getName())
		{
			return i;
		}
	}
	return -1;
}

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

Arena::Arena(){}

bool Arena::addFighter (string info)
{

	string name;
	string type;
	int hp;
	int strength;
	int speed;
	int magic;
		
	istringstream ss(info);
	string input;

	//Name
	ss >> input;
	name = input;
	if (find_name(list, name) >= 0)
	{
		cout << "**Error. Name already exists**" << endl;
		return false;
	}
	if (ss.fail())
	{
		cout << "**Error. Not enough input**" << endl;
		return false;
	}

	//Fighter Class
	ss >> input;
	type = input;
	if (type != "R" && type != "A" && type != "C")
	{
		cout << "**Error. Invalid Fighter Class**" << endl;
		return false;
	}
	if (ss.fail())
	{
		cout << "**Error. Not enough input**" << endl;
		return false;
	}


	//Hit Points
	ss >> input;
	hp = atoi(input.c_str());
	if (hp <= 0 || !check_int(input))
	{
		cout << "**Error. HP must be a positive integer**" << endl;
		return false;
	}
	if (ss.fail())
	{
		cout << "**Error. Not enough input**" << endl;
		return false;
	}


	//Strength
	ss >> input;
	strength = atoi(input.c_str());
	if (strength <= 0 || !check_int(input))
	{
		cout << "**Error. Strength must be a positive integer**" << endl;
		return false;
	}
	if (ss.fail())
	{
		cout << "**Error. Not enough input**" << endl;
		return false;
	}


	//Speed
	ss >> input;
	speed = atoi(input.c_str());
	if (speed <= 0 || !check_int(input))
	{
		cout << "**Error. Speed must be a positive integer**" << endl;
		return false;
	}
	if (ss.fail())
	{
		cout << "**Error. Not enough input**" << endl;
		return false;
	}


	//Magic
	ss >> input;
	magic = atoi(input.c_str());
	if (magic <= 0 || !check_int(input))
	{
		cout << "**Error. Magic must be a positive integer**" << endl;
		return false;
	}
	if (ss.fail())
	{
		cout << "**Error. Not enough input**" << endl;
		return false;
	}


	//Check additional invalid input
	ss >> input;
	if (!ss.fail())
	{
		cout << "**Error. Additional Input**" << endl;
		return false;
	}
	
	
	
	if (type == "R")
	{
		//cout << name << " is a Robot" << endl;
		list.push_back(new Robot(name, hp, strength, speed, magic));
	}
	if (type == "A")
	{
		//cout << name << " is an Archer" << endl;
		//list.push_back(new Archer(name, hp, strength, speed, magic));
		list.push_back(new Archer(name, hp, strength, speed, magic));
	}
	if (type == "C")
	{
		//cout << name << " is a Cleric" << endl;
		//Create Cleric
		list.push_back(new Cleric(name, hp, strength, speed, magic));
	}
	cout << name << " has " << hp << " HP, " << strength << " Strength, " << speed << " Speed, and " << magic << " Magic." << endl;
	
	return true;
}

bool Arena::removeFighter(string name)
{
	int name_index = find_name(list, name);
	if (name_index >= 0)
	{
		list.erase(list.begin()+name_index);
		return true;
	}
	else
	{
		cout << "**Errror. Fighter doesn't exist**" << endl;
		return false;
	}
}

FighterInterface* Arena::getFighter(string name)
{
	if (list.size() == 0)
	{
		return NULL;
	}
	else
	{
		int name_index = find_name(list, name);
		if (name_index >= 0)
		{
			return list[name_index];
		}
		else
		{
			cout << "**Error. Fighter doesn't exist**" << endl;
			return NULL;
		}
	}
}

int Arena::getSize()
{
	return list.size();
}