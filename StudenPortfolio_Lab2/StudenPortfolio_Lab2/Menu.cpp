//
//  Menu.cpp
//  StudenPortfolio_Lab2
//
//  Created by Eden Meseret on 3/26/24.
//

#include "Menu.hpp"

#include <iostream>

void Menu::displayMenu() const {
    cout << "\n \n ***** Computer Science Transfer Courses *****" << endl;
    cout << "1) List of Courses" << endl;
    cout << "2) View Course Details" << endl;
    cout << "3) Add New Course" << endl;
    cout << "4) Edit Course" << endl;
    cout << "5) Remove Course" << endl;
    cout << "x) Quit" << endl;
}

char Menu::getUserChoice() const {
    string input;
    cout << "Enter your choice: ";
    cin >> input;
    return input.empty() ? '0' : input[0];
}

void Menu::activate() {
    char choice;
    do {
        displayMenu();
        choice = getUserChoice();
        int order = 0;
        string courseNumber = "";

        switch (choice) {
        case '1':
            cout << "Choose: \n 1- Ascending \n 2- Descending" << endl;
            cin >> order;
            portfolio.viewList(order);
            break;
        case '2':
            cout << "Enter the course number; e.g. 101A" << endl;
            cin >> courseNumber;
            portfolio.viewCourse(courseNumber);
            break;
        case '3':
            portfolio.addCourse();
            break;
        case '4':
            cout << "Enter the course number; e.g. 101A" << endl;
            cin >> courseNumber;
            portfolio.editCourse(courseNumber);
            break;
        case '5':
            cout << "Enter the course number; e.g. 101A" << endl;
            cin >> courseNumber;
            portfolio.removeCourse(courseNumber);
            break;
        case 'x':
            portfolio.quit();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 'x');
}
