//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_FACULTY_H
#define ATTENDANCE_FACULTY_H

#include "Student.h"
#include "Database_handler.h"
#include <sstream>


class Database_handler;
class Faculty : public User {
    string password;
protected:
    Database_handler *db;
public:

    /*takes rollNumber from user, verify its existance
    addds only if not present, takes name from user, add student to database by
    calling function from databse_handler */
    void addStudent();
    
    /*function takes a +ve integer input and returns it otherwise
    an prints error and starts again */
    int takeint();

    /*takes rollNumber from user to be deleted
    verify existance of student, deletes only if student present
    deletes by calling delete function from database_handler*/
    void deleteStudent();

    void modifyStudent();

    void addAttendance();

    /*verifies existing password and then set the newly entered password*/
    bool setPassword();

    /*returns string password*/
    string getPassword();

    void modifyAttendance();

    //returns true if year is a leap year else returns false
    bool isLeapYear(unsigned short year);

    //1 for valid date, 0 for invalid date
    bool isValidDate(unsigned short year,unsigned short month,unsigned short day);

    /*Views all the functions available to the Admin.
     Uses switch case to make different function calls */
    const void facultyDashboard();
    /*Constructer assigns Name , password to the Faculty 
    and passes Reference of Database object from Interface_handler */
    Faculty(const string &basic_string, const string & ,Database_handler &);
};


#endif //ATTENDANCE_FACULTY_H
