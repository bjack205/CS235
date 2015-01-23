#include <iostream>
#include <string>
#include <vector>
#include "Fighter.h"
#include "Arena.h"

using namespace std;

int main()
{
	//Cleric* cleric1 = new Cleric("Friar", 100, 100, 500, 10);
	Arena a1 = Arena();
	a1.addFighter("Father A 100 100 1 1");
	a1.addFighter("Jack R 10 2 1 3");
	a1.addFighter("Tinman R 100 5 1 7");
	a1.addFighter("Father_Braeburn C 90 4 12 20");
	a1.addFighter("Israphel A 90 12 16 1");

	string input;
	int input_selection;
	bool worked;
	while (true) {
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
	//system("pause");
	return 0;
}


