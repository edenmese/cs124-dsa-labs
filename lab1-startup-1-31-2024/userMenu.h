#pragma once
#include "menu.h"

class UserMenu : public Menu {
public:
	// The menu options
	void signIn();
	void singOut();
	void reset();
	void create();
	void manageProfiles();

	void activate();

private:
	// TBD
};