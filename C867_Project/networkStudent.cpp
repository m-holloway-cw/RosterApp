#include "pch.h"
#include "networkStudent.h"


NetworkStudent::NetworkStudent() :Student()
{
	degree = NETWORKING;
}

NetworkStudent::NetworkStudent(string id, string fName, string lName, string email, int age, int days[], Degree degree)
	: Student(id, fName, lName, email, age, days)
{
	degree = NETWORKING;
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORKING;
}

void NetworkStudent::print()
{
	//print out degree type to go along with other student info
	this->Student::print();
	cout << "Degree type: NETWORKING." << endl;
}

//destructor
NetworkStudent::~NetworkStudent()
{
	//calls super destructor for this object
	Student::~Student();
	//no other dynamic variables declared in this class	
}
