#pragma once

#include <iostream>
#include <string>
#include <map>
#include <set>

#include "StudentInterface.h"

using namespace std;

class School {
private:
	map<unsigned long long int, StudentInterface*> IDlist;
	set<StudentInterface*, Comparator> roster;
	map<string, double> grades;

	void setGradeConverter();
public:
	//Constructor
	School(){
		setGradeConverter();
	}

	//Functions
	map<unsigned long long int, StudentInterface*> getMap();
	set<StudentInterface*, Comparator> getSet();
	bool importStudents(string mapFileName, string setFileName);
	bool importGrades(string fileName);
	string querySet(string fileName);
	string queryMap(string fileName);
	void clear();

};