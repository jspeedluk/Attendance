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
        facultyMap[facultyName] = password;
    }
//    auto  it=facultyMap.begin();
//    while(++it!=facultyMap.end()) cout<<it->first<<endl<<it->second<<endl; //for debug


}
string Database_handler::getFaculty(const string nameOfFaculty) {
    return facultyMap[nameOfFaculty];
}

void Database_handler::addFaculty(Faculty facultyObj) {
    ofstream file("faculty_details.txt",ios::out);
//    file.write((char*) &facultyObj,sizeof(facultyObj)); // try later
    facultyMap.erase(facultyObj.getName());
    auto  it=facultyMap.begin();
    while(++it!=facultyMap.end()) file<<it->first<<'\n'<<it->second<<'\n';
    facultyMap[facultyObj.getName().substr(0,'\n')]=facultyMap[facultyObj.getPassword().substr(0,'\n')];
    file<<facultyObj.getName()<<endl<<facultyObj.getPassword()<<endl;
    file.close();
}