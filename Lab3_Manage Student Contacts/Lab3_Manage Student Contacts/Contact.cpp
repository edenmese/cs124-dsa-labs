//
//  Contact.cpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/27/24.
//

#include "Contact.hpp"

/*******************************************************

 * Function Name: <Contact>

 * Purpose: <constructor>

 * Parameter: <N/A>

 * Return: <Contact>

 *******************************************************/
Contact::Contact(): Person(), id(0), role(""), company(""){}

/*******************************************************

 * Function Name: <Contact>

 * Purpose: <paramaterized constructor>

 * Parameter: <int id, const std::string& role, const std::string& company,
 const std::string& firstName, const std::string& middleName, const std::string& lastName,
 const std::string& address, const std::string& city, const std::string& county,
 const std::string& state, const std::string& zip, const std::string& primaryPhone,
 const std::string& secondaryPhone, const std::string& email>

 * Return: <Contact>

 *******************************************************/
Contact::Contact(int id, const std::string& role, const std::string& company,
                 const std::string& firstName, const std::string& middleName, const std::string& lastName,
                 const std::string& address, const std::string& city, const std::string& county,
                 const std::string& state, const std::string& zip, const std::string& primaryPhone,
                 const std::string& secondaryPhone, const std::string& email)
    : Person(firstName, middleName, lastName, address, city, county, state, zip, primaryPhone, secondaryPhone, email),
      id(id), role(role), company(company) {}

/*******************************************************

 * Function Name: <~Contact>

 * Purpose: <destructor>

 * Parameter: <N/A>

 * Return: <Contact>

 *******************************************************/
Contact::~Contact(){}

// Getters
/*******************************************************

 * Function Name: <getId>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
int Contact::getId() const{
    return id;
}

/*******************************************************

 * Function Name: <getRole>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
std::string Contact::getRole() const{
    return role;
}

/*******************************************************

 * Function Name: <getCompany>

 * Purpose: <getter>

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
std::string Contact::getCompany() const{
    return company;
}

// Setters

/*******************************************************

 * Function Name: <setId>

 * Purpose: <setter>

 * Parameter: <int id>

 * Return: <N/A>

 *******************************************************/
void Contact::setId(int id){
    this->id = id;
}

/*******************************************************

 * Function Name: <setRole>

 * Purpose: <setter>

 * Parameter: <std::string roled>

 * Return: <N/A>

 *******************************************************/
void Contact::setRole(std::string role){
    this->role = role;
}


/*******************************************************

 * Function Name: <setCompany>

 * Purpose: <setter>

 * Parameter: <std::string company>

 * Return: <N/A>

 *******************************************************/
void Contact::setCompany(std::string company){
    this->company = company;
}

// Comparison operators for sorting

/*******************************************************

 * Function Name: <operator<>

 * Purpose: <overload < operator>

 * Parameter: <const Contact& other>

 * Return: <bool>

 *******************************************************/
bool Contact::operator<(const Contact& other) const {
    return id < other.id;
}

/*******************************************************

 * Function Name: <operator<>

 * Purpose: <overload > operator>

 * Parameter: <const Contact& other>

 * Return: <bool>

 *******************************************************/
bool Contact::operator>(const Contact& other) const {
    return id > other.id;
}

/*******************************************************

 * Function Name: <operator<>

 * Purpose: <overload == operator>

 * Parameter: <const Contact& other>

 * Return: <bool>

 *******************************************************/
bool Contact::operator==(const Contact& other) const {
    return id == other.id;
}

/*******************************************************

 * Function Name: <operator<>

 * Purpose: <overload != operator>

 * Parameter: <const Contact& other>

 * Return: <bool>

 *******************************************************/
bool Contact::operator!=(const Contact& other) const {
    return !(*this == other);
}

/*******************************************************

 * Function Name: <operator<>

 * Purpose: < Overloaded printing operator to print the details of a Contact object>

 * Parameter: <std::ostream& os, const Contact& contact>

 * Return: <std::ostream&>

 *******************************************************/
std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << setw(6) << contact.getId() ;
    os << setw(12) << contact.getFirstName();
    os << setw(12) << contact.getLastName() ;
    os << setw(10) << contact.getRole();
    os << setw(32) << contact.getCompany();
    return os;
    
}

/*******************************************************

 * Function Name: <operator<>

 * Purpose: < Print only the first and last name of the contact>

 * Parameter: <std::ostream& os>

 * Return: <void>

 *******************************************************/
void Contact::printFirstLast(std::ostream& os) const{
    os << getId() <<  ": " << getLastName() << ", " << getFirstName();
}
