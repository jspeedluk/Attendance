//
// Created by Kavish Gambhir on 29/03/18.
//

#include <iostream>
#include "User.h"
#include <fstream>

User::User(const string &name) : name(name) , exit(0) {

       string temDate;
    fstream ldates( "lectureDatesfile.txt",ios::in );
    while(!ldates.eof())
    {
        ldates>>temDate;
        if(ldates.eof())break;
        lectureDates.push_back(temDate);
    }
    ldates.close();
        string tempRollNumber;
    int tempPresents;
    fstream lpresents( "presentCount.txt" ,ios::in );
    while(!lpresents.eof())
    {
        lpresents>>tempRollNumber;
        if(lpresents.eof())break;
        lpresents>>tempPresents;
        presentCountList[tempRollNumber]=tempPresents;
    }
    lpresents.close();

}

User::User()
{
    name = "Default";
    string temDate;
    fstream ldates( "lectureDatesfile.txt" );
    while(!ldates.eof())
    {
        ldates>>temDate;
        lectureDates.push_back(temDate);
    }
    ldates.close();
        string tempRollNumber;
    int tempPresents;
    fstream lpresents( "presentCount.txt" );
    while(!lpresents.eof())
    {
        lpresents>>tempRollNumber>>tempPresents;
        presentCountList[tempRollNumber]=tempPresents;
    }
    lpresents.close();
    exit=0;
}

string User::getName() {
    return this->name;

}

void User::viewDefaulters() {
    int numberOfLectures = lectureDates.size();
    cout<<"List of students who has their attendance below 85%\n";
    map<string,int>::iterator presentCountIterator = presentCountList.begin();
    while(presentCountIterator != presentCountList.end() )
    {
        double percentAttendance = ( presentCountIterator->second / ( numberOfLectures + 0.0 ) )*100;
        if( percentAttendance < 85 )
        {
            cout<< presentCountIterator->first << "\t" << percentAttendance <<endl;
        }
        presentCountIterator++;
    }
}

void User::viewAttendance() { 
    
    cout<<"Attendace of Each class is shown as Date - students who were Absent on that day\n";
    vector<string>::iterator dateIterator = lectureDates.begin();
    while( dateIterator !=lectureDates.end() )
    {
        string dateOfLecture = *dateIterator, tempStudentRollNumber;
        bool tempAttendanceStatus;
        cout<< dateOfLecture << " -- ";
        //opening file with name dateOfLecture
        fstream dateFile ( "./date/"+ dateOfLecture + ".txt" );
        while( !dateFile.eof() )
        {
            dateFile>>tempStudentRollNumber;
            if( dateFile.eof() )break;
            dateFile>>tempAttendanceStatus;
            //print Roll number of Student if Absent i.e. AttendanceStatus is false
            if( tempAttendanceStatus == false )cout<<tempStudentRollNumber<< "\t";
        }
        dateFile.close();
        cout<<"\n\n";
        dateIterator++;
    }
}
void User::loadPresentCountList()
{
    string tempRollNumber;
    int tempPresents;
    fstream lpresents( "presentCount.txt" );
    while(!lpresents.eof())
    {
        lpresents>>tempRollNumber;
        if(lpresents.eof())break;
        lpresents>>tempPresents;
        presentCountList[tempRollNumber]=tempPresents;
    }
    lpresents.close();
    return ;
}

void User::storePresentCountList()
{
    map<string,int>::iterator presentCountIterator = presentCountList.begin();
    fstream spresents( "presentCount.txt" );
    while(presentCountIterator != presentCountList.end() )
    {
        spresents<< presentCountIterator->first <<'\t'<< presentCountIterator->second <<endl;
        presentCountIterator++;
    }
    spresents.close();
    return ;
}

void User::addNewlyRegisteredStudent(string givenRollNumber)
{
    presentCountList[givenRollNumber]=0;
    storePresentCountList();
    return ;
}

void User::loadLectureDates()
{
 
        string temDate;
    fstream ldates( "lectureDatesfile.txt" );
    while(!ldates.eof())
    {
        ldates>>temDate;
        if(ldates.eof())break;
        lectureDates.push_back(temDate);
    }
    ldates.close();
    return ;
}

void User::storeLectureDates()
{
    vector<string>::iterator lectureDateIterator = lectureDates.begin();
    fstream sdates( "lectureDatesfile.txt" );
    while( lectureDateIterator != lectureDates.end() )
    {
        sdates<< *lectureDateIterator <<endl;
        lectureDateIterator++;
    }
    sdates.close();
    return ;
}
