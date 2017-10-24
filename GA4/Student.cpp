#include <iostream>
#include "Student.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

Student::Student()
{
    studentID = 0;
    studentGrade = 0;
}

Student::Student(int newID)
{
    studentID = newID;
    srand(time(NULL));
    studentGrade = rand()%100 + 1;
}

Student::~Student() {}

int Student::operator+(const Student& next)
{
    int total;
    total = this->studentGrade + next.studentGrade;

    return total;
}