#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    char firstname[101];
    char lastname[101];
    double gpa;
};

Student initStudent(const char *first, const char *last, double gpa);
void getLastName(char *studentName, Student student);
double getGPA(Student student);
void printStd(Student student);

#endif