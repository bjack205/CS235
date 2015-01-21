#include "Robot.h"


Robot::Robot(string name_in, int hp_in, int strength_in, int speed_in, int magic_in)
:Fighter(name_in, hp_in, strength_in, speed_in, magic_in)
{
	this->electricity_max = magic * 2;
	this->electricity_current = electricity_max;
	this->bonus_damage = 0;
}

int Robot::getElectricity_current()
{
	return electricity_current;
}

int Robot::getDamage()
{
	return strength + bonus_damage;
}

void Robot::reset()
{
	Fighter::reset();
	electricity_current = electricity_max;
	bonus_damage = 0;
}

void Robot::regenerate()
{
	Fighter::regenerate();
}


bool Robot::useAbility()//Shockwave Punch
{
	if (electricity_current >= ROBOT_ABILITY_COST)
	{
		bonus_damage = int (strength * (pow(double(electricity_current)/double(electricity_max),4.0)));
		electricity_current -= ROBOT_ABILITY_COST;
		return true;
	}
	else
	{
		//cout << "**Not Enough Electricity**" << endl;
		bonus_damage = 0;
		return false;
	}
}