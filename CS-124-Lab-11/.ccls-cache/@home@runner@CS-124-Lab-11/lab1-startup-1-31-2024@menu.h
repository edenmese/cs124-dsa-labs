#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
   General purpose class menu
*/
class Menu
{
public:
    Menu() {};

    /**
       Constructs a menu with no options.
    */
    Menu(string name);

    void setName(string name) {
        this->name = name;
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
    int doMenuIndex() const;
    char doMenuOption() const;

    bool hasOption() const {
        return options.size() > 0;
    };
private:
    void display() const;
    void displayIndex() const;

    string name;
    vector<string> options;
};

#endif