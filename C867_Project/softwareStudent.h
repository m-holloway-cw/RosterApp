#pragma once
#include "student.h"
#include "degree.h"
#include <string>
using namespace std;

class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	SoftwareStudent(
		string id, 
		string fName,
		string lName,
		string email,
		int age,
		int days[],
		Degree degree
	);


	Degree getDegreeProgram();
	void print();

	~SoftwareStudent();
};

