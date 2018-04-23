//
// Created by Kavish Gambhir on 29/03/18.
//

#include "Interface_handler.h"
#include "Admin.h"
#include <stdlib.h>
Interface_handler::Interface_handler() {db=new Database_handler; exitBool=0; }
int Interface_handler::adminPasswordCount = 0;



void Interface_handler::homeView() {
    if(exitBool) return;
    cout << "Enter 1 for Admin Login :\n";
    cout << "Enter 2 for Faculty Login :\n";
    cout << "Enter 3 for registration of new Faculty:\n";
    cout << "Enter 4 to view All Attendance :\n";
    cout << "Enter 5 to view All Defaulters :\n";
    cout << "Enter 9 to Exit :\n";
    string isBadInput;
    char input;
    User *user;
    cin >> isBadInput;
    if(isBadInput.length()>1) input ='0';  //goes to defaults case for bad input
    else input=isBadInput.at(0);
    cin.ignore(INT_MAX,'\n');
    system("clear");
    switch (input) {
        case '1':
            this->loginAdmin();
            break;
        case '2':
            this->loginFaculty();
            break;
        case '3':
            this->_register();
            break;
        case '4':
            user = new User();
            user->viewAttendance();
            delete user;
            break;
        case '5':
            user = new User();
            user->viewDefaulters();
            delete user;
            break;
        case '9':
            cout << "Exiting.......................\n";
            exitBool = true;
            break;
        default:
            cout << "Invalid choice\n";
    }
    if (exitBool)
        ::exit(0);
    this->homeView();


}

void Interface_handler::loginFaculty() {
    string input_password, name;
    cout << "You chose to login as Faculty.\nEnter your Name and Password\nName : ";
    getline(cin, name);
    cout << "Password: ";
    getline(cin, input_password);
    if (db->getFaculty(name) == input_password) {
        Faculty *faculty = new Faculty(name,input_password, *db);
        faculty->facultyDashboard();
    } else {
        if (db->getFaculty(name).length() < 6) cout << "Invalid Name. (Check for Upper/Lower Case) \n";
        else {
            cout << "Invalid Password.\n";
            this->homeView();
            exitBool=true;
        }
    }

}

void Interface_handler::_register() {
    cout<<"enter admin password :\n";
    string adminPasswordTemp;
    getline(cin,adminPasswordTemp);
    if(adminPasswordTemp!="CS223"&&adminPasswordTemp!="cs223")
    {
        cout<<"Invalid Admin Password.\nRedirecting to home...\n";
        this->homeView();
        exitBool=true;
    }else
    {
    string input_password, name, input_password_verify;
    cout << "You chose to Register.\nEnter your Name.\n";
    getline(cin, name );
    cout << "Enter a 6 to 13 digit Password. ( It must contain a number and an Upper Case alphabet )\n";
    getline(cin,input_password);
    while (!db->passwordStrength(input_password)) {
        PRINT_WEAK_PASSWORD
        getline(cin,input_password);
    }
    system("clear");
    cout << "Re enter your password to continue.\n";
    int passwordTries=0;
//        getline(cin,input_password_verify);
//        int passwordTries=0;
//        while (input_password != input_password_verify) {
//            system("clear");
//            if(passwordTries==3)
//            {
//                cout<<"Too many Attempts.\nRedirecting to Home...\n\n";
//                this->homeView();
//                exitBool=true;
//            }
//            passwordTries++;
//            cout << "Password does not match.\n Enter again.\n";
//            getline(cin,input_password_verify);
//        }
        getline(cin,input_password_verify);
    while (input_password!=input_password_verify) {
            passwordTries++;
            if(passwordTries<3) cout << "Password does not match.\nEnter again.\n";

        if(passwordTries>=3)
        {
            cout<<"Too many Attempts.\nRedirecting to Home...\n\n";
            this->homeView();
            exitBool=true;
            break;
        }
        getline(cin,input_password_verify);
    }
        if(!exitBool) {
            Faculty faculty(name, input_password, *db);
            db->addFaculty(faculty);
            cout << name << " has been successfully registered as the Faculty for the course !\n";
        }
}
}

void Interface_handler::loginAdmin() {

    string input_password, verify_password;
    system("clear");
    if (adminPasswordCount > 3) {
        cout << "You have exceeded the maximum number of tries for login.\n";
        cout<< "For support send an email at :\n\n";
        cout<<"***\tgambhir.2@iitj.ac.in\t***\n\nor\n\n***\tjangir.3@iitj.ac.in\t***\n\n";
        cout << "Enter any key to return to Home.\n";
        cin.get(); this->homeView();
    } else {
        cout << "You chose to login as Admin.\nEnter Admin Password :\n";
        getline(cin,input_password);
        if (input_password=="CS223"||input_password=="cs223") {
            Admin *admin = new Admin("Admin",input_password,*db,*this);
            adminPasswordCount = 0;
            admin->adminDashboard();
            return;
        } else {
            string response;
            cout << "Invalid Password!\n" << (3 - adminPasswordCount) << "  tries remaining !\n";
            if ((3 - adminPasswordCount++)) {
                cout << "Enter 'y' : to try again , 'n' to return to Home Page.\n";
                while (1) {
                    getline(cin,response);
                    if (response == "n") {
                        this->homeView();
                        exitBool=true;
                        return;
                    }
                    else if (response == "y") {
                        this->loginAdmin();
                        return;
                    } else cout << "Invalid response.\nEnter Again.\n";
                }
            } else this->loginAdmin();
        }
    }
}


