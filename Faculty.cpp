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
    string isBadInput;
    char input;
    User *user; //why??
    cin >> isBadInput;
    if(isBadInput.length()>1) input ='0';  //goes to defaults case for bad input
    else input=isBadInput.at(0);
    cin.ignore(INT_MAX,'\n');
    system("clear");
    switch (input) {
        case '1':
            this->viewAttendance();
            break;
        case '2':
            this->viewDefaulters();
            break;
        case '3':
            this->addStudent();
            break;
        case '4':
            this->modifyStudent();
            break;
        case '5':
            this->deleteStudent();
            break;
        case '6':
            this->modifyAttendance();
            break;
        case '7':
            this->addAttendance();
            break;
        case '8':
            exit=setPassword();
            break;
        case '9':
            cout << "Logging you out.......................\n";
            this->exit = true;
            break;
        default:
            cout << "Invalid choice\n";
    }
    if(!exit) this->facultyDashboard();
        return ;
    
}




string Faculty::getPassword() {
    return password;
}

void Faculty::addStudent() {
    system("clear");
    cout<<"You choose to Register a new Student :\n";
    string nameStudent,rollnumber;
    cout<<"Enter Students Roll number :\n";
    getline(cin,rollnumber);
    //checking for existance of student
    if(db->getStudent(rollnumber)=="not present")
    {
        //student is not present in database, asks again for name
        cout<<"Enter Student's Name :\n";
        getline(cin,nameStudent);
        Student student(nameStudent,rollnumber);
        db->addStudent(student);
        cout<<nameStudent<<" is successfully Registered.\n";
    } 
    else
    {
        cout<<"Student already Registered as :\n";
        cout<<db->getStudent(rollnumber); //name of student with existing roll number
    }

}

void Faculty::deleteStudent() {
    system("clear");
    cout<<"You choose to remove a registered student from the course :\n";
    cout<<"Enter Student roll number :\n";
    string rollNumber,name_temp;
    getline(cin,rollNumber);
    name_temp=db->getStudent(rollNumber);
    //checking for existance of student in database
    if(name_temp!="not present")
    {
        //means student is present in database
        string input="";
        cout<<"Are you sure you want to De-Register :\n"<<name_temp<<"\nfrom the coarse ? Enter 'y' or 'n' :\n";
        while(input!="y"&&input!="n") {
            getline(cin,input);
            if (input == "n") {
                cout<<"You choose to Cancel.\nRedirecting to your Dashboard :\n";
                return;
            } 
            else 
                if (input == "y") {
                    db->deleteStudent(rollNumber);
                    cout << name_temp << "\nis now de-registered from the course.\n";
                    return;
                } 
                else
                    cout << "Invalid Response !\nEnter Again.\n";
        }
    } 
    else
    {
        //student is not present in database
        cout<<"Student with Roll Number :\n"<<rollNumber<<"\nis Not Registered in this course. Try Again.\n";
        return;
    }
}

