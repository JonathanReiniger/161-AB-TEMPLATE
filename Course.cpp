#include <iostream>
#include <cstring>
#include "Course.h"

using namespace std;

Course initCourse() {
    Course course;
    course.numStudents = 0;
    return course;
}

Student initStudent(const char *first, const char *last, double gpa) {
    Student student;
    strncpy(student.firstname, first, sizeof(student.firstname) - 1);
    student.firstname[sizeof(student.firstname) - 1] = '\0';
    strncpy(student.lastname, last, sizeof(student.lastname) - 1);
    student.lastname[sizeof(student.lastname) - 1] = '\0';
    student.gpa = gpa;
    return student;
}

void readStudent(ifstream &inFile, Course &course) {
    char first[101], last[101];
    double gpa;

    while (course.numStudents < 20 && inFile >> last >> first >> gpa) {
        Student student = initStudent(first, last, gpa);
        addStudent(student, course);
    }
}

void addStudent(Student student, Course &course) {
    if (course.numStudents < 20) {
        course.roster[course.numStudents] = student;
        course.numStudents++;
    }
}

void printRoster(Course course) {
    cout << "Here is the course roster:" << endl;
    for (int i = 0; i < course.numStudents; i++) {
        cout << course.roster[i].firstname << ";"
             << course.roster[i].lastname << ";"
             << course.roster[i].gpa << endl;
    }
}

void dropStudent(char *lastname, Course &course) {
    for (int i = 0; i < course.numStudents; i++) {
        if (strcmp(course.roster[i].lastname, lastname) == 0) {
            for (int j = i; j < course.numStudents - 1; j++) {
                course.roster[j] = course.roster[j + 1];
            }
            course.numStudents--;
            break;
            }
        }
    }}

    Student findStudentHighestGPA(Course course) {
        if (course.numStudents == 0) {
            throw std::runtime_error("No students in the course.");
        }
        Student highest = course.roster[0];
        for (int i = 1; i < course.numStudents; i++) {
            if (course.roster[i].gpa > highest.gpa) {
                highest = course.roster[i];
            }
        }
        return highest;
    }

    void printStd(Student student) {
        cout << student.firstname << ";"
             << student.lastname << ";"
             << student.gpa << endl;
    }
    
