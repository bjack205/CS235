#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>

#include "School.h"
#include "StudentInterface.h"
#include "Student.h"

//Extras
bool validFile(ifstream& myfile) {
	int numLines = 0;
	string line;
	while (getline(myfile, line)) {
		numLines++;
	}
	if (numLines % 4 > 0)
		return false;
}
void School::setGradeConverter() {
	grades["A"] = 4.0;
	grades["A-"] = 3.7;
	grades["B+"] = 3.4;
	grades["B"] = 3.0;
	grades["B-"] = 2.7;
	grades["C+"] = 3.4;
	grades["C"] = 2.0;
	grades["C-"] = 1.7;
	grades["D+"] = 1.4;
	grades["D"] = 1.0;
	grades["D-"] = 0.7;
	grades["E"] = 0;
}

map<unsigned long long int, StudentInterface*> School::getMap() {
	return IDlist;
}
set<StudentInterface*, Comparator> School::getSet() {
	return roster;
}
bool School::importStudents(string mapFileName, string setFileName) {
	ifstream mapFile(mapFileName.c_str());
	ifstream setFile(setFileName.c_str());

	if ((mapFile.is_open()) && (setFile.is_open())) {
		int numLines = 0;
		string line;
		if (!validFile(mapFile))
			return false;
		if (!validFile(setFile))
			return false;

		//Return to beginning of file
		mapFile.clear();
		setFile.clear();
		mapFile.seekg(0, ios::beg);
		setFile.seekg(0, ios::beg);

		//Read in Map
		while (getline(mapFile, line)) {
			unsigned long long int newID = atoi(line.c_str());
			string newName;
			string newAddress;
			string newPhone;

			getline(mapFile, line);
			newName = line;
			getline(mapFile, line);
			newAddress = line;
			getline(mapFile, line);
			newPhone = line;
			Student* newStudent = new Student(newName, newID, newPhone, newAddress);
			IDlist[newID] = newStudent;
		}
		//Read in Map
		while (getline(setFile, line)) {
			unsigned long long int newID = atoi(line.c_str());
			string newName;
			string newAddress;
			string newPhone;

			getline(setFile, line);
			newName = line;
			getline(setFile, line);
			newAddress = line;
			getline(setFile, line);
			newPhone = line;
			Student* newStudent = new Student(newName, newID, newPhone, newAddress);
			roster.insert(newStudent);
		}
		return true;
	}
	else {
		cout << "Files not read" << endl;
		return false;
	}
}
bool School::importGrades(string fileName) {
	ifstream file(fileName.c_str());

	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			unsigned long long int ID = atoi(line.c_str());
			string stuClass;
			string gradeLetter;
			double gradePoints;

			getline(file, line);
			stuClass = line;
			getline(file, line);
			gradeLetter = line;
			gradePoints = grades[gradeLetter];

			StudentInterface* student;
			if (IDlist.find(ID) != IDlist.end()) { //Student is in the Map
				student = IDlist[ID];
				student->addGPA(gradePoints);
			}
		}
	}
	else {
		return false;
	}
	return true;
}

