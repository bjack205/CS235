#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>

#include "Arena.h"
#include "Archer.h"
#include "Fighter.h"
#include "Robot.h"
#include "Archer.h"
#include "Cleric.h"

using namespace std;


void new_fighter (Arena &a1)
{
	ifstream infile;
	infile.open("newFighter.txt");
	string input;
	if (infile.is_open())
	{
		getline(infile, input);
	}
	a1.addFighter(input);
}

int main142()
{
	
	Cleric* cleric1 = new Cleric("Friar", 100, 100, 500, 10);
	Arena a1 = Arena();
	a1.addFighter("Creeper R 100 100 1 1");
	a1.addFighter("Cow R 10 2 1 3");
	a1.addFighter("Tinman R 100 5 1 7");
	a1.addFighter("Father_Braeburn C 90 4 12 20");
	a1.addFighter("Israphel A 90 12 16 1");
	//a1.addFighter("Gandalf C 1000 1000 1000 500");
	
	while (true)
	{
		string s = "chicken";
		s = s.substr(1);
		cout << s << endl;
		system("pause");

		
	}

	string input;
	int input_selection = 0;
	while (true)
	{
		cout << "Select an option:\n"
			"[1] getSize\n"
			"[2] addFighter\n"
			"[3] removeFighter\n"
			"[4] getFighter\n"
			"[5] Input Fighter\n"
			"Selection: ";
		cin >> input_selection;
		
		if (input_selection == 1)
		{
			cout << "Size: " << a1.getSize() << endl;
		}
		
		if (input_selection == 2)
		{
			string input;
			cout << "Input data: ";
			cin >> input;
			a1.addFighter(input);
		}
		if (input_selection == 3)
		{
			cout << "Name: ";
			cin >> input;
			a1.removeFighter(input);
		}
		if (input_selection == 4)
		{
			cout << "Name: ";
			cin >> input;
			a1.getFighter(input);
		}
		if (input_selection == 5)
		{
			new_fighter(a1);
		}
		//cout << a1.getFighter(input)->getMagic() << endl;
	}

	string name;
	cout << "Select a player: ";
	cin >> name;
	while (true)
	{
		cout << "\nSelect an option:\n"
			"[0] Change Fighter\n"
			"[1] Name\n"
			"[2] Max HP\n"
			"[3] Current HP\n"
			"[4] Strength\n"
			"[5] Speed\n"
			"[6] Magic\n"
			"[7] get Damage\n"
			"[8] take Damage\n"
			"[9] reset\n"
			"[10] regenerate\n"
			"[11] Use Ability\n"
			"Selection: ";
		cin >> input_selection;
		if (input_selection == 0)
		{
			cout << "Select a player: ";
			cin >> name;
		}
		if (input_selection == 1)
		{
			cout << "Name: " << a1.getFighter(name)->getName() << endl;
		}
		
		if (input_selection == 2)
		{
			cout << "Max HP: " << a1.getFighter(name)->getMaximumHP() << endl;
		}
		if (input_selection == 3)
		{
			cout << "Current HP: " << a1.getFighter(name)->getCurrentHP() << endl;
		}
		if (input_selection == 4)
		{
			cout << "Strength: " << a1.getFighter(name)->getStrength() << endl;
		}
		if (input_selection == 5)
		{
			cout << "Speed: " << a1.getFighter(name)->getSpeed() << endl;
		}
		if (input_selection == 6)
		{
			cout << "Magic: " << a1.getFighter(name)->getMagic() << endl;
		}
		if (input_selection == 7)
		{
			cout << "Damage: " << a1.getFighter(name)->getDamage() << endl;
		}
		if (input_selection == 8)
		{
			int damage;
			cout << "Damage taken: ";
			cin >> damage;
			a1.getFighter(name)->takeDamage(damage);
		}
		if (input_selection == 9)
		{
			a1.getFighter(name)->reset();
		}
		if (input_selection == 10)
		{
			a1.getFighter(name)->regenerate();
		}
		if (input_selection == 11)
		{
			a1.getFighter(name)->useAbility();
		}
	}

	/*
	string input;
	getline(cin, input);
	cout << "input: " << input << endl;

	istringstream ss(input);
	vector<string> test;
	string word;
	ss >> word;
	test.push_back(word);
	cout << test[0] << endl;
	ss >> word;
	test.push_back(word);
	cout << test[1] << endl;
	*/
	

	system("pause");
	return 0;
}
