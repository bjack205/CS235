#pragma once
#ifndef ARCHER_H
#define ARCHER_H
#include "Fighter.h"


class Archer
	: public Fighter
{
private:
	int speed_current;

public:
	Archer(string name_in, int hp_in, int strength_in, int speed_in, int magic_in);
	int getSpeed();

	int getDamage();
	void takeDamage(int damage);
	void reset();
	void regenerate();
	bool useAbility();

};






#endif