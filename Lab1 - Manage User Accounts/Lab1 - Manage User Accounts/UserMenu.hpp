//
//  Menu.hpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/9/24.
//

#ifndef UserMenu_hpp
#define UserMenu_hpp
#include "User.hpp"
#include "Menu.hpp"
#include "DateTime.hpp"
#include <vector>
#include <ostream>
#include <fstream>
#include <string>
//#include <stdio.h>

using namespace std;


enum USER_MENU_OPTIONS {
  USER_MENU_SIGNIN = '1',
  USER_MENU_SIGNOUT = '2',
  USER_MENU_RESET = '3',
  USER_MENU_CREATE = '4',
  USER_MENU_MANAGEPROFILES = '5',
  USER_MENU_DOEXIT = 'x',
};


class UserMenu : public Menu{
public:
    UserMenu();
    ~UserMenu();
    
    void activate();
    void loadCSV(const string filename);


    
    void signIn();
    void signOut();
    void reset();
    void create();
    void manageProfiles();
    void deleteAccount();
    void removeInformation();
    void forgotPassword();


    void doExit();
    
    int signedInUserIndex = -1; // Initialize to invalid index

    
    
    
    
private:
    //User user;
    vector<User>list;
    fstream myFile;
    bool signedIN = false;
    bool isTempUserInList() const;
    User tempUser;




    
    
    
};


#endif /* UserMenu_hpp */
