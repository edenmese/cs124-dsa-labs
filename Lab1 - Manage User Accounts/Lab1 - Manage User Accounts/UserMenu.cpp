//
//  Menu.cpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/9/24.
//

#include "UserMenu.hpp"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>



UserMenu::UserMenu() : Menu(){}
UserMenu::~UserMenu(){}


void UserMenu::activate(){
    
    loadCSV("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab1 - Manage User Accounts/Lab1 - Manage User Accounts/users_data.csv");
    displayMenu(*this);

}

void UserMenu::loadCSV(const string filename){
    myFile.open(filename,ios::in);   // Read

    if (!myFile.is_open()){       // Returns error is file does not open
        cout << "Error opening file\n";
        return;
    }
    
    string firstLine;
    getline(myFile, firstLine); // discard first line in users_data.csv, this function read \n too
        
    while (!myFile.eof()){
        string line;
        getline(myFile, line); //read \n too
        
        line.erase(line.find_last_not_of("\n\r") + 1);
        if (line.empty()){
            continue;
        }

        istringstream ss(line);

        int id;
        string role, username, password, inDt, outDt, firstName, lastName, address, city, state, zip, phone, email;
        
        string idStr;
        getline(ss, idStr, ',');
        id = stoi(idStr);
        
        getline(ss,role,',');
        getline(ss,username,',');
        getline(ss,password,',');
        getline(ss,inDt,',');
        getline(ss,outDt,',');
        getline(ss,firstName,',');
        getline(ss,lastName,',');
        getline(ss,address,',');
        getline(ss,city,',');
        getline(ss,state,',');
        getline(ss,zip,',');
        getline(ss,phone,',');
        getline(ss,email,',');
        
        DateTime signInDt(inDt); // reads, sepeartes and initializes sign in time
        DateTime signOutDt(outDt); // reads, sepeartes and initializes sign out time
        
        User user(id, role, username, password,signInDt, signOutDt, firstName, lastName, address, city, state, zip, phone, email);
        list.push_back(user);
        
    }
    myFile.close();

}


void UserMenu::signIn() {
    string input;
    string passwordInput;
    string password;
    
    cout << "Enter email or phone number: ";
    cin >> input;
    
    if (input.find('@') != string::npos) {
        tempUser.setEmail(input);
    } else {
        tempUser.setPhone(input);
    }
    
    cout << "Enter Password (or) 'forgot' to reset password: \n";
    cin >> passwordInput;
    
    if (passwordInput == "forgot") {
        forgotPassword();
    }else {
        tempUser.setPassword(passwordInput);
        signedIN = false;
        
        for(int i = 0; i < list.size(); i++) {
            User& u = list[i];
            if (tempUser == u) {
                signedInUserIndex = i; // assign index to i
                signedIN = true;
                cout << "\nYAY! You are signed in\n" << endl;
                string dt = DateTime::now();
                tempUser.setSignIn_dt(DateTime(dt));
                tempUser.setSignedIn();
                u.updateUser(tempUser);
                return;
            }
        }
        
        if (!signedIN) {
            tempUser.clear();
            cout << "No username or password found.\n" << endl;
        }
    }
}


void UserMenu::signOut(){
    if (signedIN){
        signedIN = false;
        cout << "You have been signed out.\n" << endl;
        string dt = DateTime::now();
        tempUser.setSignOut_dt(DateTime(dt));
        tempUser.setSignedOut();
        if (signedInUserIndex != -1) {
                    User& signedOutUser = list[signedInUserIndex];
                    signedOutUser.updateUser(tempUser);
            doExit();
                }
    }else {
        cout << "You are not signed in.\n" << endl;
    }
}


