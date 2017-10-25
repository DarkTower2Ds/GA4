#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
    studentID = 0;
	studentGrade = 0;
}

Student::Student(int newID)
{
    studentID = newID;
    studentGrade = rand()%100 + 1;
}

Student::~Student() {}

int Student::operator+(const Student& next)
{
    int total;
    total = this->studentGrade + next.studentGrade;

    return total;
}

void Student::reconstruct(int inID)
{
	studentID = inID;
	studentGrade = rand() % 100 + 1;
}