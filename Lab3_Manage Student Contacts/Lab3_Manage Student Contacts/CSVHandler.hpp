//
//  CSVHandler.hpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/25/24.
//

#ifndef CSVHandler_hpp
#define CSVHandler_hpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "ContactList.hpp"


// CSVHandler class provides functionality to read contact data from a CSV file
// and write contact data to a CSV file.
using namespace std;
class CSVHandler{
    
public:

    CSVHandler(const string& filename); // Constructor: Initializes the CSVHandler with a filename @param filename The name of the CSV file to be handled.

    ~CSVHandler(); // Destructor: Cleans up any dynamically allocated resources.
    
    void readContactsFromFile(ContactList& contactList); // Reads contact data from a CSV file and populates a ContactList @param contactList The ContactList object to be populated with the data from the CSV file.
    
    void writeContactsToFile(const ContactList& contactList) const;  // Writes contact data from a ContactList to a CSV file. @param contactList The ContactList object containing the data to be written to the CSV file.

private:
    string filename; // name of CSV file
    
};

#endif /* CSVHandler_hpp */
