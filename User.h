//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_USER_H
#define ATTENDANCE_USER_H

#include <string>
using namespace std;
class User {
protected:
    string name;
public:
    User(const string &name);
    User() {name="Default";} ;

    void setName();

    string getName();

    void viewAttendance();

    void viewDefaulters();
};


#endif //ATTENDANCE_USER_H
