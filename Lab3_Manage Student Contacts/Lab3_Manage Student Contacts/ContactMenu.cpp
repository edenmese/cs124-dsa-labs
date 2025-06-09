//
//  ContactMenu.cpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/25/24.
//

#include "ContactMenu.hpp"
/*******************************************************

 * Function Name: <ContactMenu>

 * Purpose: <constructor>

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
ContactMenu::ContactMenu(){}

/*******************************************************

 * Function Name: <~ContactMenu>

 * Purpose: <destructor>

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
ContactMenu::~ContactMenu(){}


/*******************************************************

 * Function Name: <activate>

 * Purpose: <activate the program>

 * Parameter: <N/A>

 * Return: <void>

 *******************************************************/
void ContactMenu::activate(){
//    CSVHandler csvHandler("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab3_Manage Student Contacts/Lab3_Manage Student Contacts/contacts_data.csv");
    CSVHandler csvHandler("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab3_Manage Student Contacts/Lab3_Manage Student Contacts/contacts_data.csv");
    csvHandler.readContactsFromFile(contactList);
    displayMenu(*this);
}


/*******************************************************

 * Function Name: <listContacts>

 * Purpose: <show list of contact in ascending or descending or sort by specific field>

 * Parameter: <N/A>

 * Return: <void>

 *******************************************************/

void ContactMenu::listContacts() {
    int listChoice;
    cout << "1) - Show list\n2) - Sort list by field: \n"; // Display the menu options for listing or sorting contacts
    cin >> listChoice; // Get user choice
    
    if (listChoice == 1) { // Check the user's choice
        this->ascendDescendList();
//        int sortChoice;
        
        char navChoice;
        int position = 1; // Initialize position to 1
        
        char navigate;
        cout << "Would you like to navigate through menu? (Y/N)";
        cin >> navigate;
        if (toupper(navigate) == 'Y'){
            cout << "\n Current contact:\n";
            contactList.moveFirst(); // Move to the first contact
            
            do {
                contactList.printAt(position); // Display contact at current position
                cout << "\nOptions: (n)ext, (p)revious, (l)ast, (f)irst, (q)uit navigation\n";
                cin >> navChoice;
                
                switch (navChoice) {
                    case 'n': // Move to next contact
                        contactList.moveNext();
                        position++;
                        break;
                    case 'p': // Move to previous contact
                        contactList.movePrevious();
                        position--;
                        break;
                    case 'f': // Move to first contact
                        contactList.moveFirst();
                        position = 1;
                        break;
                    case 'l': // Move to last contact
                        contactList.moveLast();
                        position = contactList.getSize();
                        break;
                    case 'q': // Quit navigation
                        break;
                    default:
                        cout << "Invalid choice\n";
                }
            } while (navChoice != 'q');
        }else if (toupper(navigate) == 'N'){
            return;
        }
        
    } else if (listChoice == 2) {
        int fieldChoice;
        
        // Display the options for sorting by various fields
        cout << "Sort by:" << endl;
        cout << "1. First Name" << endl;
        cout << "2. Middle Name" << endl;
        cout << "3. Last Name" << endl;
        cout << "4. Address" << endl;
        cout << "5. Primary Phone" << endl;
        cout << "6. Secondary Phone" << endl;
        cout << "7. Email" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> fieldChoice; // Get user's field choice for sorting
        
        this->sortListByField(fieldChoice); // Sort the contact list by the chosen field
    }
}

/*******************************************************

 * Function Name: <viewContact>

 * Purpose: <View details of a specific contact based on the provided first name.>

 * Parameter: <N/A>

 * Return: <void>

 *******************************************************/

