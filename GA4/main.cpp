#include <iostream>
using namespace std;

void main()
{
	int numOfStudents = 0;
	int numInGroup = 0;

	bool keepGoing = true;
	while (keepGoing)
	{
		cout << "Enter the number of students: ";
		cin >> numOfStudents;

		if ((numOfStudents != 6) || (numOfStudents != 10) || (numOfStudents != 12))
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
		students[i].setID((i + 1));
	}

	int temp = 1;
	for(int i = 0; i < numOfStudents; i++)
	{
		if (temp != numInGroup)
		{
			students[i].print();
			temp++;
		}
		else if ((temp == numInGroup) && (numInGroup == 2))
		{
			i--;

			cout << "Group Average = " << avgOf2(students[i - 1], students[i]) << endl;

			temp = 1;
		}
		else if ((temp == numInGroup) && (numInGroup == 3))
		{
			i--;

			cout << "Group Average = " << avgOf3(students[i - 2], students[i - 1], students[i]) << endl;

			temp = 1;
		}
		else if ((temp == numInGroup) && (numInGroup == 4))
		{
			i--;

			cout << "Group Average = " << avgOf2(students[i - 3], students[i - 2], students[i - 1], students[i]) << endl;

			temp = 1;
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

}

double avgOf3(Student a, Student b, Student c)
{

}

double avgOf4(Student a, Student b, Student c, Student d)
{

}