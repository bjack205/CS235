#pragma once

#include <string>
#include "StudentInterface.h"

using std::string;

class Student : public StudentInterface {
private:
	string name;
	int ID;
	string phone;
	string address;
	double numPoints;
	int numClasses;

public:
	//Constructors
	Student() : 
		name(), ID(0), phone(), address(), numPoints(0), numClasses(0) {};
	Student(string name, int ID, string phone, string address) :
		name(name), ID(ID), phone(phone), address(address), numPoints(0), numClasses(0) {};
	Student(string name, int ID, string phone, string address, double numPoints, int numClasses) :
		name(name), ID(ID), phone(phone), address(address), numPoints(numPoints), numClasses(numClasses) {};

	//Operators
	friend std::ostream& operator<<(std::ostream& stream, Student& stu) {
		stream << stu.name;
		return stream;
	}

	unsigned long long int getID();
	string getName();
	string getGPA();
	void addGPA(double classGrade);
	string toString();
};
