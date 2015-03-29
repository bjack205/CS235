#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "Student.h"

using namespace std;

unsigned long long int Student::getID() {
	return ID;
}
string Student::getName() {
	return name;
}
string Student::getGPA() {
	ostringstream strm;
	double GPA;
	if (numClasses > 0)
		GPA = numPoints / (numClasses);
	else
		GPA = 0;
	strm << fixed << setprecision(2) << GPA;
	return strm.str();
}
void Student::addGPA(double classGrade) {
	numPoints = numPoints + classGrade;
	numClasses++;
}
string Student::toString() {
	ostringstream out;
	out << to_string(ID) << endl;
	out << name << endl;
	out << address << endl;
	out << phone << endl;
	out << getGPA() << endl;
	return out.str();
}