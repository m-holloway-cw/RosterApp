#pragma once
#include <string>
#include "student.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include <iostream>
using namespace std;

class Roster
{
public:
	Roster();
	Roster(int size);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
	void printAll();
	void remove(string stutendID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);

	Student* getStudentAtIndex(int index);
	void parseRow(string row);
	~Roster();

private:
	Student** classRosterArray;
	int lastIndex;
	int size;
	int days[3];
};

