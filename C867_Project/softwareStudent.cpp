#include "pch.h"
#include "softwareStudent.h"



SoftwareStudent::SoftwareStudent() :Student()
{
	degree = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string id, string fName, string lName, string email, int age, int days[], Degree degree)
	: Student(id, fName, lName, email, age, days)
{
	degree = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::print() 
{
	//print out degree type to go along with other student info
	this->Student::print();
	cout << "Degree type: SOFTWARE." << endl;
}

//destructor
SoftwareStudent::~SoftwareStudent()
{
	//calls super destructor for this object
	Student::~Student();
	//no other dynamic variables declared in this class
}
