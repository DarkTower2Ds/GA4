#ifndef GROUPASSIGNMENT4_STUDENT_H
#define GROUPASSIGNMENT4_STUDENT_H

class Student
{
private:
    int studentID;
    int studentGrade;
public:
	friend int operator+(const int&, const Student&);
	friend void print(Student temp);

    Student();
    Student(int);
    ~Student();
	void reconstruct(int);
    int operator+(const Student& );
};

#endif //GROUPASSIGNMENT4_STUDENT_H
