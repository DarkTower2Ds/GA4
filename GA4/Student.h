

#ifndef GROUPASSIGNMENT4_STUDENT_H
#define GROUPASSIGNMENT4_STUDENT_H

class Student {
private:
    int studentID;
    int studentGrade;
public:
    Student();
    Student(int );
    ~Student();
    friend void print(Student temp);
    int operator+(const Student& );
    int operator+(const int&, const Student&);

};

#endif //GROUPASSIGNMENT4_STUDENT_H
