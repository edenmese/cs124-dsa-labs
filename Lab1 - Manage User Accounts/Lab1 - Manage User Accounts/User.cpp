//
//  User.cpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/9/24.
//

#include "User.hpp"
#include <string>
User::User(){
    role = username = password = firstName = lastName = address = city = state = zip =  phone = email = "N/A";
}

User::User(int id, const string& role, const string& username, const string& password,const DateTime& signIn_dt, const DateTime& signOut_dt, const string& firstName, const string& lastName, const string& address, const string& city, const string& state, const string& zip, const string& phone, const string& email){
    
    setId(id);
    setRole(role);
    setUsername(username);
    setPassword(password);
    setSignIn_dt(signIn_dt);
    setSignIn_dt(signOut_dt);
    setFirstname(firstName);
    setLastname(lastName);
    setAddress(address);
    setCity(city);
    setState(state);
    setZip(zip);
    setPhone(phone);
    setEmail(email);
    
    signedIn = signedOut = false;
}

User::User (const string& firstName,const string& lastName,const string& phone,const string& email,const string&password){
    setFirstname(firstName);
    setLastname(lastName);
    setPhone(phone);
    setEmail(email);
    setPassword(password);
    
    signedIn = signedOut = false;
}//THIS IS FOR CREATE ACCOUNT CONSTRUCTOR


User::~User(){
    
}

bool User::operator==(const User& other) const{
    return
    (this-> email == other.getEmail() && this -> password == other.getPassword()) ||
    (this->phone == other.getPhone() && this-> password == other.getPassword());
    
}

bool User::comparePassword(const string& oldPassword)const{
    return this->password == oldPassword;
}
bool User::getSignedIn() const{
    return signedIn;
}
bool User::getSignedOut() const{
    return signedOut;
}
void User::setSignedIn(){
    signedIn = true;
}
void User::setSignedOut(){
    signedOut = true;
}
void User::updateProfile(int option, User& user){
    switch (option) {
        case UPDATE_NAME: {
            string newUsername;
            cout << "\n(Enter New Username): ";
            cin>> newUsername;
            user.setUsername(newUsername);
            cout << "Username Updpated to: " << user.getUsername() << endl<< endl;
            break;
        }
        case UPDATE_ROLE:{
            string newRolee;
            cout << "(Enter New Role): ";
            cin>> newRolee;
            user.setRole(newRolee);
            cout << "Role Updpated to: " << user.getRole() << endl<< endl;
            break;
        }
        case UPDATE_ADDRESS:{
            string newAddress;
            cout << "(Enter New Address): ";
            cin>> newAddress;
            user.setAddress(newAddress);
            cout << "Address Updpated to: " << user.getAddress() << endl << endl;
            break;
        }
        case UPDATE_PHONE:{
            string newPhone;
            cout << "(Enter New Phone Number): ";
            cin>> newPhone;
            user.setPhone(newPhone);
            cout << "Phone Number Updpated to: " << user.getPhone() << endl<< endl;
            break;
        }
        case UPDATE_EMAIL:{
            string newEmail;
            cout << "(Enter New Email): ";
            cin>> newEmail;
            user.setEmail(newEmail);
            cout << "Email Updpated to: " << user.getEmail() << endl<< endl;
            break;
        }
        default:
            break;
    }
}


void User::updateUser(const User& other){
    if (!other.email.empty()){
        email = other.email;
    }
    if (!other.phone.empty()){
        phone = other.phone;
    }
    if (!other.password.empty()){
        password = other.password;
    }
    if (!other.role.empty()){
        role = other.role;
    }
    if (!other.username.empty()){
        username = other.username;
    }

    setSignIn_dt(other.signIn_dt);
    setSignOut_dt(other.signOut_dt);
} ///TO UPDATE WITH OTHER USER

void User::removeInfo(int option){
    switch (option){
        case 1:
            setFirstname("N/A");
            break;
        case 2:
            setLastname("N/A");
            break;
        case 3:
            setAddress("N/A");
            break;
        case 4:
            setCity("N/A");
            break;
        case 5:
            setState("N/A");
            break;
        case 6:
            setZip("N/A");
            break;
        case 7:
            setPhone("N/A");
            break;
        case 8:
            setEmail("N/A");
            break;
        default:
            cout << "Invalid option.\n";
            
    }
}

void User::clear(){
    role = username = password = firstName = lastName = address = city = state = zip =  phone = email = "";
    
}



void User::setId(int id){
    this->id = id;
}

void User::setRole(string role){
    this->role = role;
}

void User::setUsername(string username){
    this->username = username;

}
void User::setPassword(string password){
    this->password = password;

}
void User::setFirstname(string firstName){
    this->firstName = firstName;

}
void User::setLastname(string lastName){
    this->lastName = lastName;

}
void User::setAddress(string address){
    this->address = address;

}
void User::setCity(string city){
    this->city = city;

}
void User::setState(string state){
    this->state = state;

}
void User::setZip(string zip){
    this->zip = zip;

}
void User::setPhone(string phone){
    this->phone = phone;

}
void User::setEmail(string email){
    this->email = email;

}

//CHANGE TO DATETIME
void User::setSignIn_dt(const DateTime& signIn_dt){
    this->signIn_dt = signIn_dt;
}

void User::setSignOut_dt(const DateTime& signOut_dt){
    this->signOut_dt = signOut_dt;
}

User& User::operator=(const User& other) {
    if (this != &other) { // Avoid self-assignment
        // Set all member variables of current object to the values of other object
        this->id = other.id;
        this->role = other.role;
        this->username = other.username;
        this->password = other.password;
        this->signIn_dt = other.signIn_dt;
        this->signOut_dt = other.signOut_dt;
        this->firstName = other.firstName;
        this->lastName = other.lastName;
        this->address = other.address;
        this->city = other.city;
        this->state = other.state;
        this->zip = other.zip;
        this->phone = other.phone;
        this->email = other.email;
        this->signedIn = other.signedIn;
        this->signedOut = other.signedOut;
    }
    return *this; // Return the current object
}

int User::getiId() const{
    return this->id;
}
string User::getRole() const{
    return this->role;
}
string User::getUsername() const{
    return this->username;
}
string User::getPassword() const{
    return this->password;
}
string User::getFirstName() const{
    return this->firstName;
}
string User::getLastName() const{
    return this->lastName;
}
string User::getAddress() const{
    return this->address;
}
string User::getCity() const{
    return this->city;
}
string User::getState() const{
    return this->state;
}
string User::getZip() const{
    return this->zip;
}

string User::getPhone() const{
    return this->phone; 
}

string User::getEmail() const{
    return this->email;
}



//CHANGE TO DATETIME
DateTime User::getSignInDt()const{
    return this->signIn_dt;
}
DateTime User::getSignOutDt()const{
    return this->signOut_dt;
}


