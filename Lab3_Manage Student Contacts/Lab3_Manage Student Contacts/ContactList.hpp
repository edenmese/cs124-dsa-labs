//
//  ContactList.hpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/27/24.
//

#ifndef ContactList_hpp
#define ContactList_hpp
#include "AbstractLinkedList.hpp"
#include "Contact.hpp"
#include <iostream>


/**
 * @brief The ContactList class is a derived class from AbstractLinkedList.
 * It manages a list of Contact objects and provides various operations to manipulate and
 * display the contacts. The class includes methods for adding, removing, and searching
 * contacts, as well as sorting the contacts based on different fields such as first name,
 * middle name, last name, address, primary phone, secondary phone, and email.
 */
using namespace std;
class ContactList: public AbstractLinkedList<Contact>{
public:
    ContactList(); // Constructor
    
    ~ContactList(); // Destructor
    
    //override functions from AbstractLinkedList
    void sort() const override; // Override sort function to sort contacts
    void displayContacts() const; // Displays contact details in linked list
    
    //additional functions to override pure virtual functions from AbstractLinkedList
    void append(const Contact& data) const override; // Appends a contact to the end of the list
    void prepend(const Contact& data) override; // Prepends a contact to the beginning of the list
    void insertAfter(Node<Contact>* preNode, const Contact& data) override; // Inserts a contact after a given node
    void remove(const Contact& data) const override; // Removes a contact with a given data
    void addContact(const Contact& contact) const; // Adds a contact to the list
    int getSize() const override; // Returns the size of the list
    bool search(const Contact& data) const override; // Searches for a contact in the list
    
    Contact& getFirst() const override; // Returns the first contact in the list
    Contact& getLast() const override; // Returns the last contact in the list
    Contact& getAt(int pos) const override; // Returns the contact at a given position in the list
    void setAt(int pos, const Contact& data) override; // Sets the contact at a given position in the list
    bool isEmpty() const override; // Checks if the list is empty
    void clear() override; // Clears the list
    void reverse() const override; // Reverses the list
    
    // Sorting functions
    void sortByFirstName() const; // Sorts the list by first name
    void sortByMiddleName() const; // Sorts the list by middle name
    void sortByLastName() const; // Sorts the list by last name
    void sortByAddress() const; // Sorts the list by address
    void sortByPrimaryPhone() const; // Sorts the list by primary phone number
    void sortBySecondaryPhone() const; // Sorts the list by secondary phone number
    void sortByEmail() const; // Sorts the list by email
    

    
    
    //display functions
    void printAt(int position) const;
    void printNodeAt(Node<Contact>* node) const;
    
    //move & iterator functions
    void moveFirst();
    void moveNext();
    void movePrevious();
    void moveLast();
    
    ContactList& operator++();
    ContactList operator++(int);
    ContactList& operator--();
    ContactList operator--(int);
    
    Contact& getCurrent() const;
    
    
    
protected:
    void printNode(Node<Contact>* node) const; // Override function to print elements in node
    
private:
    Node<Contact>* findMiniNode(Node<Contact>* start) const; // Finds the node with the minimum contact data starting from a given node
    mutable Node<Contact>* current; // Mutable member variable to keep track of the current node
        // cursor = head // first
        // cursor = tail // last
        // cursor = cursor->next // next
        // cursor = cursor->prev
};
#endif /* ContactList_hpp */
