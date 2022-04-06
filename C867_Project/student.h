#pragma once
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

class Student
{
public:
	Student();
	Student(string studentID, string fName, string lName, string email, int age, int time[]);
	
	virtual void print() = 0;
	const static int durationArraySize = 3;

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int * getNumDaysArray();
	virtual Degree getDegreeProgram() = 0;

	//setters
	void setStudentID(int newID);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setEmail(string email);
	void setAge(int age);
	void setNumDaysArray(int days[]);

	//destructor
	~Student();

protected:
	string studentID;
	string fName;
	string lName;
	string email;
	int age;
	int time[durationArraySize];
	Degree degree;
};

