//
//  Menu.hpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>

using namespace std;

// Enumeration for menu options
enum MENU_OPTIONS {
  DISPLAY_LIST = '1',
  VIEW_CATEGORIES = '2',
  ADD_ASSIGNMENT = '3',
  EDIT_ASSIGNMENT = '4',
  REMOVE_ASSIGNMENT = '5',
  VIEW_COURSES = '6', 
  CALCULATE_GRADE = '7',
  DO_EXIT = 'x',
};

class GradeBookMenu;

/**
 * The Menu class provides a basic menu system for the Contact Management application.
 * It includes methods to display a menu of options and to get the user's choice.
 * The main functionality is to present options for managing contacts, such as listing, viewing,
 * adding, editing, deleting contacts, and exiting the application.
 */
class Menu {
public:

    /*******************************************************

         * Function Name: Menu

         * Purpose: Constructor for Menu class

         * Parameter: None

         * Return: None

         *******************************************************/
        Menu();

        /*******************************************************

         * Function Name: ~Menu

         * Purpose: Destructor for Menu class

         * Parameter: None

         * Return: None

         *******************************************************/
        ~Menu();
    
    
    /*******************************************************

     * Function Name: <displayMenu>

     * Purpose: <Display the main menu and prompt user for choice>

     * Parameter: <GradeBookMenu& menuChoice - reference to the GradeBookMenu object for storing user choice>

     * Return: <void>

     *******************************************************/
    void displayMenu(GradeBookMenu& menuCoice);
    

    
protected:
    
    /*******************************************************

         * Function Name: getChoice

         * Purpose: Get user choice from menu

         * Parameter: None

         * Return: char - the user's choice

         *******************************************************/
        char getChoice() const;

private:
    bool quit = false; // Flag to indicate if the user wants to quit
    char choice; // User's menu choice
};

#endif /* Menu_hpp */
