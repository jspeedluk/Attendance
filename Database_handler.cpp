//
// Created by Kavish Gambhir on 29/03/18.
//

#include "Database_handler.h"

Database_handler::Database_handler() {
    // Creating the map using file
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

Faculty * Database_handler::getFaculty(const string nameOfFaculty) {
    Faculty * objFaculty = new Faculty;
    *objFaculty.setName(nameOfFaculty);
    *objFaculty.setPassword( facultyMap[nameOfFaculty] );
    return objFaculty;
}

void Database_handler::addFaculty(Faculty facultyObj) {
    facultyMap[ facultyObj.getName() ] = facultyObj.getPassword();
    // Now Write whole map ito the file faculty_details.txt
    /*
    ofstream file("faculty_details.txt",ios::out);
    //file.write((char*) &facultyObj,sizeof(facultyObj)); // try later
    auto  it=facultyMap.begin();
    while(++it!=facultyMap.end()) file<<it->first<<'\n'<<it->second<<'\n';
    facultyMap[facultyObj.getName().substr(0,'\n')]=facultyMap[facultyObj.getPassword().substr(0,'\n')];
    file<<facultyObj.getName()<<endl<<facultyObj.getPassword()<<endl;
    file.close();
     */
}
