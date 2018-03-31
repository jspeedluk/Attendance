//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_STUDENT_H
#define ATTENDANCE_STUDENT_H

#include "User.h"

class Student : public User {
protected:
    string rollNumber;
public:

    /*returns rollNumber*/
    string getRollNumber();

    /*sets rollNumber as rollNumberToBeSet*/
    void setRollNumber(string rollNumberToBeSet);
};

#endif //ATTENDANCE_STUDENT_H