void UserMenu::reset(){
    int attempt = 0;
    if (signedIN){
        string oldPassword;
        string newPassword;
        
        
        int attempt = 0;
        while(attempt < 3){
            cout << "Enter old password: ";
            cin >> oldPassword;
            
            if (tempUser.comparePassword(oldPassword)){
                cout << "Enter new password: ";
                cin >> newPassword;
                tempUser.setPassword(newPassword);
                cout << "\nPassword reset Successfully\n"<< endl;
                break ;
            }
            else{
                cout << "Incorrect password. Try again.\n" << endl;
            }
            attempt++;
        }
    }
    else{
        cout << "\nYou must sign to reset password.\n" << endl;
    }
    if (attempt == 3){
        cout << "You have exceeded amount of attempts.";
    }
}


void UserMenu::create() {
    if (!signedIN) {
        while (true) {
            string username;
            string firstName;
            string lastName;
            string phoneNumber;
            string email;
            string password;
            string reEnterPassword;
            
            cout << "Create account username: ";
            cin >> username;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter phone number: ";
            cin >> phoneNumber;
            cout << "Enter email: ";
            cin >> email;
            
            while (true) {
                cout << "Enter password: ";
                cin >> password;
                cout << "Re-enter password: ";
                cin >> reEnterPassword;
                
                if (password == reEnterPassword) {
                    tempUser.setUsername(username);
                    tempUser.setFirstname(firstName);
                    tempUser.setLastname(lastName);
                    tempUser.setPhone(phoneNumber);
                    tempUser.setEmail(email);
                    tempUser.setPassword(password);
                    
                    char confirmed;
                    cout << "\nIs the following information all correct? (Y/N)" << endl << endl;
                    cout << "User Name: " << tempUser.getUsername() << "\nFirst Name: " << tempUser.getFirstName() << "\nLast Name: " << tempUser.getLastName() << "\nPassword: " << tempUser.getPassword() << "\nPhone: " << tempUser.getPhone() << "\nEmail: " << tempUser.getEmail() << "\nPassword: " << tempUser.getPassword() << endl;
                    cin >> confirmed;
                    
                    if (toupper(confirmed) == 'Y') {
                        string currentDateTime = DateTime::now();
                        tempUser.setSignIn_dt(DateTime(currentDateTime));
                        tempUser.setId(list[list.size()-1].getiId() + 1);
                        tempUser.setSignOut_dt(DateTime()); // Set sign-out time to "0" (indicating never signed out)
                        tempUser.setSignedIn(); // Set signed in flag
                        cout << "\nAccount Created Successfully!" << endl;
                        return;
                    } else if (toupper(confirmed) == 'N') {
                        cout << "Re-enter information:" << endl << endl;
                        break;
                    }
                } else {
                    cout << "Password does not match. Please re-enter." << endl;
                }
            }
        }
    } else {
        cout << "Please sign out first." << endl << endl;
    }
}

void UserMenu::manageProfiles(){
    if (!signedIN){
        cout << "You must sign in to manage profiles.\n";
        return;
    }
    char action;
    cout << "\n(U)-Update info or (D)-Delete profile? ";
    cin >> action;
    if (toupper(action) == 'U'){
        int option;
        cout << "\nWhat would you like to update: " << endl;
        cout << "1)Name   2)Role   3)Address\n4)Phone   5)Email" <<endl;
        cout  << "Enter option: ";
        cin >> option;
        
        if (signedInUserIndex != -1){
            User& currentSignedInUser = list[signedInUserIndex];
            tempUser.updateProfile(option, tempUser);
            currentSignedInUser.updateUser(tempUser);
        }
    }else if (toupper(action) == 'D'){
        char actionTwo;
        cout << "\n(D) - Delete account, (R) - Remove information: ";
        cin >> actionTwo;
        
        if (toupper(actionTwo) == 'D'){
            deleteAccount();
        } else if (toupper(actionTwo) == 'R'){
            removeInformation();
        }
    }
}

void UserMenu::deleteAccount(){
    if  (signedInUserIndex != -1){
        list.erase(list.begin() + signedInUserIndex);
        cout << "Account deleted successfully.\n";
        signedIN = false; //Update signedIn status
    }
}

