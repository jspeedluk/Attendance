//
// Created by Kavish Gambhir on 21/03/18.
//

#include "attendance_management.h"
bool passwordStrength(string str) {
    int countNumber,countUC;
    countNumber=countUC=0;
    for (char i : str) {
        if(i >=65&& i <=90) countUC++;
        if(i >='0'&& i <='9') countNumber++;
    }
    return countNumber && countUC && str.length()>=6 && str.length()<=13 ;
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
            // user->viewDefaulters();
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

void Interface_handler::loginFaculty() {
    string input_password,name;
    cout<<"You chose to login as Faculty\n.Enter your Name and Password :\nName: \n";
    cin>>name;
    cout<<"Password:\n";
    cin>>input_password;


}

void Interface_handler::_register() {
    string input_password,name,input_password_verify;
    cout<<"You chose to Register.\nEnter your Name.\n";
    getline(cin,name);
    cout<<"Enter a 6 to 13 digit Password. ( It must contain a number and an Upper Case alphabet )\n";
    cin>>input_password;
    while(!passwordStrength(input_password))
    {
       cout<<"Yout password must contain a number and an Upper Case alphabet !\nReenter your password.\n";
        cin>>input_password;
    }
    system("clear");
    cout<<"Re enter your password to continue.\n";
    cin>>input_password_verify;
    while(input_password!=input_password_verify) {
        system("clear");
        cout << "Password does not match.\n Enter again.\n";
        cin >> input_password_verify;
    }

    }




