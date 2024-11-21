//*****************************************************************************
// Author: Jonathan Reiniger
// Assignment: Assignment 6
// Date: November 14, 2024
// Description: The purpose of this program is to keep track of a course and its roster.
The course has a list of students and the number of students on the roster. Each student
has a first name, last name and gpa for the attributes. The program loads from a file
into the course roster - the functionalities are to add a student, remove a student, print the
roster, print a single student and to find the student with the highest gpa.
// Input: Need a students' last name to remove from the list - char lastname [101] - char array.
// Output: The output is the roster - an array of students Students list[] and its size from
  the course struct, Course course is the name of the variable that has the Student list[]
and its size.
// Sources: Assignment 6 sample
//*****************************************************************************
#include <iostream>
#include <fstream>
#include "Course.h"

using namespace std;

int main() {
    Course course = initCourse();
    ifstream inFile("students.txt");
    
    if (!inFile) {
        cout << "Error: Could not open file." << endl;
        return 1;
    }
    
    readStudent(inFile, course);
    printRoster(course);
    
    char lastname[101];
    cout << "Enter the last name of the student to drop: ";
    cin >> lastname;
    
    dropStudent(lastname, course);
    printRoster(course);
    
    try {
        Student highestGPAStudent = findStudentHighestGPA(course);
        cout << "The student with the highest GPA:" << endl;
        printStd(highestGPAStudent);
    } catch (const std::runtime_error &e) {
        cout << e.what() << endl;
    }
    
    cout << "Thank you for using my Student Roster program!!" << endl;
    
    return 0;
}

