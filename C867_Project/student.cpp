#include "pch.h"
#include "student.h"


Student::Student()
{
	this->studentID = "";
	this->fName = "";
	this->lName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < durationArraySize; i++) this->time[i] = 0;
}

Student::Student(string studentID, string fName, string lName, string email, int age, int time[])
{
	this->studentID = studentID;
	this->fName = fName;
	this->lName = lName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < durationArraySize; i++) this->time[i] = time[i];
}


//getters
string Student::getStudentID()
{
	return this->studentID;
}

string Student::getFirstName()
{
	return this->fName;
}

string Student::getLastName()
{
	return this->lName;
}

string Student::getEmail()
{
	return this->email;
}

int Student::getAge()
{
	return this->age;
}

int* Student::getNumDaysArray()
{
	return this->time;
}

//setters
void Student::setStudentID(int newID) 
{
	this->studentID = newID;
}

void Student::setFirstName(string fName) 
{
	this->fName = fName;
}

void Student::setLastName(string lName) 
{
	this->lName = lName;
}

void Student::setEmail(string email) 
{
	this->email = email;
}

void Student::setAge(int age) 
{
	this->age = age;
}

void Student::setNumDaysArray(int days[]) 
{
	for (int i = 0; i < durationArraySize; i++)
	{
		this->time[i] = days[i];
	}
}


void Student::print() {
	int* arrayCopy = this->getNumDaysArray();
		//print specific student data except for the degree type(comes from subclass)
	cout <<"ID: " << this->getStudentID() << 
		"\tFirst Name: " << this->getFirstName() << 
		"\tLast Name: " << this->getLastName() << 
		"\tAge: " << this->getAge() <<
		"\tdaysInCourse: {" << arrayCopy[0] << ", " << arrayCopy[1] << ", " << arrayCopy[2] <<
		"}\t";
}

	//destructor
Student::~Student()
{
	//no dynamic variables created outside locals inside function print()
	//nothing to destroy
}