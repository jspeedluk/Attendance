//
// Created by Kavish Gambhir on 21/03/18.
//

#ifndef ATTENDANCE_ATTENDANCE_MANAGEMENT_H
#define ATTENDANCE_ATTENDANCE_MANAGEMENT_H


//
// Created by Kavish Gambhir on 21/03/18.
//

#include <iostream>
using namespace std;
class User
{
	string name;
public:
	void setName();
	void getName();
	void viewAttendance();
	void viewDefaulters();
};
class Faculty : User
{
	string password;
public:
	void addStudent();
	void deleteStudent();
	void setStudent();
	void modifyStudent();
	void addAttendance();
	void setPassword();
	const void facultyDashboard();
};
class Student : User
{
	string rollNumber;
};
class Interface_handler
{
public:
	void loginFaculty();
	void _register();
	void homeView();
	void loginAdmin();
    friend bool passwordStrength(string);
};
class Admin : Faculty
{
public:
	void addFaculty();
	void setFaculty();
	void getFaculty();
	void adminDashboard();
	void deleteFaculty();

};
class Database_handler
{
public:
	static int callback(void *NotUsed, int argc, char **argv, char **azColName);
	void addStudent();
	void getStudent();
	void deleteStudent();
	void addFaculty();
	void getFaculty();
	void deleteFaculty();
};

#endif //ATTENDANCE_ATTENDANCE_MANAGEMENT_H
