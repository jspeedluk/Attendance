//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_DATABASE_HANDLER_H
#define ATTENDANCE_DATABASE_HANDLER_H

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#define INT_MAX 1000
#define PRINT_WEAK_PASSWORD cout << "Yout password must be 6 to 13 digit , contain a number and an Upper Case alphabet !\nReenter your password.\n";
#include "Faculty.h"

using namespace std;

class Faculty;
class Database_handler {
    //map storing faculty names and their passwords
    map<string, string> facultyMap;
    //vector storing roll number of students
    map<string,string> studentsMap;
public:
    Database_handler();

    /*input is an object of student
    add student to studentsMap with name and roll number
    writes map to file studentsList.txt*/
    void addStudent(Student);
    
    /*checking presence of student and 
    returning name of student if student is present
    else returns "not present" */
    string getStudent(string);

    /*removes student from map studentsMap and
    writes back the whole map studentsMap to  file studentsList.txt
    does not check for verification of student as it is checked before calling*/
    void deleteStudent(const string); //not working

    /*name and password of faculty is added to the 
    file faculty_details.txt and facultyMap*/
    void addFaculty(Faculty);

    /*takes name of faculty as argument and 
    returns password of faculty from the map*/
    string getFaculty(string);
    /*takes the name of the faculty as argument and 
    deletes it from facultyMap and updates faculty_details.txt */
    void deleteFaculty(const string);
    /*takes password(string) as an argument and returns true if
    it has min 1 UpperCase , number and 6<=string.length()<=13 */
    bool passwordStrength(string);

};


#endif //ATTENDANCE_DATABASE_HANDLER_H
