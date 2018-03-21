//
// Created by Kavish Gambhir on 21/03/18.
//

#include "attendance_management.h"

void User::setName() {

}

void Interface_handler::homeView() {

    cout<<"Enter 1 for Admin Login :\n";
    cout<<"Enter 2 for Faculty Login :\n";
    cout<<"Enter 3 for registration of new Faculty:\n";
    cout<<"Enter 4 to view All Attendance :\n";
    cout<<"Enter 5 to view All Defaulters :\n";
    unsigned int input;
    User* user;
    cin>>input;
    system ("clear");
    switch(input)
    {
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
            user=new User();
            delete user;
            break;
        case 5:
            user =new User();
             user->viewDefaulters();
            delete user;
            break;
        default:
            cout<<"Invalid choice\n";
            this->homeView();


    }

}

void Interface_handler::loginAdmin() {

    string input_password;
    cout<<"You chose to login as Admin\n.Enter Admin Password :\n";
    cin>>input_password;



}
