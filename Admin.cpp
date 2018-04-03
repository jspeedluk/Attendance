//
// Created by Kavish Gambhir on 29/03/18.
//

#include "Admin.h"

Admin::Admin(const string &basic_string, const string &input_password, Database_handler &db,
              Interface_handler &handler) :
        Faculty(basic_string, input_password, db ), handler(&handler) {}


void Admin::adminDashboard() {
    system("clear");

    cout << "\nWelcome Dr. Chiranjoy Chattopadhyay.\n";
    cout << "Enter 1 to Add a Faculty for the course :\n";
    cout << "Enter 2 to modify a Faculty details :\n";
    cout << "Enter 3 to remove a Faculty designated for the course :\n";
    cout << "Enter 4 to view All Attendance :\n";
    cout << "Enter 5 to register a student in the course :\n";
    cout << "Enter 6 to modify a Students details :\n";
    cout << "Enter 7 to remove a registered student from the course :\n";
    cout << "Enter 8 to modify Attendance :\n";
    cout << "Enter 9 to add Attendance into the database :\n";
    cout << "Enter 0 to exit and return to home :\n";
    char input;
    string isBadInput;
    getline(cin,isBadInput);
    if(isBadInput.length()>1) input ='d';  //goes to defaults case for bad input
    else input=isBadInput.at(0);
    system("clear");
    switch (input) {
        case '1':
            this->addFaculty();
            break;
        case '2':
            this->setFaculty();
            break;
        case '3':
            this->deleteFaculty();
            break;
        case '4':
            this->viewAttendance();
            break;
        case '5':
            this->addStudent();
            break;
        case '6':
            this->modifyStudent();
            break;
        case '7':
            this->deleteStudent();
            break;
        case '8':
            this->modifyAttendance();
            break;
        case '9':
            this->addAttendance();
            break;
        case '0':
            this->exit=true;
            break;
        default:
            cout << "Invalid choice\n";
        }
    if(handler->exit==1) this->exit=1;
           if(!this->exit) this->adminDashboard();
            cout<<"Logging you out...\n";
    handler->homeView();
}

void Admin::addFaculty() {
    handler->_register();

}

void Admin::deleteFaculty() {
    string linkedPassword, name;
    cout << "You chose to remove a Faculty for the coarse.\nEnter Faculty Name.\n";
    getline(cin, name);
    linkedPassword = db->getFaculty(name);
    if (!db->passwordStrength(linkedPassword)) {
        cout << "No such Faculty Assigned for the coarse.\n Redirecting to Dashboard... \n";
        return;
    } else
    { 
        db->deleteFaculty(name);
        cout << name << " has been successfully Removed from the course !\n\n";
    }

}

void Admin::setFaculty() {
    string linkedPassword, name;
    cout << "You chose to modify a Faculty for the coarse.\nEnter Faculty Name.\n";
    getline(cin, name);
    linkedPassword = db->getFaculty(name);
    if (!db->passwordStrength(linkedPassword)) {
        cout << "No such Faculty Assigned for the coarse.\n Redirecting to Dashboard... \n";
        return;
    }
        cout << "Enter 1 : to change Name for Dr. " << name << endl;
    cout << "Enter 2 : to change password for Dr. " << name << endl;
   char input='0';
    while (input!='1'&&input!='2') {
    string isBadInput;
    getline(cin,isBadInput);
    if(isBadInput.length()>1) input ='0';  //goes to default case for bad input (enter again)
    else input=isBadInput.at(0);
        if (input == '1') {
            string newName;
            cout << "Enter new name for Dr. " << name << endl;
            getline(cin, newName);
            db->deleteFaculty(name);
            Faculty faculty(newName, linkedPassword, *db);
            db->addFaculty(faculty);
            cout<<"New name has been updated .\n";
        } else if (input == '2') {
            string newPass = "";
            cout << "Enter new Password for Dr. " << name << endl;
            
            while (1)
            {
                getline(cin,newPass);
                if(!db->passwordStrength(newPass))
                PRINT_WEAK_PASSWORD
                else
                    break;
            }
            db->deleteFaculty(name);
            Faculty faculty(name, newPass, *db);
            db->addFaculty(faculty);
            cout<<"New password has been updated :\n";
        }
        else cout<<"Invalid Input.\nEnter again :\n";
    }


}


