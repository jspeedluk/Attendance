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

    void loginFaculty();

    void _register();

    void homeView();

    void loginAdmin();

};


#endif //ATTENDANCE_INTERFACE_HANDLER_H
