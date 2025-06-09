#include "userMenu.h"
#include <fstream>
#include <sstream>


using namespace std;
UserMenu::UserMenu()
{ addOption("1) Sign-in");
  addOption("3) Sign Out");
  addOption("3) Reset Password");
  addOption("4) Create Account");
  addOption("5 Manage Profiles");
  addOption("X) Quit");
}

void UserMenu::activate()
{
  char input = 0;
  do {
    input = this->doMenuOption();
    if (input == USER_MENU_SIGNIN) {
      this->signIn();
    } else if (input == USER_MENU_SIGNOUT) {
      this->signOut();
    } else if (input == USER_MENU_RESET) {
      this->reset();
    } else if (input == USER_MENU_CREATE) {
      this->create();
    } else if (input == USER_MENU_MANAGE_PROFILES) {
      this->manageProfiles();
    } else if (input == USER_MENU_EXIT) {
      this->doExit();
    } else {
      cout << "Invalid selection!\n";
    }
    cout << "Input: " << input << endl;
  } while (input != '6');
}

void UserMenu::signIn() {
  //cout << "Handle sign-in\n\n";
  /**
  - Enter email or mobile phone number
  - Enter password
  - Update sign in datetime
  **/
}

void UserMenu::signOut() {
  cout << "Handle sign-in\n\n";
  /**
  - User must be already sign-in
  - Update sign out datetime
  - Save new sign-in and sign-out datetime to users_data.csv
  **/
}

void UserMenu::reset() {
  cout << "Handle reset password\n\n";
  /**
  - User must be already sign-in
  - Enter old password
  - Enter new password
  - Save new password to users_data.csv
  **/
}

void UserMenu::create() {
  cout << "Handle create new user\n\n";
  /**
  4)Create account
  - Enter first and last name
  - Enter mobile number or email
  - Enter password
  - Enter re-enter password
  - Forgot your password? Only role=admin can reset your password.
  - Save new sign-in, sign-out datetime, and data to users_data.csv
  **/
}

void UserMenu::manageProfiles() {
  cout << "Handle manage profiles\n\n";
  /**
  - User must be already sign-in
  - Allow user to change (update or delete) personal information, name, role, address, phone, email
  - Save new data to users_data.csv


  **/
}

void UserMenu::doExit() {
  cout << "Handle exit\n\n";
  //- Enter char 'x' to exit Sign Out and update sign out datetime.
}

