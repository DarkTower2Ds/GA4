#include <iostream>
#include "Student.h"
using namespace std;

double avgOf2(Student, Student);
double avgOf3(Student, Student, Student);
double avgOf4(Student, Student, Student, Student);

void main()
{
	int numOfStudents = 0;
	int numInGroup = 0;

	bool keepGoing = true;
	while (keepGoing)
	{
		cout << "Enter the number of students: ";
		cin >> numOfStudents;
		cout << "You entered: " << numOfStudents << " students" << endl;

		if ((numOfStudents != 6) && (numOfStudents != 10) && (numOfStudents != 12))
		{
					cout << "ERROR: INVALID NUMBER OF STUDENTS. MUST BE 6, 10, OR 12" << endl;
		}
		else
		{
			cout << "Enter the number of students in each group: ";
			cin >> numInGroup;
			cout << "---" << endl;
			
			if ((numInGroup < 2) || (numInGroup > 4))
			{
				cout << "ERROR: INVALID NUMBER OF STUDENTS PER GROUP. MUST BE BETWEEN 2 AND 4" << endl;
			}
			else if (((numOfStudents == 6) || (numOfStudents == 10)) && (numInGroup == 4))
			{
				cout << "ERROR: CANNOT SPLIT STUDENTS EVENLY INTO GROUPS" << endl;
			}
			else if ((numOfStudents == 10) && (numInGroup == 3))
			{
				cout << "ERROR: CANNOT SPLIT STUDENTS EVENLY INTO GROUPS" << endl;
			}
			else
			{
				keepGoing = false;
			}
		}
	}

	Student *students;
	students = new Student[numOfStudents];

	for (int i = 0; i < numOfStudents; i++)
	{
		students[i].reconstruct(i + 1);
	}

	int temp = 0;
	for(int i = 0; i < numOfStudents + 1; i++)
	{
		if ((temp != numInGroup) && (i != numOfStudents))
		{
			print(students[i]);
			temp++;
		}
		else if ((temp == numInGroup) && (numInGroup == 2))
		{
			i--;

			cout << "Group Average = " << avgOf2(students[i - 1], students[i]) << endl << endl;

			temp = 0;
		}
		else if ((temp == numInGroup) && (numInGroup == 3))
		{
			i--;

			cout << "Group Average = " << avgOf3(students[i - 2], students[i - 1], students[i]) << endl << endl;

			temp = 0;
		}
		else if ((temp == numInGroup) && (numInGroup == 4))
		{
			i--;

			cout << "Group Average = " << avgOf4(students[i - 3], students[i - 2], students[i - 1], students[i]) << endl << endl;

			temp = 0;
		}
		else if (i == numOfStudents)
		{
			//ta-da! This magically prevents the following error message from being displayed when, in fact, nothing is wrong...
		}
		else
		{
			cout << "ERROR: THERE'S BEEN A TERRIBLE MISTAKE" << endl;
		}
	}

	delete [] students;

	system("pause");
}

double avgOf2(Student a, Student b)
{
	return (a + b) / 2;
}

double avgOf3(Student a, Student b, Student c)
{
	Student d;
	d = a + b;
	return (d + c) / 3;
}

double avgOf4(Student a, Student b, Student c, Student d)
{
	Student e, f;
	e = a + b;
	f = c + d;
	return (e + f) / 4;
}

//friend functions
void print(Student temp)
{
	cout << "Student " << temp.studentID << ": " << "Grade " << temp.studentGrade << endl;
}

int operator+(const int &first, const Student &next)
{
	int totalOfThreeGrades;
	totalOfThreeGrades = first + next.studentGrade;

	return totalOfThreeGrades;
}