void ContactMenu::viewContact() const {
    string viewChoice;
    cout << "\nEnter First-Name to view Contact: " << endl; // Prompt the user to enter the first name of the contact to view

    cin >> viewChoice; // Get the user's input for the first name

    Node<Contact>* current = contactList.getHead();
    bool found = false;
    int position = 1;

    while (current != nullptr) {  // Iterate through the contact list to find the contact with the given first name
        if (current->data.getFirstName() == viewChoice) {
            cout << "(Contact Found)\n" << endl;
            contactList.printAt(position);  // Using the printAt function to print the Contact details
            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {  // Display a message if the contact is not found
        cout << "Contact not found." << endl;
    }
}


/*******************************************************

 * Function Name: <addNewContact>

 * Purpose: <Add a new contact to contactList and generate ID>

 * Parameter: <N/A>

 * Return: <void>

 *******************************************************/
void ContactMenu::addNewContact() const {
    string firstName, middleName, lastName, role, company, address, city, county, state, zip, primaryPhone, secondaryPhone, email;

        cout << "Enter First Name: ";
        cin >> firstName;
        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Enter Middle Name: ";
        getline(cin, middleName);

        cout << "Enter Last Name: ";
        cin >> lastName;
        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Enter Role: ";
        getline(cin, role);

        cout << "Enter Company: ";
        getline(cin, company);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter City: ";
        cin >> city;
        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Enter County: ";
        cin >> county;
        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Enter State: ";
        cin >> state;
        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Enter ZIP: ";
        cin >> zip;
        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Enter Primary Phone: ";
        cin >> primaryPhone;
        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Enter Secondary Phone: ";
        cin >> secondaryPhone;
        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Enter Email: ";
        cin >> email;
        cin.ignore();  // Ignore the newline character left in the buffer

        int newId = generateNewId(); // Generate a new ID for the contact

        Contact newContact(newId, role, company, firstName, middleName, lastName, address, city, county, state, zip, primaryPhone, secondaryPhone, email); // Create a new contact object with the provided details
        contactList.addContact(newContact); // Add the new contact to the contact list
        contactList.displayContacts(); // Display the updated list of contacts
}



/*******************************************************

 * Function Name: <editContact>

 * Purpose: <Edit details of a specific contact based on the provided first name.>

 * Parameter: <N/A>

 * Return: <void>

 *******************************************************/
void ContactMenu::editContact() const {
    string nameToEdit;
    string middleName;
    string lastName;
    string role;
    string company;
    string address;
    string city;
    string county;
    string state;
    string zip;
    string primaryPhone;
    string secondaryPhone;
    string email;

    cout << "Enter contact's first name to edit: "; // Prompt the user to enter the first name of the contact to edit
    cin >> nameToEdit;

    Node<Contact>* current = contactList.getHead();
    bool found = false;

    while (current != nullptr) { // Iterate through the contact list to find the contact with the given first name
        if (current->data.getFirstName() == nameToEdit) {
            cout << "(Contact Found)\n" << endl;
            contactList.printNodeAt(current);  // Using the printNodeAt function to print the Contact details
            found = true;

            while (true) {  // Display edit options to the user
                cout << "\nEdit Options:" << endl;
                cout << "---------------------------" << endl;
                cout << "1) First Name       2) Middle Name" << endl;
                cout << "3) Last Name        4) Role" << endl;
                cout << "5) Company          6) Address" << endl;
                cout << "7) City             8) County" << endl;
                cout << "9) State            10) ZIP" << endl;
                cout << "11) Primary Phone   12) Secondary Phone" << endl;
                cout << "13) Email           14) FINISH EDITING" << endl;
                cout << "---------------------------" << endl;
                cout << "Enter your choice: ";

                int choice;
                cin >> choice;

                // Clear the input buffer
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                switch (choice) {  // Switch case to handle user's edit choice
                    case 1:  // Edit the First Name
                        cout << "Enter new First Name: ";
                        getline(cin, nameToEdit);
                        current->data.setFirstName(nameToEdit);
                        break;
                    case 2: // Edit the Middle Name
                        cout << "Enter new Middle Name: ";
                        getline(cin, middleName);
                        current->data.setMiddleName(middleName);
                        break;
                    case 3: // Edit the Last Name
                        cout << "Enter new Last Name: ";
                        getline(cin, lastName);
                        current->data.setLastName(lastName);
                        break;
                    case 4: // Edit the Role
                        cout << "Enter new Role: ";
                        getline(cin, role);
                        current->data.setRole(role);
                        break;
                    case 5: // Edit the Company
                        cout << "Enter new Company: ";
                        getline(cin, company);
                        current->data.setCompany(company);
                        break;
                    case 6: // Edit the Address
                        cout << "Enter new Address: ";
                        getline(cin, address);
                        current->data.setAddress(address);
                        break;
                    case 7: // Edit the City
                        cout << "Enter new City: ";
                        getline(cin, city);
                        current->data.setCity(city);
                        break;
                    case 8:  // Edit the County
                        cout << "Enter new County: ";
                        getline(cin, county);
                        current->data.setCounty(county);
                        break;
                    case 9:  // Edit the State
                        cout << "Enter new State: ";
                        getline(cin, state);
                        current->data.setState(state);
                        break;
                    case 10:  // Edit the Zip
                        cout << "Enter new ZIP: ";
                        getline(cin, zip);
                        current->data.setZip(zip);
                        break;
                    case 11:  // Edit the Primary Phone
                        cout << "Enter new Primary Phone: ";
                        getline(cin, primaryPhone);
                        current->data.setPrimaryPhone(primaryPhone);
                        break;
                    case 12:  // Edit the Secondary Phone
                        cout << "Enter new Secondary Phone: ";
                        getline(cin, secondaryPhone);
                        current->data.setSecondaryPhone(secondaryPhone);
                        break;
                    case 13:  // Edit the Email
                        cout << "Enter new Email: ";
                        getline(cin, email);
                        current->data.setEmail(email);
                        break;
                    case 14: // Finish editing and exit the function
                        cout << "Finished editing." << endl << endl;
                        cout << "***Updated Contact***" << endl;
                        contactList.printNodeAt(current);  // Using the printNodeAt function to print the updated Contact details
                        return;  // Exit the function
                    default:
                        cout << "Invalid choice. Please try again." << endl; // Invalid choice
                        break;
                }
            }
        }
        current = current->next; // Move to the next node in the contact list
    }

    if (!found) {  // Display a message if the contact is not found
        cout << "Contact with first name " << nameToEdit << " not found." << endl;
    }
}

/*******************************************************

 * Function Name: <deleteContact>

 * Purpose: <delete specific contact in List and update remaining ID's>

 * Parameter: <N/A>

 * Return: <void>

 *******************************************************/

void ContactMenu::deleteContact() const{
    string nameToDelete;

        cout << "Enter contact's first name to delete: "; // Prompt the user to enter the first name of the contact to delete
        cin >> nameToDelete;

        Node<Contact>* current = contactList.getHead();
        Node<Contact>* prev = nullptr;
        bool found = false;

    // Search for the contact to delete in the linked list
        while (current != nullptr) {
            if (current->data.getFirstName() == nameToDelete) {
                found = true;
                break;
            }
            prev = current;
            current = current->next;
        }

    // If the contact is found
        if (found) {
            if (prev != nullptr) {
                // If the contact to delete is not the head of the list
                prev->next = current->next;
                delete current; // delete current node
            } else {
                // If the contact to delete is the head of the list
                contactList.setHead(current->next);
                delete current; // delete current node
            }

            // Update IDs of the remaining contacts
            current = contactList.getHead();
            int newId = 1001;  // Starting ID
            while (current != nullptr) {
                current->data.setId(newId); // set new ID for each contact
                newId++;
                current = current->next;
            }
            // Display success message and updated contact list
            cout << "Contact with first name " << nameToDelete << " deleted successfully." << endl;
            contactList.displayContacts();
        } else {
            cout << "Contact with first name " << nameToDelete << " not found." << endl; // Display error message if the contact is not found
        }
}

/*******************************************************

 * Function Name: <doExit>

 * Purpose: <exit program>

 * Parameter: <N/A>

 * Return: <void>

 *******************************************************/

void ContactMenu::doExit() const{
    // Inform the user that the program is saving the contacts to a CSV file
    cout << "Saving contacts to CSV file..." << endl;

    // Initialize a CSVHandler object with the specified file path
    CSVHandler csvHandler("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab3_Manage Student Contacts/Lab3_Manage Student Contacts/contacts_data.csv");
    
    // Write the ContactList data to the CSV file
    csvHandler.writeContactsToFile(contactList);

    // Inform the user that the contacts have been saved successfully
    cout << "Contacts saved successfully." << endl;
}



/*******************************************************

 * Function Name: <ascendDescendList>

 * Purpose: <recieve choice on ascend/descedning then sort list>

 * Parameter: <N/A>

 * Return: <void>

 *******************************************************/
void ContactMenu::ascendDescendList() const{
    // Declare a variable to store the user's choice for sorting order
    int sortChoice;

    // Prompt the user to select the sorting order
//    cout << "Sort by (A)scending or (D)escending" << endl;
    cout << "\nSort in:\n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Enter your choice (1-2): ";

    // Read the user's choice from the console
    cin >> sortChoice;

    // Clear the input buffer to prevent any unwanted characters
    cin.ignore();

    // Check the user's choice and perform the sorting accordingly
    if (sortChoice == 1){
        // Sort the contact list in ascending order
        contactList.sort();
        // Display the sorted contact list
        contactList.displayContacts();
    } else if (sortChoice == 2){
        // Sort the contact list in ascending order first
        contactList.sort();
        // Reverse the order of the contact list to get descending order
        contactList.reverse();
        // Display the sorted contact list
        contactList.displayContacts();
    } else {
        // Inform the user of an invalid choice and return to the main menu
        cout << "Invalid choice. Returning to main menu" << endl;
    }
}



/*******************************************************

 * Function Name: <sortListByField>

 * Purpose: <sort list by a specific field>

 * Parameter: <N/A>

 * Return: <void>

 *******************************************************/
void ContactMenu::sortListByField(int field) const{
    // Switch statement to determine which field to sort by
    switch (field) {
        case FIRST_NAME:
            // Sort the contact list by first name
            contactList.sortByFirstName();
            // Display the sorted contact list
            contactList.displayContacts();
            break;
        case MIDDLE_NAME:
            // Sort the contact list by middle name
            contactList.sortByMiddleName();
            // Display the sorted contact list
            contactList.displayContacts();
            break;
        case LAST_NAME:
            // Sort the contact list by last name
            contactList.sortByLastName();
            // Display the sorted contact list
            contactList.displayContacts();
            break;
        case ADDRESS:
            // Sort the contact list by address
            contactList.sortByAddress();
            // Display the sorted contact list
            contactList.displayContacts();
            break;
        case PRIMARY_PHONE:
            // Sort the contact list by primary phone number
            contactList.sortByPrimaryPhone();
            // Display the sorted contact list
            contactList.displayContacts();
            break;
        case SECONDARY_PHONE:
            // Sort the contact list by secondary phone number
            contactList.sortBySecondaryPhone();
            // Display the sorted contact list
            contactList.displayContacts();
            break;
        case EMAIL:
            // Sort the contact list by email
            contactList.sortByEmail();
            // Display the sorted contact list
            contactList.displayContacts();
            break;
        default:
            // Handle an invalid field choice (no action needed)
            break;
    }
}


/*******************************************************

 * Function Name: <generateNewId>

 * Purpose: <generate new Id when new contact is created>

 * Parameter: <N/A>

 * Return: <void>

 *******************************************************/
int ContactMenu::generateNewId() const {
    int maxId = 0;  // Initialize the maximum ID to 0
    Node<Contact>* current = contactList.getHead();  // Get the head of the contact list

    // Traverse the contact list to find the maximum ID
    while (current != nullptr) {
        int currentId = current->data.getId();  // Retrieve the ID of the current contact
        if (currentId > maxId) {
            maxId = currentId;  // Update the maximum ID if the current ID is greater
        }
        current = current->next;  // Move to the next node in the list
    }

    // Return a new ID that is one greater than the current maximum ID
    return maxId + 1;
}



