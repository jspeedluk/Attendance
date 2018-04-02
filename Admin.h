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
	/*Constructor initialises handler and Passes values to Faculty */
    Admin(const string &basic_string, const string &,Database_handler &db, const Interface_handler &handler);
    /*Adds Faculty just like from Interface ( HOMEVIEW ) */
    void addFaculty();
    /*Changes the faculty's name or password as required by the user */
    void setFaculty();
	/*Views all the functions available to the Admin.
	 Uses switch case to make different function calls */
    void adminDashboard();
    /*Deletes a Faculty ( name and password) from faculty_details.txt
    and from facultyMap*/
    void deleteFaculty();

};


#endif //ATTENDANCE_ADMIN_H
