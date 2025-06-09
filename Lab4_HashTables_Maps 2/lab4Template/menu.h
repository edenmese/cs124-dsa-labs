#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "hashtable-template-solution.h"

using namespace std;
using namespace val_hash;

/**
   General purpose class menu
*/
class Menu{
public:
    /*******************************************************

     * Function Name: Menu(string name)

     * WHAT I CHANGED: Modified the constructor to initialize the Menu object with a hashtable of options instead of a vector.
     *                 The options are stored in a hashtable, which provides efficient access and allows for fast retrieval based on indices.
     *                 The constructor initializes the name of the Menu and initializes the options hashtable with a default size.

     * Parameter:
     * - name: The name of the Menu.

     * Return: None

     *******************************************************/
    Menu(string name) : name(name), options(10), optionIndex(0) {} // Initialize Hashtable with a default size

    /*******************************************************

     * Function Name: void Menu::setName(string name)

     * WHAT I CHANGED: Updated the setName function to set the name of the Menu.
     *                 The function sets the name of the Menu to the specified name.

     * Parameter:
     * - name: The new name to be set for the Menu.

     * Return: None

     *******************************************************/
    void setName(string name) {
        this->name = name;
    }
    
    /*******************************************************

     * Function Name: string Menu::getName(int index) const

     * WHAT I CHANGED: Updated the getName function to sort options in the hashtable.
     *                 Options are sorted based on their indices before retrieving the name of the option at the specified index.
     *                 The function first retrieves all options from the hashtable and stores them in a vector.
     *                 Then, it sorts the options based on their indices using a custom sorting function.
     *                 Finally, it retrieves the name of the option at the specified index and returns it.

     * Parameter:
     * - index: The index of the option whose name needs to be retrieved.

     * Return: The name of the option at the specified index.

     *******************************************************/
    string getName(int index) const {
        
        vector<string> optionVec;
        
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
        
        string option = optionVec[index];
        return option.substr(option.find(" "));
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
        return false;//options.size() > 0;
    };
private:
    void display() const;
    void displayPrefixIndex() const;

    string name;
    int optionIndex;
    val_hash::HashTable<string> options; // Change to use HashTable<string>

    
};
