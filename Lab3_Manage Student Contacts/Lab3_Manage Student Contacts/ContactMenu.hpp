//
//  ContactMenu.hpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/25/24.
//

#ifndef ContactMenu_hpp
#define ContactMenu_hpp
#include "Menu.hpp"
#include "ContactList.hpp"


//enumeration for 'sort by' function choices
enum SORT_BY_FUNCTION_CHOICES{
    FIRST_NAME = 1,
    MIDDLE_NAME,
    LAST_NAME,
    ADDRESS,
    PRIMARY_PHONE,
    SECONDARY_PHONE,
    EMAIL,
};

/**
 * The ContactMenu class is a derived class of the Menu class.
 * It extends the basic menu functionalities to provide specific actions
 * related to managing a list of contacts. It includes methods for listing contacts,
 * viewing a specific contact, adding a new contact, editing an existing contact,
 * deleting a contact, and saving the contact list to a CSV file.
 */
class ContactMenu: public Menu {
    
public:
    
    //constructor
    ContactMenu();
    
    //destructor
    ~ContactMenu();
    
    // Activate the program
    void activate();
    
    //Actions
    void listContacts(); // Display the list of all contacts
    void viewContact() const; // View details of a specific contact
    void addNewContact() const; // Add a new contact to the list
    void editContact() const; // Edit details of an existing contact
    void deleteContact() const; // Delete a contact from the list
    void doExit() const;  // Exit the program and save the contact list to a file
 
    void moveFirst();
    void moveNext();
    void movePrevious();
    void moveLast();
private:
    ContactList contactList; // List of contacts
    void ascendDescendList() const; // Ascend/Descend sorting option
//    void ascendDescendList(int orderChoice) const;
    void sortListByField(int field) const; // Sort the contact list by a specific field
    int generateNewId() const; // Generate a new ID for a contact
    
};
#endif /* ContactMenu_hpp */
