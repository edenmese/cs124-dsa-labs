#include "userMenu.h"
using namespace std;

int main() {
	//UserMenu menu;
	Menu main_menu;
	main_menu.addOption("1) Sign-in");
	main_menu.addOption("2) Sign Out");
	main_menu.addOption("3) Reset Password");
	main_menu.addOption("4) Create Account");
	main_menu.addOption("5) Manage Profiles");
	main_menu.addOption("x) Quit");
	int input = 0;
	do {
		input = main_menu.doMenuOption();
		cout << "Input: " << input << endl;
	} while (input <= 4);

	return 0;
	return 0;
}