//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_FACULTY_H
#define ATTENDANCE_FACULTY_H

#include "User.h"
#include "Database_handler.h"

class Database_handler;
class Faculty : public User {
    string password;
    Database_handler *db;
public:
    void addStudent();

    void deleteStudent();

    void setStudent();

    void modifyStudent();

    void addAttendance();

    bool setPassword();

    string getPassword();

    void modifyAttendance();

    const void facultyDashboard();
    Faculty(const string &basic_string, const string & ,Database_handler &);
};


#endif //ATTENDANCE_FACULTY_H
