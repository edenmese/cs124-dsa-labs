//
//  Menu.cpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#include "Menu.hpp"
#include "GradeBookMenu.hpp"



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
void Menu::displayMenu(GradeBookMenu& menuChoice){
    quit = false;
    do{
        cout << "***** Welcome to the GradeBook! ******" << endl;
        cout << "1) Display Assignments and Categories" << endl;
        cout << "2) View A Category" << endl;
        cout << "3) Add New Assignment" << endl;
        cout << "4) Edit Assignment" << endl;
        cout << "5) Delete Assignment" << endl;
        cout << "6) View Courses and Faculty" << endl;
        cout << "7) Calculate Grade" << endl;
        cout << "x) Exit and Save\n" << endl;
        
        char choice = getChoice(); // get users choice
        
        switch (choice) {
            case DISPLAY_LIST:
                cout << "-- Display Assignments and Categories --" << endl;
                menuChoice.displayGradeBookCategories();
                break;
            case VIEW_CATEGORIES:
                cout << "-- View A Category --" << endl;
                menuChoice.viewGradeBookCategory();
                break;
            case ADD_ASSIGNMENT:
                cout << "-- Add New Assignment --" << endl;
                menuChoice.addAssignment();
                break;
            case EDIT_ASSIGNMENT:
                cout << "-- Edit Assignment --" << endl;
                menuChoice.editAssignment();
                break;
            case REMOVE_ASSIGNMENT:
                cout << "-- Delete Assignment --" << endl;
                menuChoice.removeAssignment();
                break;
                
            case VIEW_COURSES:
                menuChoice.displayCoursesAndFaculty();
                break;
            case CALCULATE_GRADE:
                cout << " -- Calculate Grade --" << endl;
                menuChoice.calculateGrade();
                break;
            case DO_EXIT:
                cout << "-- Exit and Save Assignments --" << endl;
                menuChoice.doExit();
                cout << "Goodbye !!" << endl;
                quit = true;
                
                break;
                
            default:
                break;
        }
    }while(!quit);
}


