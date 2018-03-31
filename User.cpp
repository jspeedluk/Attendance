//
// Created by Kavish Gambhir on 29/03/18.
//

#include <iostream>
#include "User.h"
#include <map>
#include <vector>
#include <fstream>

User::User(const string &name) : name(name) {}


string User::getName() {
    return this->name;

}

void User::viewAttendance() { //trial

    system("clear");
    string rollNum,date;
    int present;
    cout<<"Showing All Attendance :\n\n";
    map<string,int> dateMap;
    map<string,map<string,int> > attendance;
    fstream file("table.txt",ios::in);
    while(!file.eof())
    {
        file>>rollNum;
        file>>date;
        file>>present;
//        cout<<rollNum<<date<<present<<endl;
        attendance[rollNum][date]=present;
    }
    auto it=attendance.begin();
    while(it!=attendance.end())
    {
        cout<<it->first<<endl;
        auto it2=(it->second).begin();
        while(it2!=(it->second).end()) cout<<it2->first<<"      "<<it2++ ->second<<endl;
        it++;

    }



}

void User::setName() {

}

void User::viewDefaulters() {

}
