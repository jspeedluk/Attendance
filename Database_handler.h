//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_DATABASE_HANDLER_H
#define ATTENDANCE_DATABASE_HANDLER_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include "Faculty.h"

using namespace std;

class Database_handler {
    /*Map storing name of faculty and maps with it's password
     * this map is initialized in the constructor of class database_handler*/
    map<string, string> facultyMap;
public:
    /*Constructor intializes tha map Database_handler::facultyMap from the file faculty_details.txt*/
    Database_handler();

    void addStudent();

    void getStudent();

    void deleteStudent();

    /*takes argument an object of faculty
     * adds its name and password to the map facultyMap and then writes the map
     * to the file faculty_details.txt*/
    void addFaculty(Faculty);

    /*name of faculty as argument and returns a pointer to the Faculty object of same credentials*/
    Faculty * getFaculty(const string);

    void deleteFaculty();

    friend bool passwordStrength(string);
};


#endif //ATTENDANCE_DATABASE_HANDLER_H
