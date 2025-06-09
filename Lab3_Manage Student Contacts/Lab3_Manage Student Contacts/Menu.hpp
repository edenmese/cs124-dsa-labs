//
//  Menu.hpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/25/24.
//

#ifndef Menu_hpp
#define Menu_hpp
#include <iostream>
#include "CSVHandler.hpp"

using namespace std;

// Enumeration for menu options
enum MENU_OPTIONS {
  LIST_OF_CONTACTS = '1',
  VIEW_CONTACT = '2',
  ADD_CONTACT = '3',
  EDIT_CONTACT = '4',
  DELETE_CONTACT = '5',
  DO_EXIT = 'x',
};

class ContactMenu;

/**
 * The Menu class provides a basic menu system for the Contact Management application.
 * It includes methods to display a menu of options and to get the user's choice.
 * The main functionality is to present options for managing contacts, such as listing, viewing,
 * adding, editing, deleting contacts, and exiting the application.
 */
class Menu {
public:

    //constructor
    Menu();
    
    //destructor
    ~Menu();
    
    // Display the main menu and get user choice
    void displayMenu(ContactMenu& menuCoice);
    

    
protected:
    
    // Get user choice from menu
    char getChoice() const;

    
private:
    bool quit = false; // Flag to indicate if the user wants to quit
    char choice; // User's menu choice
};

#endif /* Menu_hpp */
