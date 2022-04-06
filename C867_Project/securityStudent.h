#pragma once
#include "student.h"
#include <string>
#include "degree.h"
using namespace std;

class SecurityStudent: public Student
{
public:
	SecurityStudent();
	SecurityStudent(
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

	~SecurityStudent();
};

