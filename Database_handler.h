//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_DATABASE_HANDLER_H
#define ATTENDANCE_DATABASE_HANDLER_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

class Database_handler {
    map<string, string> faculty;
public:
    Database_handler();
    void addStudent();

    void getStudent();

    void deleteStudent();

    void addFaculty();

    string getFaculty(string);

    void deleteFaculty();

    friend bool passwordStrength(string);
};


#endif //ATTENDANCE_DATABASE_HANDLER_H
