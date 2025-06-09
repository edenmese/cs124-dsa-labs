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

/**
* Initial menu name
*/
//Menu::Menu(string name) {
//    this->name = name;
//}

/**
* Add menu open name
*/

/*******************************************************

 * Function Name: void Menu::addOption(string option)

 * WHAT I CHANGED: Modified the addOption function to insert an option into the hashtable instead of pushing it into a vector.
 *                 The function generates a formatted string containing the index and the option text, and then inserts this formatted string into the hashtable.
 *                 This allows for efficient retrieval of options based on their indices.

 * Parameter:
 * - option: The option to be added to the Menu.

 * Return: None

 *******************************************************/
void Menu::addOption(string option) {
//    options.push_back(option);
    string format = to_string(optionIndex++) + " " + option;
    options.insert(format); //Insert option into the Hashtable
}

/**
* Dipslay option nam
*/
//void Menu::display() const {
//    cout << "***** " << name << " *****" << endl;
//    for (int i = 0; i < (int)options.size(); i++) {
//        cout << options[i] << endl;
//    }
//    cout << "\nEnter choice: ";
//}


//void Menu::display() const{
//    
//    cout << "***** " << name << " *****" << endl;
//    int index = 1;
//    for(Iterator<string> iter = options.begin(); !iter.equals(options.end()); iter.next()){
//        cout << /*index <<*/ ")" << iter.get() << endl;
//        index++;
//    }
//    
//}

/*******************************************************

 * Function Name: Menu::display() const

 * WHAT I CHANGED: Updated the display function to sort options in the hashtable.
 *                 Options are sorted based on their indices before displaying them.
 *                 The function first retrieves all options from the hashtable and stores them in a vector.
 *                 Then, it sorts the options based on their indices using a custom sorting function.
 *                 Finally, it iterates over the sorted options and displays them with their indices.

 * Parameter: None

 * Return: None

 *******************************************************/
void Menu::display() const{
    vector<string> optionVec;
    
    cout << "***** " << name << " *****" << endl;
    //char index = 'a'; // Start with character 'a' as the first index
    for(Iterator<string> iter = options.begin(); !iter.equals(options.end()); iter.next()){
        optionVec.push_back(iter.get());
        //cout << index << ")" << iter.get() << endl;
        //index++; // Increment the character for the next index
    }
    
    //sort
    sort(optionVec.begin(), optionVec.end(),
         [](const string& first, const string& second){
            int idx1 = 0;
            int idx2 = 0;
        istringstream iss1(first);
        istringstream iss2(second);
        
        iss1 >> idx1;
        iss2 >> idx2;
        
        return idx1 < idx2;
        }
    );
    
    for (string option: optionVec){
        option = option.substr(option.find(" ") + 1);
        cout << option.substr(0, 1) << ") " << option << endl;
    }
    
}



/**
* Display ordered index and option name
*/
/*******************************************************

 * Function Name: void Menu::displayPrefixIndex() const

 * WHAT I CHANGED: Updated the displayPrefixIndex function to display the options stored in the hashtable along with their indices.
 *                 The function iterates through the options in the hashtable using an Iterator and displays each option along with its corresponding index.
 *                 This ensures that options are displayed in the order they were added to the Menu.

 * Parameter: None

 * Return: None

 *******************************************************/
void Menu::displayPrefixIndex() const {
    
    cout << "***** " << name << " *****" << endl;
    int index = 1;
    for (Iterator<string> iter = options.begin(); !iter.equals(options.end()); iter.next()) {
        cout << index << ") " << iter.get() << endl;
        index++;
    }
     
    cout << "\nEnter choice: ";
}
//void Menu::displayPrefixIndex() const {
//    cout << "***** " << name << " *****" << endl;
//    for (int i = 0; i < (int)options.size(); i++) {
//        cout << i + 1 << ") " << options[i] << endl;
//    }
//    cout << "\nEnter choice: ";
//}
/**
* Display option menu, option name; and ask users to select a choice by index
*/
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

/**
* Display option menu, option name; and ask users to select a choice
*/
int Menu::doMenu() const {
    int input = 0;
    
    do {
        display();
        cin >> input;
    } while (input < 1 || input >(int)options.size());
     
    return input;
}

/**
* Display option menu, option name; and ask users to select a choice
*/
char Menu::doMenuOption() const {
    char input = '\0';
    display();
    
    string temp;
    getline(cin, temp);
    
    if (temp.length() > 0){
        input = temp[0];
    }
    
    return input;
}
