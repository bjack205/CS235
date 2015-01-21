#pragma once
#include "fighter.h"

class Robot :
	public Fighter
{
private:
	int electricity_max;
	int electricity_current;
	int bonus_damage;

public:
	Robot(string name_in, int hp_in, int strength_in, int speed_in, int magic_in);
	int getElectricity_current();

	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
};