void Faculty::modifyStudent() {
    system("clear");
    cout<<"You choose to change name of a registered student of the course :\n";
    cout<<"Enter Student roll number :\n";
    string tempRollNumber,tempName;
    getline(cin,tempRollNumber);
    tempName=db->getStudent(tempRollNumber);
    //checking for existance of student in database
    if(tempName!="not present")
    {
        //means student is present in database, asking for new name
        cout<<"Please Enter the new Name for the student: ";
        getline(cin, tempName );
        db->deleteStudent(tempRollNumber);  //deleting previous student
        Student tempStudent( tempName , tempRollNumber);    //creating Student object
        db->addStudent(tempStudent);    //adding new student with same rollNumber but new Name
    } 
    else
    {
        //student is not present in database
        cout<<"Student with Roll Number :\n"<<tempRollNumber<<"\nis Not Registered in this course. Try Again.\n";
        return;
    }
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

void Faculty::addAttendance()
{
    unsigned short dd , mm , yyyy;
    cout<<"You are About to Add Attendance\n";
    cout<<"Enter Date of lecture (dd mm yyyy)\n";
    cout<<"Enter dd (01 <= dd <= 31) ";
    dd = takeint();
    cout<<"Enter mm (01<= mm <= 12) ";
    mm = takeint();
    cout<<"Enter yyyy (1950<=yyyy) ";
    yyyy = takeint();
    if( isValidDate(yyyy,mm,dd) == false )
    {
        cout<<"Invalid Date.\n";
        facultyDashboard();
        return ;
    }
    ostringstream s1;
    s1<<dd<<"-"<<mm<<"-"<<yyyy;
    string dateString = s1.str();   //to store date of lecture as string, used to create file
    vector<string> todayAbsents; //to store the roll number of students who ere absent today
    int todayAbsentsCount; //number of absents to determine for loop count
    string tempRollNumber , fileAddress; //to store roll number taken input from user
    cout<<"Enter the number of Students absent on the date: ";
    todayAbsentsCount=takeint();
    cout<<"Enter the roll Number of Students who were Absent today.\n";
    for (int i = 0; i < todayAbsentsCount; ++i)
    {
        cout<<i+1<<" : ";
        getline(cin,tempRollNumber);
        if(presentCountList.find(tempRollNumber)==presentCountList.end())
        {
            cout<<"Invalid Roll number. Enter Again:  ";
            i--;
        } else
        todayAbsents.push_back(tempRollNumber);
    }
    //if file with same date already exist then add (1) at the end of file name to create new
    ifstream isExist("./date/"+dateString + ".txt");
    if(isExist){
        fileAddress = "./date/"+dateString + "(1).txt";
        lectureDates.push_back(dateString+"(1)");
    }
    else{
        fileAddress = "./date/"+dateString + ".txt";
        lectureDates.push_back(dateString);
    }
    isExist.close();

    //stores attendance in map presentCountList, vector todayAbsents
    //writes to file rollNumber true(present)/false(absent), rollNumber presentCount
    map<string,int>::iterator strollnum = presentCountList.begin();
    fstream stoday(fileAddress , ios::out);
    while(strollnum != presentCountList.end() )
    {
        stoday<< strollnum->first <<'\t';
        std::vector<string>::iterator absentsIterator = todayAbsents.begin();
        while(*absentsIterator != strollnum->first && absentsIterator != todayAbsents.end() )
        {
            absentsIterator++;
        }
        if(absentsIterator == todayAbsents.end())
        {
            //student is present today, incrementing presents
            strollnum->second++;
            stoday<< true <<"\n";
        }
        else
        {
            //student is absent today
            stoday<< false <<"\n";
        }
        strollnum++;
    }
    stoday.close();
    storeLectureDates();
    storePresentCountList();
}

void Faculty::modifyAttendance() {
    cout<<"Enter Date for which you want to do modification\n";
    unsigned short dd , mm , yyyy;
    cout<<"Enter Date of lecture (dd mm yyyy)\n";
    cout<<"Enter dd (01 <= dd <= 31) ";
    dd = takeint();
    cout<<"Enter mm (01<= mm <= 12) ";
    mm = takeint();
    cout<<"Enter yyyy (1950<=yyyy) ";
    yyyy = takeint();
    ostringstream s2;
    s2<<dd<<"-"<<mm<<"-"<<yyyy;
    string dateString = s2.str();
    string tempRollNumber , fileAddress , tempFileRollNumber ,tempStatus_input; //to store roll number taken input from user
    bool newAttendanceStatus , tempStatus;
    //if file with same date already exist then add (1) at the end of file name to create new
    ifstream isExist("./date/"+dateString + ".txt");
    if(isExist){
        fileAddress = "./date/"+dateString + ".txt";
    }
    else
    {
        //date is wrong
        cout<<"No Lecture taken on this date.\n";
        return ;
    }
    isExist.close();
    cout<<"Enter Roll Number Of Student (ex.: B16CS001 ):\n";
    getline (cin,tempRollNumber);
    cout<<"Enter new Status for Attendance (ex.: 0,a,A for absent , 1,p,P for present ):\n";
    getline (cin,tempStatus_input);
    while(1)
    {
        if(tempStatus_input=="1"||tempStatus_input=="P"||tempStatus_input=="p")
        {
            tempStatus=true;
            break;
        } else
            if(tempStatus_input=="0"||tempStatus_input=="a"||tempStatus_input=="A")
            {
                tempStatus=false;
                break;
            } else
            {
                cout<<"Invalid Input.\nEnter new Status for Attendance (Valid entries: 0,a,A for absent , 1,p,P for present ):\n";
                getline(cin,tempStatus_input);
            }
    }
    //open file fileAddress and search for student with rollNumber tempRollNumber
    //and change its status to newAttendanceStatus
    map< string,bool >  dateRollnumberStatus;
    fstream mAf( fileAddress );
    while( !mAf.eof() )
    {
        mAf>>tempFileRollNumber;
        if(mAf.eof())break;
        mAf>>tempStatus;
        dateRollnumberStatus[tempFileRollNumber]=tempStatus;
    }
    mAf.close();
    //check if student exist
    bool isStudentPresent = false;
    map< string,bool >::iterator drsItertor =  dateRollnumberStatus.begin();
    while(drsItertor != dateRollnumberStatus.end())
    {
        if( drsItertor->first == tempRollNumber )
        {
            isStudentPresent=true;
            {
                //means student exist in map
                bool oldAttendanceStatus = dateRollnumberStatus[tempRollNumber];
                if( oldAttendanceStatus==newAttendanceStatus )
                {
                    cout<<"Same Attendance is alreday in database\n";
                }
                else
                {
                    dateRollnumberStatus[tempRollNumber]=newAttendanceStatus;
                    if(newAttendanceStatus)
                    {
                        //old is o and new is 1
                        presentCountList[tempRollNumber]++;
                    }
                    else
                    {
                        //old is 1 new is 0
                        presentCountList[tempRollNumber]--;
                    }
                    //store the newly changed present count list to file
                    storePresentCountList();
                }
            }
            break;
        }
        drsItertor++;
    }
    //check if student exist then do changes else return to faculty dashboard


    if(! isStudentPresent )
    {
        //student does not exist in map
        cout<<"Student Roll Number is Wrong\n";
        return ; //faculty dashboard
    }
    //overwriting map to file
    fstream wAf ( fileAddress , ios::out);
    drsItertor =  dateRollnumberStatus.begin();
    while( drsItertor != dateRollnumberStatus.end() )
    {
        wAf<< drsItertor->first <<"\t"<< drsItertor->second <<endl;
        drsItertor++;
    }
    wAf.close();
    cout<<"Modification of student "<< tempRollNumber <<" is done to ";
    cout<< newAttendanceStatus <<" on date "<< dateString<<endl;
    return ;//to faculty dashboard
}

bool Faculty::isLeapYear(unsigned short year){
    return (!(year%4) && (year%100) || !(year%400));
}

//1 valid, 0 invalid
bool Faculty::isValidDate(unsigned short year,unsigned short month,unsigned short day){
    unsigned short monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (!year || !month || !day || month>12)
        return 0;
    if (isLeapYear(year) && month==2)
        monthlen[1]++;
    if (day>monthlen[month-1])
        return 0;
    return 1;
}

int Faculty::takeint()
{
    string c ;
    bool isNum = false ,x=true;
    int y;
    while(!isNum)
    {
        getline(cin,c);
        for(int i=0;i<c.length();i++)
        {
            x=isdigit(c[i]);
            if(!x) break;

        }

        if(x && c.length() <= 4)
        {
        y = atoi(c.c_str()) ;
        isNum=true;
        }
        else
            cout<<"Invalid Input.\nEnter again: \n";
    }
    return y;
}