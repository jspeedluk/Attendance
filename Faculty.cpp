//
// Created by Kavish Gambhir on 29/03/18.
//
#include <iostream>
#include "Faculty.h"


Faculty::Faculty(const string &facultyName, const string &password ,Database_handler &db ) :
    User(facultyName) ,
    password(password) ,db(&db){}

const void Faculty::facultyDashboard() {
    cout<<"Welcome Dr. "<<this->name<<" to your Dashboard .\n";
    cout << "Enter 1 to View all attendance :\n";
    cout << "Enter 2 to view the list of defaulters :\n";
    cout << "Enter 3 to register a student in the course :\n";
    cout << "Enter 4 to modify a Students details :\n";
    cout << "Enter 5 to remove a registered student from the course :\n";
    cout << "Enter 6 to modify Attendance :\n";
    cout << "Enter 7 to add Attendance into the database :\n";
    cout << "Enter 8 to change password :\n";
    cout << "Enter 9 to log-out and return to Home:\n";
    unsigned int input;
    bool exit = 0;
    User *user;
    cin >> input;
    system("clear");
    switch (input) {
        case 1:
            this->viewAttendance();
            break;
        case 2:
            this->viewDefaulters();
            break;
        case 3:
            this->addStudent();
            break;
        case 4:
            this->modifyStudent();
            break;
        case 5:
            this->deleteStudent();
            break;
        case 6:
            this->modifyAttendance();
        case 7:
            this->addAttendance();
            break;
        case 8:
            exit=setPassword();
            break;
        case 9:
            cout << "Logging you out.......................\n";
            exit = true;
            break;
        default:
            cout << "Invalid choice\n";
    }
    if(exit)
        return ;
    this->facultyDashboard();
}




string Faculty::getPassword() {
    return password;
}

void Faculty::addStudent() {

}

void Faculty::deleteStudent() {

}

void Faculty::setStudent() {

}

void Faculty::modifyStudent() {

}

void Faculty::addAttendance() {

}

bool Faculty::setPassword() {
    string pass_original,pass_new;
    cout<<"Enter Existing Password :\n";
    cin>>pass_original;
    if(pass_original!=password)
    {
        system("clear");
        cout<<"Incorrect Password.\nRedirecting to Home...\n";
        return true;
    }
    cout<<"Enter new Password :\n";
    cin>>pass_new;
    this->password=pass_new;
    db->addFaculty(*this);
    return false;
}

void Faculty::modifyAttendance() {

}

