//
//  Person.cpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/25/24.
//

#include "Person.hpp"

/*******************************************************

 * Function Name: <Person>

 * Purpose: <paramaterized constructor>

 * Parameter: <N/A>

 * Return: <Person>

 *******************************************************/
Person::Person():firstName(""), middleName(""), lastName(""), address(""), city(""), county(""), state(""), zip(""), primaryPhone(""), secondaryPhone(""), email(""){}

/*******************************************************

 * Function Name: <Person>

 * Purpose: <paramaterized constructor>

 * Parameter: <const string& firstName, const string& middleName, const string& lastName, const string& address,const string& city,const string& county, const string& state, const string& zip, const string& primaryPhone, const string& secondaryPhone,const string& email>

 * Return: <Person>

 *******************************************************/
Person::Person(const string& firstName, const string& middleName, const string& lastName, const string& address,const string& city,const string& county, const string& state, const string& zip, const string& primaryPhone, const string& secondaryPhone,const string& email):
    firstName(firstName),
    middleName(middleName),
    lastName(lastName),
    address(address),
    city(city),
    county(county),
    state(state),
    zip(zip),
    primaryPhone(primaryPhone),
    secondaryPhone(secondaryPhone),
    email(email){}

/*******************************************************

 * Function Name: <~Person>

 * Purpose: <destructor>

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
Person::~Person(){}

// Getters

/*******************************************************

 * Function Name: <getFirstName>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getFirstName() const{
    return firstName;
}

/*******************************************************

 * Function Name: <getMiddleName>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getMiddleName() const{
    return middleName;
}

/*******************************************************

 * Function Name: <getLastName>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getLastName() const{
    return lastName;
}

/*******************************************************

 * Function Name: <getAddress>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getAddress() const{
    return address;
}

/*******************************************************

 * Function Name: <getCity>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getCity() const{
    return city;
}

/*******************************************************

 * Function Name: <get Country>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getCounty() const{
    return county;
}

/*******************************************************

 * Function Name: <get state>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getState() const{
    return state;
}

/*******************************************************

 * Function Name: <get zip>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getZip() const{
    return zip;
}

/*******************************************************

 * Function Name: <get primary phone>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getPrimaryPhone() const{
    return primaryPhone;
}

/*******************************************************

 * Function Name: <get secondary phone>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getSecondaryPhone() const{
    return secondaryPhone;
}

/*******************************************************

 * Function Name: <get email>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
string Person::getEmail() const{
    return email;
}

// Setters

/*******************************************************

 * Function Name: <getFirstName>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setFirstName(string firstName){
    this -> firstName = firstName;
}

/*******************************************************

 * Function Name: <getMiddleName>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setMiddleName(string middleName){
     this->middleName = middleName;
}

/*******************************************************

 * Function Name: <setLastName>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setLastName(string lastName){
    this->lastName = lastName;
}

/*******************************************************

 * Function Name: <setAddress>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setAddress(string address){
     this->address = address;
}

/*******************************************************

 * Function Name: <setCity>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setCity(string city){
     this->city = city;
}

/*******************************************************

 * Function Name: <setCountry>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setCounty(string county){
    this->county = county;
}

/*******************************************************

 * Function Name: <setState>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setState(string state){
  this->state = state;
}

/*******************************************************

 * Function Name: <setZip>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setZip(string zip){
    this->zip = std::move(zip);
}

/*******************************************************

 * Function Name: <setPrimaryPhone>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setPrimaryPhone(string primaryPhone){
    this->primaryPhone = primaryPhone;
}

/*******************************************************

 * Function Name: <setSecondaryPhone>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setSecondaryPhone(string secondaryPhone){
    this->secondaryPhone = secondaryPhone;
}

/*******************************************************

 * Function Name: <setEmail>

 * Purpose: <setter>

 * Parameter: <N/A>

 * Return: <string>

 *******************************************************/
void Person::setEmail(string email){
    this->email = email;
}



/*******************************************************

 * Function Name: <operator<<>

 * Purpose: <Overloaded printing operator to print the details of a Person object.>

 * Parameter: <std::ostream& os, const Person& person>

 * Return: <std:: ostream&>

 *******************************************************/
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "First Name: " << person.getFirstName() << "\n";
    os << "Middle Name: " << person.getMiddleName() << "\n";
    os << "Last Name: " << person.getLastName() << "\n";
    os << "Address: " << person.getAddress() << "\n";
    os << "City: " << person.getCity() << "\n";
    os << "County: " << person.getCounty() << "\n";
    os << "State: " << person.getState() << "\n";
    os << "ZIP: " << person.getZip() << "\n";
    os << "Primary Phone: " << person.getPrimaryPhone() << "\n";
    os << "Secondary Phone: " << person.getSecondaryPhone() << "\n";
    os << "Email: " << person.getEmail() << "\n";
    return os;
}



