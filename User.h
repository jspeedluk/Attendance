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

    /*argument: string name to be filled
     *sets the string as name*/
    void setName(string);

    /*returns string User:name*/
    string getName();

    void viewAttendance();

    void viewDefaulters();
};


#endif //ATTENDANCE_USER_H
