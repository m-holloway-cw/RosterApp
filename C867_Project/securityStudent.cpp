#include "pch.h"
#include "securityStudent.h"

SecurityStudent::SecurityStudent() :Student()
{
	degree = SECURITY;
}

SecurityStudent::SecurityStudent(string id, string fName, string lName, string email, int age, int days[], Degree degree)
	: Student(id, fName, lName, email, age, days)
{
	degree = SECURITY;
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	//print out degree type to go along with other student info
	this->Student::print();
	cout << "Degree type: SECURITY." << endl;
}

//destructor
SecurityStudent::~SecurityStudent()
{
	//calls super destructor for this object
	Student::~Student();
	//no other dynamic variables declared in this class
}

