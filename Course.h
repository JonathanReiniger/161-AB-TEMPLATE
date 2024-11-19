#ifndef COURSE_H
#define COURSE_H

#include "Student.h"

struct Course {
    Student roster[20];
    int numStudents;
};

Course initCourse();
Student findStudentHighestGPA(Course course);
void readStudent(std::ifstream &inFile, Course &course);
void addStudent(Student student, Course &course);
void printRoster(Course course);
void dropStudent(char *lastname, Course &course);

#endif