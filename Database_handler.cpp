//
// Created by Kavish Gambhir on 29/03/18.
//

#include "Database_handler.h"

bool Database_handler::passwordStrength(string str) {
    int countNumber, countUC;
    countNumber = countUC = 0;
    for (char i : str) {
        if (i >= 65 && i <= 90) countUC++;
        if (i >= '0' && i <= '9') countNumber++;
    }
    return countNumber && countUC && str.length() >= 6 && str.length() <= 13;
}
Database_handler::Database_handler() {
    fstream file("faculty_details.txt", ios::in);
    string facultyName, password;

    while (!file.eof()) {
        getline(file, facultyName);
        getline(file, password);
        facultyMap[facultyName] = password;
    }
//    auto  it=facultyMap.begin();
//    while(++it!=facultyMap.end()) cout<<it->first<<endl<<it->second<<endl; //for testing


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

string Database_handler::getStudent(string rollNum) {
    FILE *file;
    string nameStudent,filePath;
    filePath=PATH_STUDENT+rollNum+".txt";
    file=fopen(filePath.c_str(), "r");
    if(!(bool)file)
    {
        return "not present";
    }
    else {
        ifstream file_2(PATH_STUDENT + rollNum + ".txt");
        getline(file_2,nameStudent);
    }
    return nameStudent;

}

void Database_handler::addStudent(Student student) {
    fstream file(PATH_STUDENT+student.getRollNum()+".txt",ios_base::out);
    file<<student.getName();
}

void Database_handler::deleteStudent(const string rollNum) {
    string temp=PATH_STUDENT+rollNum+".txt";
    remove(temp.c_str()); //It's not working
}

void Database_handler::deleteFaculty(const string nameOfFaculty) {
    facultyMap.erase(nameOfFaculty);
    ofstream file("faculty_details.txt",ios::out);
    auto it= facultyMap.begin();
    while(++it!=facultyMap.end()) file<<it->first<<endl<<it->second<<endl;
    file.close();
}
