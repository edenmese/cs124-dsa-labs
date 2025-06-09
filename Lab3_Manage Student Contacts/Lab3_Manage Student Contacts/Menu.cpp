//
//  Menu.cpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/25/24.
//

#include "Menu.hpp"
#include "ContactMenu.hpp"



/*******************************************************

 * Function Name: <Menu>

 * Purpose: <constructor>

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
Menu::Menu(){}


/*******************************************************

 * Function Name: <~Menu>

 * Purpose: <destructor>

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
Menu::~Menu(){}




/*******************************************************

 * Function Name: <getChoice>

 * Purpose: <get user's choice for menu>

 * Parameter: <N/A>

 * Return: <char>

 *******************************************************/
char Menu::getChoice()const{
    char choice;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();
    return choice;
}


/*******************************************************

 * Function Name: <displayMenu>

 * Purpose: <displays main user menu>

 * Parameter: <contactMenu reference object menuChoice>

 * Return: <void>

 *******************************************************/
void Menu::displayMenu(ContactMenu& menuChoice){
    quit = false;
    do{
        cout << "***** Contact Menu ******" << endl;
        cout << "1) List of Contacts" << endl;
        cout << "2) View a Contact" << endl;
        cout << "3) Add New Contact" << endl;
        cout << "4) Edit Contact" << endl;
        cout << "5) Delete Contact" << endl;
        cout << "x) Exit and Save\n" << endl;
        
        char choice = getChoice(); // get users choice
        
        switch (choice) {
            case LIST_OF_CONTACTS:
                cout << "-- List Contacts --" << endl;
                menuChoice.listContacts();
                break;
            case VIEW_CONTACT:
                cout << "-- View a Contact --" << endl;
                menuChoice.viewContact();
                break;
            case ADD_CONTACT:
                cout << "-- Add New Contact --" << endl;
                menuChoice.addNewContact();
                cout << "Contact added successfully:" << endl;
                break;
            case EDIT_CONTACT:
                cout << "-- Edit Contact --" << endl;
                menuChoice.editContact();
                break;
            case DELETE_CONTACT:
                cout << "-- Delete Contact --" << endl;
                menuChoice.deleteContact();
                break;
            case DO_EXIT:
                cout << "-- Exit and Save --" << endl;
                menuChoice.doExit();
                cout << "Goodbye !!" << endl;
                quit = true;
                
                break;
                
            default:
                break;
        }
    }while(!quit);
}



