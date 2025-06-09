//
//  Contact.hpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/27/24.
//

#ifndef Contact_hpp
#define Contact_hpp
#include <iostream>
#include "Person.hpp"
#include <iomanip>


using namespace std;


// Contact class represents a contact with additional attributes like id, role, and company.
// It inherits from the Person class to reuse and extend the basic attributes and functionalities.
class Contact: public Person{
public:
    Contact(); // Default constructor
    Contact(int id, const string& role, const string& company,
              const string& firstName, const string& middleName, const string& lastName,
              const string& address, const string& city, const string& county,
              const string& state, const string& zip, const string& primaryPhone,
              const string& secondaryPhone, const string& email); // Parameterized constructor
    ~Contact(); // Destructor
    
    // Getters
    int getId() const; // Getter for the contact's id
    string getRole() const; // Getter for the contact's role
    string getCompany() const; // Getter for the contact's company

    // Setters
    void setId(int id); // Setter for the contact's id
    void setRole(string role); // Setter for the contact's role
    void setCompany(string company); // Setter for the contact's company

    // Comparison operators for sorting
    bool operator<(const Contact& other) const; // Less than operator for sorting
    bool operator>(const Contact& other) const; // Greater than operator for sorting
    bool operator==(const Contact& other) const; // Equality operator for contacts
    bool operator!=(const Contact& other) const; // Inequality operator for contacts
    
    // Printing and formatting
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact); // Overloaded printing operator to print the details of a Contact object
    void printFirstLast(ostream& os) const; // Print only the first and last name of the contact
    
private:
    int id;           // Unique identifier for the contact
    string role;      // Role of the contact
    string company;   // Company of the contact
};
#endif /* Contact_hpp */
