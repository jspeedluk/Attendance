//
// Created by Kavish Gambhir on 29/03/18.
//

#include "Student.h"

Student::Student(const string name, const string rollNum) {
    this->name=name;
    this->rollNumber=rollNum;
}

string Student::getRollNum() {
    return this->rollNumber;
}
