//
//  CSVHandler.cpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/25/24.
//

#include "CSVHandler.hpp"

/*******************************************************

 * Function Name: <CSVHandler>

 * Purpose: <constructor >

 * Parameter: <const string& filename>

 * Return: <N/A>

 *******************************************************/
CSVHandler::CSVHandler(const string& filename) : filename(filename){}


/*******************************************************

 * Function Name: <~CSVHandler>

 * Purpose: <deconstructor >

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
CSVHandler::~CSVHandler(){}



/*******************************************************

 * Function Name: <readContactsFromFiler>

 * Purpose: <Read contact data from a CSV file and populate the ContactList >

 * Parameter: <ContactList &contactList>

 * Return: <N/A>

 *******************************************************/
void CSVHandler::readContactsFromFile(ContactList &contactList){
    ifstream file(filename); // Open the file with the provided filename
    if (!file.is_open()){ // Check if the file is opened successfully
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    
    string line;
    vector<string> row;
    
    // Skip the header line
    getline(file, line);
    
    // Read the file line by line
    while(getline(file, line)){
        Contact contact;
        string field;
        bool inQuotes = false;
        
        // Parse the line character by character
        for(char c : line){
            if(c == '"'){
                inQuotes = !inQuotes;
            }
            if(c == ',' && !inQuotes){
                row.push_back(field); // Add the field to the row vector
                field.clear(); // Clear the field string for the next field
            }else{
                field += c; // Append the character to the field string
            }
        }
        row.push_back(field); // Add the last field to the row vector
        
        // Check if the row contains the correct number of fields (14)
        if (row.size() == 14){
            contact.setId(stoi(row[0]));
            contact.setFirstName(row[1]);
            contact.setMiddleName(row[2]);
            contact.setLastName(row[3]);
            contact.setRole(row[4]);
            contact.setCompany(row[5]);
            contact.setAddress(row[6]);
            contact.setCity(row[7]);
            contact.setCounty(row[8]);
            contact.setState(row[9]);
            contact.setZip(row[10]);
            contact.setPrimaryPhone(row[11]);
            contact.setSecondaryPhone(row[12]);
            contact.setEmail(row[13]);
            
            contactList.append(contact); // Append the contact to the ContactList
        }else{
            cerr << "Invalid row in CSV: " << line << endl;
        }
        
        row.clear(); // Clear the row vector for the next line
    }

    file.close(); // Close the file
}


/*******************************************************

 * Function Name: <writeContactsToFile>

 * Purpose: <Write contact data from ContactList to a CSV file>

 * Parameter: <ContactList &contactList>

 * Return: <N/A>

 *******************************************************/
void CSVHandler::writeContactsToFile(const ContactList& contactList) const {
    ofstream file(filename); // Open the file with the provided filename

    if (!file.is_open()) { // Check if the file is opened successfully
        cout << "Error opening file " << filename << " for writing." << endl;
        return;
    }

    Node<Contact>* current = contactList.getHead();

    // Write the contact data to the file line by line
    while (current != nullptr) {
        file << current->data.getId() << ","
             << current->data.getFirstName() << ","
             << current->data.getMiddleName() << ","
             << current->data.getLastName() << ","
             << current->data.getRole() << ","
             << current->data.getCompany() << ","
             << current->data.getAddress() << ","
             << current->data.getCity() << ","
             << current->data.getCounty() << ","
             << current->data.getState() << ","
             << current->data.getZip() << ","
             << current->data.getPrimaryPhone() << ","
             << current->data.getSecondaryPhone() << ","
             << current->data.getEmail() << "\n";

        current = current->next;
    }

    file.close(); // Close the file
}
