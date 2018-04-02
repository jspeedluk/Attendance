//
// Created by Kavish Gambhir on 29/03/18.
//

#include "Student.h"

//constructor with argument as name and rollnumber
//intiliazes the attributes - name , rolNumber
Student::Student(const string name, const string rollNum) {
    this->name=name;
    this->rollNumber=rollNum;
}

//constructor without any argument
//creates object without initilization
Student::Student(){}

string Student::getRollNum() {
    return this->rollNumber;
}
