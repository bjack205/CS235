#include <iostream>
#include <string>
#include <map>
#include <set>

#include "Header.h"
using namespace std;

template<typename ItemType>
void print(ItemType items) {

	std::cout << '[';

	for (typename ItemType::iterator i = items.begin(); i != items.end(); i++) {
		if (i != items.begin())
			std::cout << ", ";
		std::cout << '\'' << (*i)->getName() << '\'';
	}

	std::cout << ']' << std::endl;

}
template<typename K, typename V>
void print(std::map<K, V> items) {

	std::cout << '{';

	for (typename std::map<K, V>::iterator i = items.begin(); i != items.end(); i++) {
		if (i != items.begin())
			std::cout << ", ";
		std::cout << i->first << '=' << (i->second)->getName();
	}

	std::cout << '}' << std::endl;

}

int main() {


	Student stu = Student("Brian Jackson", 7126718, "5128095246", "1400 Deer Horn Dr.", 40.0, 10);
	cout << stu.getGPA() << endl;
	stu.addGPA(3.5);
	cout << stu.getGPA() << endl;
	cout << stu.toString() << endl;

	School byu = School();
	cout << "Import: " << byu.importStudents("studentListMap_Large.txt", "studentListSet_Large.txt") << endl;
	//cout << "Import: " << byu.importStudents("studentList_Total.txt", "studentList_Total.txt") << endl;
	cout << "Import Invalid: " << byu.importStudents("studentListMap_Small.txt", "studentList_Invalid.txt") << endl;
	cout << "Import Grades: " << byu.importGrades("classList_Total.txt") << endl;

	map<unsigned long long int, Student*> IDlist = byu.getMap();
	set<Student*, Comparator> roster = byu.getSet();
	//print(IDlist);
	//print(roster);
	
	unsigned long long int ID = 105396824;
	//cout << "Name: " << IDlist[ID]->getName() << endl;
	//cout << "GPA: " << IDlist[ID]->getGPA() << endl;

	//Query Set
	cout << "\n" << "Query Set: " << endl;
	cout << byu.querySet("querySet_Small.txt") << endl;

	//Query Map
	cout << "\n" << "Query Map: " << endl;
	cout << byu.queryMap("queryMap_Small.txt") << endl;

	string input;
	cout << "Would you like to exit? (y/n): ";
	cin >> input;
	return 0;
}