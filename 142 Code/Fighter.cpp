#include "Fighter.h"


Fighter::Fighter(string name_in, int hp_in, int strength_in, int speed_in, int magic_in)
{
	this->name = name_in;
	this->hp_max = hp_in;
	this->hp_current = hp_max;
	this->strength = strength_in;
	this->speed = speed_in;
	this->magic = magic_in;
}

Fighter::Fighter(){}

string Fighter::getName()
{
	return name;
}

int Fighter::getMaximumHP()
{
	return hp_max;
}

int Fighter::getCurrentHP()
{
	return hp_current;
}

int Fighter::getStrength()
{
	return strength;
}

int Fighter::getSpeed()//Archer Specific
{
	return speed;
}

int Fighter::getMagic()
{
	return magic;
}

int Fighter::getDamage()//Class Specific
{
	return 0;
}

void Fighter::takeDamage(int damage)//Archer Specific
{
	int dodge = speed / 4;
	int damage_taken = damage - dodge;
	if (damage_taken < 1) damage_taken = 1;
	cout << "Damage taken: " << damage_taken << endl;
	hp_current -= damage_taken;
}

void Fighter::reset()//Class Specific
{
	hp_current = hp_max;
}

void Fighter::regenerate()//Cleric Specific
{
	if (hp_current < hp_max)
	{
		int regeneration = strength / 6;
		if (regeneration < 1) regeneration = 1;
		if (hp_max - hp_current >= regeneration)
			hp_current += regeneration;
		else
			hp_current = hp_max;
	}
	else
	{
		//cout << "**Already at max HP**" << endl;
	}
}

bool Fighter::useAbility()
{
	return false;
}