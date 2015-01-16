/*
 * main.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: bjack205
 */

#include <iostream>
#include <string>
#include <vector>
#include "Fighter.h"

using namespace std;

int main()
{
	Fighter Jack ("Jackson",10,10,10);


	int hp;
	hp = Jack.getHP();

	cout << "Jack's hp is " << hp << endl;

}



