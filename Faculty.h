//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_FACULTY_H
#define ATTENDANCE_FACULTY_H

#include "User.h"


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

    Faculty(const string &basic_string, const string &);
};


#endif //ATTENDANCE_FACULTY_H
