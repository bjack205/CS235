#include "Cleric.h"


Cleric::Cleric(string name_in, int hp_in, int strength_in, int speed_in, int magic_in)
:Fighter(name_in, hp_in, strength_in, speed_in, magic_in)
{
	this->mana_max = 5 * magic;
	this->mana_current = mana_max;
	cout << mana_max << endl;
}

int Cleric::getDamage()
{
	return magic;
}

void Cleric::reset()
{
	Fighter::reset();
	mana_current = mana_max;
}

void Cleric::regenerate()
{
	Fighter::regenerate();
	int mana_bonus = magic / 5;
	if (mana_bonus < 1) mana_bonus = 1;
	if (mana_current + mana_bonus > mana_max)
	{
		mana_current = mana_max;
	}
	else
	{
		mana_current += mana_bonus;
	}
}


bool Cleric::useAbility()//Healing Light
{
	if (mana_current >= CLERIC_ABILITY_COST)
	{
		int bonus_hp = magic / 3;
		if (bonus_hp < 1) bonus_hp = 1;
		if (hp_current + bonus_hp > hp_max)
			hp_current = hp_max;
		else
			hp_current += bonus_hp;
		mana_current -= CLERIC_ABILITY_COST;
		return true;
	}
	else
	{
		cout << "**Not Enough Mana**" << endl;
		return false;
	}
}