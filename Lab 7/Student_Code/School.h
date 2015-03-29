#pragma once

#include <iostream>
#include <string>
#include <map>
#include <set>

#include "Student.h"
#include "StudentInterface.h"
#include "GPAInterface.h"

using namespace std;

class School : public GPAInterface {
private:
	map<unsigned long long int, StudentInterface*> IDlist;
	set<StudentInterface*, Comparator> roster;
	map<string, double> grades;

	void setGradeConverter();
	StudentInterface* RosterID(unsigned long long int ID);
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
	map<unsigned long long int, StudentInterface*> getMap();
	set<StudentInterface*, Comparator> getSet();
	bool importStudents(string mapFileName, string setFileName);
	bool importGrades(string fileName);
	string querySet(string fileName);
	string queryMap(string fileName);
	void clear();

};