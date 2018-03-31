//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_FACULTY_H
#define ATTENDANCE_FACULTY_H

#include "User.h"


class Faculty : public User {
    string password;
    //Database_handler *db;
public:
    void addStudent();

    void deleteStudent();

    void setStudent();

    void modifyStudent();

    void addAttendance();
    /*verify existing password, input new password, set new password*/
    bool setPassword();
    /*returns Faculty:password*/
    string getPassword();

    void modifyAttendance();
    /*register student, modify student, remove student, add Attendance, modify attendance view attendance/defaulters*/
    const void facultyDashboard();

    Faculty(const string &basic_string, const string & );
};


#endif //ATTENDANCE_FACULTY_H
