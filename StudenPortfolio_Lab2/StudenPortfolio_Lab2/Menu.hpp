//
//  Menu.hpp
//  StudenPortfolio_Lab2
//
//  Created by Eden Meseret on 3/26/24.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include <string>
#include "StudentPortfolio.hpp"

class Menu {
public:
    // Display the menu
    void displayMenu() const;

    // Get user choice from menu
    char getUserChoice() const;

    // Activate the program
    void activate();

private:
    StudentPortfolio portfolio;
};


#endif /* Menu_hpp */
