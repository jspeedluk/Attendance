//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_INTERFACE_HANDLER_H
#define ATTENDANCE_INTERFACE_HANDLER_H

#include "Database_handler.h"

using namespace std;

class Interface_handler {
    static int adminPasswordCount;
    Database_handler *db;
public:
    Interface_handler();
    /*login screen for faculty, verifying password, directing to faculty dashboard*/
    void loginFaculty();
    /*Register as Faculty screen, verify Admin password, input name and password, register as Faculty*/
    void _register();
    /*Admin login, Faculty login, register new faculty, View All Attendance/Defaulters, exit*/
    void homeView();
    /*login screen for admin, verify admin password, directing to admin dashboard*/
    void loginAdmin();

    friend bool passwordStrength(string);
};


#endif //ATTENDANCE_INTERFACE_HANDLER_H
