#include "Archer.h"


Archer::Archer(string name_in, int hp_in, int strength_in, int speed_in, int magic_in)
:Fighter(name_in, hp_in, strength_in, speed_in, magic_in)
{
	this->speed_current = speed;
}

int Archer::getSpeed()
{
	return speed_current;//Changed to speed_current
}

int Archer::getDamage()
{
	return speed_current;
}

void Archer::takeDamage(int damage)
{
	int dodge = speed_current / 4;//Changed to speed_current
	int damage_taken = damage - dodge;
	if (damage_taken < 1) damage_taken = 1;
	cout << "Damage taken: " << damage_taken << endl;
	hp_current -= damage_taken;
}

void Archer::reset()
{
	Fighter::reset();
	speed_current = speed;
}

void Archer::regenerate()
{
	Fighter::regenerate();
}


bool Archer::useAbility()//Quickstep
{
	speed_current++;
	return true;
}