void UserMenu::removeInformation(){
    int option;
    cout << "\nWhat information would you like to remove?\n";
    cout << "1) First Name   2) Last Name   3) Address\n";
    cout << "4) City   5) State   6) Zip   7) Phone   8) Email\n";
    cout << "Endter option: ";
    cin >> option;
    
    if (signedInUserIndex != -1){
        User& currentSignedInUser = list[signedInUserIndex];
        currentSignedInUser.removeInfo(option);
        cout << "Information removed successfully. \n";
    }else {
        cout << "Error: Signed-in user not found.\n";
    }
}

void UserMenu::forgotPassword() {
    string newPassword;
    bool isAdmin = false;
    
    // Check if the user is an admin
    for (int i = 0; i < list.size(); i++) {
        const User& admin = list[i];
        if ((tempUser.getEmail() == admin.getEmail() || tempUser.getPhone() == admin.getPhone()) && admin.getRole() == "admin") {
            isAdmin = true;
            break; // Exit the loop once an admin user is found
        }
    }
    
    // If the user is not an admin, show a message and return
    if (!isAdmin) {
        cout << "Only admin can reset password." << endl;
        return;
    }
    
    // Prompt for a new password
    cout << "Enter new password: ";
    cin >> newPassword;

    // Update the password for the admin user
    signedIN = true;
    for (int i = 0; i < list.size(); i++) {
        User& admin = list[i];
        if ((tempUser.getEmail() == admin.getEmail() || tempUser.getPhone() == admin.getPhone()) && admin.getRole() == "admin") {
            admin.setPassword(newPassword);
            cout << "Password reset successfully for admin account." << endl;
            break; // Once the admin's password is updated, exit the loop
        }
    }
}

void UserMenu::doExit(){

    ofstream outputFile("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab1 - Manage User Accounts/Lab1 - Manage User Accounts/users_data.csv");

    if (!outputFile.is_open()){
        cout << "Error opening file for writing\n";
        return;
    }

    outputFile << "ID,Role,Username,Password,SignInDateTime,SignOutDateTime,FirstName,LastName,Address,City,State,Zip,Phone,Email\n";

        for (size_t i=0; i < list.size(); ++i){
            const User& user = list[i];

            string signedInTime = "";
            string signedOutTime = "";

            if (!user.getSignedIn() && i == signedInUserIndex){
                signedInTime = user.getSignInDt().format();
            }
            if (!user.getSignedOut() && i == signedInUserIndex){
                signedOutTime = user.getSignOutDt().format();
            }else {
                signedOutTime = "";
            }
            outputFile << user.getiId() << "," << user.getRole() << "," << user.getUsername() << "," << user.getPassword() << "," << signedInTime << "," << signedOutTime << "," << user.getFirstName() << "," << user.getLastName() << "," << user.getAddress() << "," << user.getCity() << "," << user.getState() << "," << user.getZip() << "," << user.getPhone() << "," << user.getEmail() << "\n";

        }

    if (!signedIN && !isTempUserInList()){
        string newAccountSignIn = "";
        string newAccountSignOut = "";
        newAccountSignIn = tempUser.getSignInDt().format();
        newAccountSignOut = tempUser.getSignOutDt().format();
        outputFile << tempUser.getiId() << "," << tempUser.getRole() << "," << tempUser.getUsername() << "," << tempUser.getPassword() << "," << newAccountSignIn << "," << newAccountSignOut << "," << tempUser.getFirstName() << "," << tempUser.getLastName() << "," << tempUser.getAddress() << "," << tempUser.getCity() << "," << tempUser.getState() << "," << tempUser.getZip() << "," << tempUser.getPhone() << "," << tempUser.getEmail() << "\n";

    }

}


bool UserMenu::isTempUserInList() const{
    for (const User& user : list) {
        if (tempUser == user) {
            return true;
        }
    }
    return false;
}
