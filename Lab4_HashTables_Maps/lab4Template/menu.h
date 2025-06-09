#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Hashtable.hpp"

using namespace std;
/**
    General purpose class menu
 */
 class Menu{
 public:
     Menu() : options(10), numOptions(0) {};
     
     Menu(string name) : name(name), options(10), numOptions(0){}

     /**
        Constructs a menu with no options.
     */
     void setName(string name) {
         this->name = name;
     }

     /**
        Retrieves the name of the option at the specified index.
        @param index the index of the option
        @return the name of the option
     */
     string getName(int index) const{
         return options.search(to_string(index));
     }

     /**
        Adds an option to the end of this menu.
        @param option the option to add
     */
     void addOption(string option);
     
     /**
        Displays the menu, with options numbered starting with 1,
        and prompts the user for input. Repeats until a valid input
        is supplied.
        @return the number that the user supplied
     */
     int doMenu() const;
     
     /**
        Displays the menu with options prefixed by their index number.
        @return the number that the user supplied
     */
     int doMenuIndex() const;
     
     /**
        Displays the menu and prompts the user for a character input.
        @return the character that the user supplied
     */
     char doMenuOption() const;

     /**
        Checks if the menu has any options.
        @return true if the menu has options, otherwise false
     */
     bool hasOption() const {
         return options.size() > 0;
     };
 private:
     /**
        Displays the menu options.
     */
     void display() const;
     
     /**
        Displays the menu options prefixed by their index number.
     */
     void displayPrefixIndex() const;

     string name; ///< The name of the menu
     Hashtable <string, string> options; ///< The options of the menu
     int numOptions; ///< The number of options in the menu
 };
