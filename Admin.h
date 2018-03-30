//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_ADMIN_H
#define ATTENDANCE_ADMIN_H

#include <iostream>
#include "Faculty.h"
#include "Interface_handler.h"

class Admin : public Faculty {
private:
    Interface_handler handler;
public:
    Admin(const string &basic_string, const string &,Database_handler &db, const Interface_handler &handler);

    void addFaculty();

    void setFaculty();

    void getFaculty();

    void adminDashboard();

    void deleteFaculty();

};


#endif //ATTENDANCE_ADMIN_H
