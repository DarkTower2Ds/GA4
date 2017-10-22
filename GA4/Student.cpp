#include <iostream>
#include "Student.h
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

Student::Student(){
    studentID = 0;
    studentGrade = 0;
}

Student::Student(int newID){
    studentID = newID;
    srand(time(NULL));
    studentGrade = rand()%100 + 1;
}

Student::~Student() {}

int Student::operator+(const Student& next) {
    int total;

    total = this->studentGrade + next.studentGrade;
    return total;
}

int Student::operator+(const int& first, const Student &next){
    int totalOfThreeGrades;

    totalOfThreeGrades = first + next.studentGrade;
    return totalOfThreeGrades;
}


//friend function
void print(Student temp){
    cout<<"Student "<<temp.studentID<<": "<<"Grade "<<temp.studentGrade;
}
