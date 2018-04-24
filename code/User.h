//
// Created by Kavish Gambhir on 29/03/18.
//

#ifndef ATTENDANCE_USER_H
#define ATTENDANCE_USER_H

#include <string>
#include <map>
#include <vector>
using namespace std;
class Database_handler;
class User {
protected:
    string name;
    bool exit;
public:
//maps student's rollNumber with numberOfPresents
	map<string,int> presentCountList;
	
	//maps date with rollNumber with bool present/absent
	map< string, map< string,bool > > dateRollnumber;

	//list of dates of lectures
	vector<string> lectureDates;

    //constructors
    User(const string &name);
    User();
    // void setName(); 
    void setName(string nameToBeSet);//unneccessary

    string getName();

    void viewAttendance();

    void viewDefaulters();

    //loads the file presentCount.txt TO map presentCountList
    void loadPresentCountList();

    //stores the map presentCountList TO presentCount.txt
    void storePresentCountList();

    //adds newly registered student to presentCountList with Zero presentCount
    void addNewlyRegisteredStudent(string givenRollNumber);

    //loads lecture dates from file lectureDatesfile.txt TO vector lectureDates
    void loadLectureDates();

    //stores the vector lectureDtaes TO file lectureDtaesfile.txt
    void storeLectureDates();
};


#endif //ATTENDANCE_USER_H
