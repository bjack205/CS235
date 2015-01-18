#pragma once
#include "fighter.h"

class Cleric :
	public Fighter
{
private:
	int mana_current;
	int mana_max;
public:
	Cleric(string name_in, int hp_in, int strength_in, int speed_in, int magic_in);

	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
};

