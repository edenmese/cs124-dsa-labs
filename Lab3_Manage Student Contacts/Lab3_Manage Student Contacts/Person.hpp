//
//  Person.hpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/25/24.
//

#ifndef Person_hpp
#define Person_hpp
//#include "DateType.hpp"
#include <iostream>
#include <string>

using namespace std;

/**
 * The Person class represents an individual with personal details.
 * It includes attributes such as name, address, contact information, and more.
 */
class Person{
public:
    //default constructor
    Person();
    
    //parameter constructor
    Person(const string& firstName, const string& middleName, const string& lastName,/*const DateType dateOfBirth,*/const string& address,const string& city,const string& county, const string& state, const string& zip, const string& primaryPhone, const string& secondaryPhone, const string& email);
    
    

    //destructor
    ~Person();
    
    //Getters
    string getFirstName() const; //getter for firstname
    string getMiddleName() const; // getter for middle name
    string getLastName() const; // getter for last name
    string getAddress() const; // getter for address
    string getCity() const; // getter for city
    string getCounty() const; // getter for county
    string getState() const; // getter for state
    string getZip() const; // getter for zip
    string getPrimaryPhone() const; // getter for primary phone
    string getSecondaryPhone() const; // getter for secondary phone
    string getPronouns() const; // getter for pronouns
    string getEmail() const; // getter for email

    //Setters
    void setFirstName(string firstName); //setter for firstname
    void setMiddleName(string middleName); //setter for middle name
    void setLastName(string lastName); //setter for last name
    void setAddress(string address); //setter for address
    void setCity(string city); //setter for city
    void setCounty(string county); //setter for county
    void setState(string state); //setter for state
    void setZip(string zip); //setter for zip
    void setPrimaryPhone(string primaryPhone); //setter for primary phone
    void setSecondaryPhone(string secondaryPhone); //setter for secondary phone
    void setEmail(string email); //setter for email
 
   friend std::ostream& operator<<(std::ostream& os, const Person& person); // overloaded printing operator to print data of Person
private:
    string firstName, middleName, lastName, address, city, county, state, zip, primaryPhone, secondaryPhone, pronouns, email;

};

#endif /* Person_hpp */
