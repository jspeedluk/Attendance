//
// Created by Kavish Gambhir on 29/03/18.
//

#include "Interface_handler.h"
#include "Admin.h"
Interface_handler::Interface_handler() {db=new Database_handler; }
int Interface_handler::adminPasswordCount = 0;



void Interface_handler::homeView() {

    cout << "Enter 1 for Admin Login :\n";
    cout << "Enter 2 for Faculty Login :\n";
    cout << "Enter 3 for registration of new Faculty:\n";
    cout << "Enter 4 to view All Attendance :\n";
    cout << "Enter 5 to view All Defaulters :\n";
    cout << "Enter 9 to Exit :\n";
    unsigned int input=0;
    bool exit = 0;
    User *user;
    cin >> input;
    system("clear");
    switch (input) {
        case 1:
            this->loginAdmin();
            break;
        case 2:
            this->loginFaculty();
            break;
        case 3:
            this->_register();
            break;
        case 4:
            user = new User();
            user->viewAttendance();
            delete user;
            break;
        case 5:
            user = new User();
            // user->viewDefaulters();
            delete user;
            break;
        case 9:
            cout << "Exiting.......................\n";
            exit = true;
            break;
        default:
            cout << "Invalid choice\n";
    }
    if (!exit)
        this->homeView();


}

void Interface_handler::loginFaculty() {
    string input_password, name;
    cout << "You chose to login as Faculty.\nEnter your Name and Password :\nName : \n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    cout << "Password:\n";
    getline(cin, input_password);
    if (db->getFaculty(name) == input_password) {
        Faculty *faculty = new Faculty(name,input_password, *db);
        faculty->facultyDashboard();
    } else {
        if (db->getFaculty(name).length() < 6) cout << "Invalid Name. (Check for Upper/Lower Case) \n";
        else {
            cout << "Invalid Password.\n";
            this->homeView();
        }
    }

}

void Interface_handler::_register() { //should require admin password
    string input_password, name, input_password_verify;
    cout << "You chose to Register.\nEnter your Name.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name );
    cout << "Enter a 6 to 13 digit Password. ( It must contain a number and an Upper Case alphabet )\n";
    getline(cin,input_password);
    while (!db->passwordStrength(input_password)) {
        PRINT_WEAK_PASSWORD
        cin >> input_password;
    }
    system("clear");
    cout << "Re enter your password to continue.\n";
    cin >> input_password_verify;
    int passwordTries=0;
    while (input_password != input_password_verify) {
        system("clear");
        if(passwordTries==3)
        {
            cout<<"Too many Attempts.\nRedirecting to Home...\n\n";
            this->homeView();
        }
        passwordTries++;
        cout << "Password does not match.\n Enter again.\n";
        cin >> input_password_verify;
    }
    Faculty faculty(name,input_password,*db);
    db->addFaculty(faculty);
    cout << name << " has been successfully registered as the Faculty for the course !\n";
}

void Interface_handler::loginAdmin() {

    string input_password, verify_password;
    system("clear");
    if (adminPasswordCount > 3) {
        cout << "You have exceeded the maximum number of tries for login.\n";
        cout
                << "For support send an email at :\n\n***\tgambhir.2@iitj.ac.in\t***\n\nor\n\n***\tjangir.3@iitj.ac.in\t***\n\n";
        cout << "Enter any key to return to Home.\n";
        while (cin.get()) this->homeView();
    } else {
        cout << "You chose to login as Admin.\nEnter Admin Password :\n";
        cin >> input_password;
        ifstream file("passwords.txt");
        file >> verify_password;
        if (verify_password == input_password) {
            Admin *admin = new Admin("Admin",input_password,*db,*this);
            file.close();
            adminPasswordCount = 0;
            admin->adminDashboard();
            return;

        } else {
            char response;
            cout << "Invalid Password!\n" << (3 - adminPasswordCount) << "  tries remaining !\n";
            if ((3 - adminPasswordCount++)) {
                cout << "Enter 'y' : to try again , 'n' to return to Home Page.\n";
                while (cin >> response) {
                    cin.ignore(numeric_limits<streamsize >::max(),'\n');
                    if (response == 'n') this->homeView();
                    else if (response == 'y') {
                        this->loginAdmin();
                        return;
                    } else cout << "Invalid response.\nEnter Again.\n";
                }
            } else this->loginAdmin();
        }
    }
}


