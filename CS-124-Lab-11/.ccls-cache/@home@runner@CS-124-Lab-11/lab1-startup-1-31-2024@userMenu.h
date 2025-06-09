#ifndef USERMENU_H
#define USERMENU_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "menu.h"
#include "user.h"

enum USER_MENU_OPTION {
USER_MENU_SIGNIN = '1',
USER_MENU_SIGNOUT = '2',
USER_MENU_CREATE = '3',
USER_MENU_REMOVE = '4',
USER_MENU_RESET = '5',
USER_MENU_MANAGE_PROFILES = '6',
USER_MENU_EXIT = 'x',
};

class UserMenu : public Menu {
public:
	
  UserMenu();
  // The menu options
  void signIn();
	void signOut();
	void reset();
	void create();
	void manageProfiles();
  void doExit();

	void activate();

private:
  // Member variables and any other variables if necessary
  fstream inFile;
  User user;
  vector<User> users;
};

#endif


