//
// Created by Kavish Gambhir on 29/03/18.
//

#include "Admin.h"

Admin::Admin(const string &basic_string, const string &input_password, Database_handler &db,
             const Interface_handler &handler) :
        Faculty(basic_string, input_password, db), handler(handler) {}


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
    unsigned int input;
    cin >> input;
    system("clear");
    switch (input) {
        case 1:
            this->addFaculty();
            break;
        case 2:
            this->setFaculty();
            break;
        case 3:
            this->deleteFaculty();
            break;
        case 4:
//            this->viewAttendance();
            break;
        case 5:
//            this->addStudent();
            break;
        case 6:
//            this->modifyStudent();
            break;
        case 7:
//            this->deleteStudent();
            break;
        case 8:
//            this->modifyAttendance();
            break;
        case 9:
            //    this->addAttendance();
            break;
        default:
            cout << "Invalid choice\n";
            this->adminDashboard();
    }
}

void Admin::addFaculty() {
    handler._register();

}

void Admin::deleteFaculty() {
    string linkedPassword, name;
    cout << "You chose to remove a Faculty for the coarse.\nEnter Faculty Name.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    linkedPassword = db->getFaculty(name);
    if (!db->passwordStrength(linkedPassword)) {
        cout << "No such Faculty Assigned for the coarse.\n Redirecting to Dashboard... \n";
        return;
    } else
        db->deleteFaculty(name);
    cout << name << " has been successfully Removed from the course !\n\n";

}

void Admin::setFaculty() {  //need bug fix
    string linkedPassword, name;
    cout << "You chose to modify a Faculty for the coarse.\nEnter Faculty Name.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    linkedPassword = db->getFaculty(name);
    if (!db->passwordStrength(linkedPassword)) {
        cout << "No such Faculty Assigned for the coarse.\n Redirecting to Dashboard... \n";
        return;
    }
        cout << "Enter 1 : to change Name for Dr. " << name << endl;
    cout << "Enter 2 : to change password for Dr. " << name << endl;
    int inp = 0;
    while (inp != 1 && inp != 2) {

        cin >> inp;
        if (inp == 1) {
            string newName;
            cout << "Enter new name for Dr. " << name << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, newName);
            db->deleteFaculty(name);
            Faculty faculty(newName, linkedPassword, *db);
            db->addFaculty(faculty);
            cout<<"New name has been updated .\n";
        } else if (inp == 2) {
            string newPass = "";
            cout << "Enter new Password for Dr. " << name << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,newPass);
            while (!db->passwordStrength(newPass))
            {
                PRINT_WEAK_PASSWORD
                getline(cin,newPass);

            }
            db->deleteFaculty(name);
            Faculty faculty(name, newPass, *db);
            db->addFaculty(faculty);
            cout<<"New password has been updated :\n";
        }
        else cout<<"Invalid Input.\nEnter again :\n";
    }


}


