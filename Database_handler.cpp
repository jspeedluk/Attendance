//
// Created by Kavish Gambhir on 29/03/18.
//

#include "Database_handler.h"

Database_handler::Database_handler() {
    fstream file("faculty_details.txt", ios::in);
    string facultyName, password;
    while (!file.eof()) {
        getline(file, facultyName);
        getline(file, password);
        faculty[facultyName] = password;
    }
}
string Database_handler::getFaculty(const string nameOfFaculty) {
    return faculty[nameOfFaculty];
}
