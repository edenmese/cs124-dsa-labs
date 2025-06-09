//
//  main.cpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/25/24.
//


/*******************************************************

 * Program Name: <Manage Student Contacts>

 * Author: <Eden Meseret>

 * Date: <04/06/24>

 * Description: <The Contact Management System is a console-based application designed to manage a list of contacts. Users can view, add, edit, and delete contacts, as well as sort the contact list by various fields like First Name, Middle Name, Last Name, and more. The system utilizes a linked list to organize and navigate through the contacts, providing an efficient way to handle contact information.>

 *******************************************************/

#include <iostream>
#include "Menu.hpp"
#include "CSVHandler.hpp"
#include "AbstractLinkedList.hpp"
#include "ContactList.hpp"
#include "Contact.hpp"
#include "Person.hpp"
#include "ContactMenu.hpp"


int main() {
    ContactMenu menu; // Create an instance of the ContactMenu class
    menu.activate();  // Activate the contact menu to start the program
    return 0;  // Return 0 to indicate successful execution of the program
}
