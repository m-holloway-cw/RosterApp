// C867_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "roster.h"
#include <algorithm>

Roster::Roster() 
{
	this->size = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int size)
{
	this->size = size;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[size];
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++) {
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}

Student * Roster::getStudentAtIndex(int index)
{
	return classRosterArray[index];
}

void Roster::parseRow(string row)
{
	//parse long strings
	if (lastIndex < size) {
		lastIndex++; // first pass puts lastIndex to 0

		//find student ID
		int commaIndex = row.find(",");
		string sID = row.substr(0, commaIndex);

		//find first name
		int nextIndex = commaIndex + 1;
		commaIndex = row.find(",", nextIndex);
		string fName = row.substr(nextIndex, commaIndex - nextIndex);

		//find last name
		nextIndex = commaIndex + 1;
		commaIndex = row.find(",", nextIndex);
		string lName = row.substr(nextIndex, commaIndex - nextIndex);

		//find email
		nextIndex = commaIndex + 1;
		commaIndex = row.find(",", nextIndex);
		string email = row.substr(nextIndex, commaIndex - nextIndex);

		//find age
		nextIndex = commaIndex + 1;
		commaIndex = row.find(",", nextIndex);
		int age = stoi(row.substr(nextIndex, commaIndex - nextIndex)); //stoi = string to integer

		//find days
		nextIndex = commaIndex + 1;
		commaIndex = row.find(",", nextIndex);
		int days1 = stoi(row.substr(nextIndex, commaIndex - nextIndex)); //stod = string to double

		nextIndex = commaIndex + 1;
		commaIndex = row.find(",", nextIndex);
		int days2 = stoi(row.substr(nextIndex, commaIndex - nextIndex)); //stod = string to double 

		nextIndex = commaIndex + 1;
		commaIndex = row.find(",", nextIndex);
		int days3 = stoi(row.substr(nextIndex, commaIndex - nextIndex)); //stod = string to double 

		//find degree
		Degree degree;
		nextIndex = commaIndex + 1;
		commaIndex = row.find(",", nextIndex);
		string degreeName = row.substr(nextIndex, commaIndex - nextIndex);
		if (degreeName == "SOFTWARE") {
			degree = SOFTWARE;
		} else if (degreeName == "SECURITY") {
			degree = SECURITY;
		} else  {
			degree = NETWORKING;
		}
	//add to classRosterArray at last index using add() function
		add(sID, fName, lName, email, age, days1, days2, days3, degree);
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree)
{
	//add days to the array
	days[0] = daysInCourse1;
	days[1] = daysInCourse2;
	days[2] = daysInCourse3;
	if (degree == SOFTWARE) {	
		classRosterArray[lastIndex] = new SoftwareStudent(
			studentID, firstName, lastName, emailAddress, age,
			days, degree
		);
	}
	else if (degree == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(
			studentID, firstName, lastName, emailAddress, age,
			days, degree
		);
	}
	else {
		classRosterArray[lastIndex] = new NetworkStudent(
			studentID, firstName, lastName, emailAddress, age,
			days, degree
		);
	}
}

void Roster::remove(string studentID) {
	bool found = false;
	//search for and remove matching student to studentID
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			cout << "Removing id: " << studentID << " from the class roster." << endl;
			delete this->classRosterArray[i];
			//remove gaps in array by moving last entry to empty spot and then decrementing index to match
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
			found = true;
		}
	}
	if (!found) 
	{
		cout << "Student ID: " << studentID << " not found in the class roster." << endl;
	}

}

void Roster::printAll() {
	for (int i = 0; i <= lastIndex; i++)
	{
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
		//print average of number of days in the three courses
	for (int i = 0; i <= lastIndex; i++){
		if (classRosterArray[i]->getStudentID() == studentID) 
		{
			int * arrayCopy = classRosterArray[i]->getNumDaysArray();
			double avg = (arrayCopy[0] + arrayCopy[1] + arrayCopy[2]) / 3;
			cout << "Average days for student id " << studentID << ": " << avg << endl;
		}
	}
	
}

void Roster::printInvalidEmails() {
		//should include @ and . but no " "
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		string email = classRosterArray[i]->getEmail();
		
		int indexAtSymbol = email.find("@");
		int indexDot = email.find(".", indexAtSymbol);
		int indexSpace = email.find(" ");
		if (indexAtSymbol == -1)
		{
			cout << "Invalid email found \t[no @ symbol]: \t\t" << email << " \tStudent ID: " << classRosterArray[i]->getStudentID() << endl;
			found = true;
		}
		else if (indexDot == -1)
		{
			cout << "Invalid email found \t[no . symbol after @]: \t" << email << " \tStudent ID: " << classRosterArray[i]->getStudentID() << endl;
			found = true;
		} 
		else if (indexSpace != -1) 
		{
			cout << "Invalid email found \t[contains a space]: \t" << email << " \tStudent ID: " << classRosterArray[i]->getStudentID() << endl;
			found = true;
		}
		else
		{
			//valid email
			//cout << "Valid email found: " << email << " Student ID: " << classRosterArray[i]->getStudentID() << endl;
		}
	}
	if (!found)
	{
		cout << "No invalid emails found" << endl;
	}
}

void Roster::printByDegreeProgram(int degreeProgram) {
		//prints student info for a degree program specified by enum type
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		Degree d = classRosterArray[i]->getDegreeProgram();
		if (d == degreeProgram)
		{
			found = true;
			classRosterArray[i]->print();
		}
	}
	if (!found) {
		cout << "No students found in specified degree program." << endl;
	}
}


int main()
{
	//Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.
	cout << endl;
	cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 001215316" << endl;
	cout << "Name: Michael Holloway" << endl;
	cout << endl;

	int numStudents = 5;
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Michael,Holloway,mhol186@wgu.edu,30,20,21,22,SOFTWARE"
	};

	Roster * classRoster = new Roster(numStudents);

	for (int i = 0; i < numStudents; i++)
	{
		//parse each row of data
		classRoster->parseRow(studentData[i]);
	}

	//print all entries per specified format
	classRoster->printAll();
	cout << endl;

	//print a check for invalid emails of entries
	classRoster->printInvalidEmails(); 
	cout << endl;

	for (int i = 0; i < numStudents; i++)
	{
		//print averages days in course by studentID from array
		string sID = classRoster->getStudentAtIndex(i)->getStudentID();
		classRoster->printAverageDaysInCourse(sID);
	}
	cout << endl;

	//print entries of a certain degree type	
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;

	//attempt to remove a student from roster by id
	classRoster->remove("A3");
	cout << endl;

	// should print student id not found
	classRoster->remove("A3");

	//	call destructor to release Roster object's memory
	classRoster->~Roster();

	return 0;
}

