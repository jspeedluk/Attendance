//
// Created by Kavish Gambhir on 29/03/18.
//

#include "Database_handler.h"
#include <algorithm>

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
    string facultyName, password, tempStudentName , tempStudentRollNumber;
    //forming map facultymap for faculty name and password
    while (!file.eof()) {
        getline(file, facultyName);
        if(file.eof())break;
        getline(file, password);
        facultyMap[facultyName] = password;
    }
    file.close();
    //forming map studentsMap of students using file StudentsList.txt
    fstream stfile( "StudentsList.txt" );
    while(!stfile.eof())
    {
        getline( stfile, tempStudentRollNumber );
        getline( stfile, tempStudentName );
        studentsMap[tempStudentRollNumber]=tempStudentName;
    }
    stfile.close();
//    auto  it=facultyMap.begin();
//    while(it!=facultyMap.end()) cout<<it->first<<endl<<it++->second<<endl; //for testing
//    auto  it2=studentsMap.begin();
//    while(it2!=studentsMap.end()) cout<<it2->first<<endl<<it2++->second<<endl; //for testing

}
string Database_handler::getFaculty(const string nameOfFaculty) {
    return facultyMap[nameOfFaculty];
}

void Database_handler::addFaculty(Faculty facultyObj) {   //NEEDS FIX
    ofstream file("faculty_details.txt",ios::out);
    facultyMap.erase(facultyObj.getName());
    auto  it=facultyMap.begin();
    while(++it!=facultyMap.end()) file<<it->first<<'\n'<<it->second<<'\n';
    facultyMap[facultyObj.getName()]=facultyObj.getPassword();
    file<<facultyObj.getName()<<endl<<facultyObj.getPassword()<<endl;
    file.close();
}

void Database_handler::deleteFaculty(const string nameOfFaculty) {
    facultyMap.erase(nameOfFaculty);
    ofstream file("faculty_details.txt",ios::out);
    auto it= facultyMap.begin();
    while(++it!=facultyMap.end()) file<<it->first<<endl<<it->second<<endl;
    file.close();
}

string Database_handler::getStudent(string rollNum) {
    string nameStudent;
    //checking presence of student in map studentsMap
    map<string,string>::iterator mapIterator = studentsMap.find(rollNum);
    if(mapIterator == studentsMap.end() )
    {
        return "not present";//means student is not present in database
    }
    else {
        //student is present thus return name from map studentsMap
        nameStudent = studentsMap[rollNum];
    }
    return nameStudent;

}

void Database_handler::addStudent(Student student) {
    //adding student to map studentsMap 
    this->studentsMap[student.getRollNum() ] = student.getName();
    //writing whole studentsMap Map to the file StudentsList.txt
    std::map<string,string>::iterator it = this->studentsMap.begin();
    fstream writeStudents( "StudentsList.txt" , ios::out);
    while(it!=this->studentsMap.end())
    {
        writeStudents << it->first <<'\n'<< it->second << endl;
        it++;
    }
    writeStudents.close();
    //to add student to presents count list with Zero attendance
    User tempUser;
    tempUser.addNewlyRegisteredStudent( student.getRollNum() );
}

void Database_handler::deleteStudent(const string rollNum) {
    //removing from map studentsMap
    std::map<string,string>::iterator mapIterator = studentsMap.find(rollNum);
    studentsMap.erase(mapIterator);
    //writing whole studentsMap Map to the file StudentsList.txt
    std::map<string,string>::iterator it1 = studentsMap.begin();
    fstream writeStudents1( "StudentsList.txt" , ios::out);
    while(it1!=studentsMap.end())
    {
        writeStudents1 << it1->first <<'\n'<< it1->second << endl;
        it1++;
    }
    writeStudents1.close();
}
