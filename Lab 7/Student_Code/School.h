#pragma once

#include <iostream>
#include <string>
#include <map>
#include <set>

#include "Student.h"
#include "StudentInterface.h"

using namespace std;

class School {
private:
	map<unsigned long long int, Student*> IDlist;
	set<Student*, Comparator> roster;
	map<string, double> grades;

	void setGradeConverter();
	Student* RosterID(unsigned long long int ID);
public:
	//Constructor
	School(){
		setGradeConverter();
	}
	//Destructor
	~School() {
		this->clear();
	}

	//Functions
	map<unsigned long long int, Student*> getMap();
	set<Student*, Comparator> getSet();
	bool importStudents(string mapFileName, string setFileName);
	bool importGrades(string fileName);
	string querySet(string fileName);
	string queryMap(string fileName);
	void clear();

};