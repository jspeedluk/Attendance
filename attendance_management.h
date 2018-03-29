//
// Created by Kavish Gambhir on 21/03/18.
//

#ifndef ATTENDANCE_ATTENDANCE_MANAGEMENT_H
#define ATTENDANCE_ATTENDANCE_MANAGEMENT_H


//
// Created by Kavish Gambhir on 21/03/18.
//

#include <iostream>
#include <fstream>
#include <map>
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

class User {
    string name;
public:
    void setName();

    void getName();

    void viewAttendance();

    void viewDefaulters();
};

class Faculty : public User {
    string password;
public:
    void addStudent();

    void deleteStudent();

    void setStudent();

    void modifyStudent();

    void addAttendance();

    void setPassword();

    const void facultyDashboard();
};

class Student : public User {
    string rollNumber;
};

class Interface_handler {
    static int adminPasswordCount;
    Database_handler *db;
public:
    Interface_handler();

    void loginFaculty();

    void _register();

    void homeView();

    void loginAdmin();

    friend bool passwordStrength(string);
};

class Admin : public Faculty {
private:
    Interface_handler handler;
public:
    void addFaculty();

    void setFaculty();

    void getFaculty();

    void adminDashboard();

    void deleteFaculty();

};


#endif //ATTENDANCE_ATTENDANCE_MANAGEMENT_H
