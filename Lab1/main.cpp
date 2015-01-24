#include <iostream>
#include <string>
#include <vector>
#include "Header.h"

using namespace std;

int main()
{
	//Cleric* cleric1 = new Cleric("Friar", 100, 100, 500, 10);
	Arena a1 = Arena();
	a1.addFighter("Father A 100 1 1 1");
	a1.addFighter("Jack R 10 2 1 3");
	a1.addFighter("Tinman R 100 20 1 10");
	a1.addFighter("Father_Braeburn C 90 4 12 20");
	a1.addFighter("Israphel A 90 12 16 1");

	string input;
	int input_selection;
	bool worked;
	while (false) {
		cout << "Select an option:\n"
			"[1] getSize\n"
			"[2] addFighter\n"
			"[3] removeFighter\n"
			"[4] getFighter\n"
			"[5] Exit\n"
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
			if (a1.removeFighter(input))
				cout << input << " was removed from the area" << endl;
			else
				cout << input << " was not removed from the area" << endl;
		}
		if (input_selection == 4)
		{
			cout << "Name: ";
			cin >> input;
			FighterInterface* outputfighter;
			outputfighter = a1.getFighter(input);
			cout << outputfighter->getName() << " stats: " <<
				outputfighter->getMaximumHP() << " MaxHP, " <<
				outputfighter->getCurrentHP() << " HP, " <<
				outputfighter->getStrength() << "St, " <<
				outputfighter->getSpeed() << "Sp, " <<
				outputfighter->getMagic() << "M" << endl;
		}
		if (input_selection == 5)
		{
			return 0;
		}
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
			"[12] Exit\n"
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
			if (a1.getFighter(name)->useAbility())
				cout << "Ability used" << endl;
			else
				cout << "Ability not used" << endl;
		}
		if (input_selection == 12) {
			return 0;
		}
	}
	//system("pause");
	return 0;
}


