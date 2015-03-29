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
	//cout << "addGPA: " << name << " " << " adding " << classGrade << " GPA: " << getGPA() << endl;
}
string Student::toString() {
	ostringstream out;
	out << ID << endl;
	out << name << endl;
	out << address << endl;
	out << phone << endl;
	out << getGPA();
	return out.str();
}
