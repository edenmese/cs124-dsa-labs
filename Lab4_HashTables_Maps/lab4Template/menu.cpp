/**
* Author: Eden Meseret
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <string>
#include <vector>
#include "menu.h"

using namespace std;


/*******************************************************
 * class Name: addOption
 *
 * WHAT I CHANGED: Adds a new option to the menu.
 *
 * parameter: option - the option to add
 *******************************************************/
void Menu::addOption(string option){
    options.add(to_string(++numOptions), option);
}

/*******************************************************
 * class Name: display
 *
 * WHAT I CHANGED: Displays the menu options.
 *******************************************************/
void Menu::display() const {
    cout << "***** " << name << " *****" << endl;
    options.printAll([](const string& key, const string& value) {
        cout << key << ": " << value << endl;
    });
    cout << "\nEnter choice: ";
}


/*******************************************************
 * class Name: displayPrefixIndex
 *
 * WHAT I CHANGED: Displays the menu options with prefixed index numbers.
 *******************************************************/
void Menu::displayPrefixIndex() const {
    cout << "***** " << name << " *****" << endl;
    int index = 1;
    options.printAll([&index](const string& key, const string& value) {
        cout << index++ << ") " << value << endl;
    });
    cout << "\nEnter choice: ";
}

/*******************************************************
 * class Name: doMenuIndex
 *
 * WHAT I CHANGED: Displays the menu with prefixed index numbers and prompts the user for input. Repeats until a valid input is supplied.
 *
 * Return: the index chosen by the user
 *******************************************************/
int Menu::doMenuIndex() const {
    char ch;
    int input = 0;
    do {
        displayPrefixIndex();
        cin >> ch;
        input = static_cast<int>(ch) - 48;
    } while (input < 1 || input >(int)options.size());
    return input;
}

/*******************************************************
 * class Name: doMenu
 *
 * WHAT I CHANGED: Displays the menu and prompts the user for input. Repeats until a valid input is supplied.
 *
 * Return: the index chosen by the user
 *******************************************************/
int Menu::doMenu() const {
    int input = 0;
    do {
        display();
        cin >> input;
    } while (input < 1 || input >(int)options.size());
    return input;
}

/*******************************************************
 * class Name: doMenuOption
 *
 * WHAT I CHANGED: Displays the menu and prompts the user for input. Returns the character input by the user.
 *
 * Return: the character input by the user
 *******************************************************/
char Menu::doMenuOption() const {
    char input;
    display();
    cin >> input;
    return input;
}
