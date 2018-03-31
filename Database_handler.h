//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_DATABASE_HANDLER_H
#define ATTENDANCE_DATABASE_HANDLER_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <cstdio>
#define  PATH_STUDENT "/Users/gambhir/Desktop/Attendance/cmake-build-debug/students/"
#define PRINT_WEAK_PASSWORD cout << "Yout password must be 6 to 13 digit , contain a number and an Upper Case alphabet !\nReenter your password.\n";
#include "Faculty.h"

using namespace std;

class Faculty;
class Database_handler {
    map<string, string> facultyMap;
public:
    Database_handler();
    void addStudent(Student);

    string getStudent(string);

    void deleteStudent(const string); //not working

    void addFaculty(Faculty);

    string getFaculty(string);

    void deleteFaculty(const string);
    bool passwordStrength(string);

};


#endif //ATTENDANCE_DATABASE_HANDLER_H
