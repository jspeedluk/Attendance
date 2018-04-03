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
    bool exit;
	/*constructer initialises default private attributes */
    Interface_handler();
    /* takes name and password from user and verifies both from 
    facultyMap in Database and calls Faculty ::facultyDashboard
    otherwise prints appropriate message. */
    void loginFaculty();
    /* Registers new faculty and stores it into facultyMap and database.
    Requires admin Password. takes Faculty Name , Password.
    Only Strong Passwords are accepted. User reenters the entered password 
    to confirm registration (max 3 times allowed) */
    void _register();
    /* Main View which launches at start, uses switch case
    to call all functions. */
    void homeView();
    /* takes admin password from user and verifies if it's correct.
     and calls Admin ::adminDashboard
    otherwise prints appropriate message.
    MAXIMUM 3 incorrect tries allowed Consecutively  */
    void loginAdmin();

};


#endif //ATTENDANCE_INTERFACE_HANDLER_H
