//
// Created by Kavish Gambhir on 29/03/18.
//

#include "User.h"

//Constructor
User::User(const string &name) : name(name) {}

string User::getName() {
    return this->name;
}

void User::setName(string nameToBeFilled) {
    name = nameToBeFilled;
}

void User::viewAttendance() {

}

void User::viewDefaulters() {

}

