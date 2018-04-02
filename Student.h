//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_STUDENT_H
#define ATTENDANCE_STUDENT_H

#include "User.h"

class Student : public User {
    string rollNumber;
public:

	//constructor taking argument as name and rollNumber
    Student(const string name, const string rollNum);

    //constructor without any argument
    Student();

    //returns attribute rollNumber
    string getRollNum();
};


#endif //ATTENDANCE_STUDENT_H
