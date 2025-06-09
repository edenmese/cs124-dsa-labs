/**
* Author: Eden Meseret
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <iomanip>
#include "taskMenu.h"

using namespace std;


/**
   Computes the hash code for a string.
   @param str a string
   @return the hash code
*/
int hash_code(const string& str);

void showBanner();

int main() {
	showBanner();
    TaskMenu menu;
    menu.activate();

	return 0;
}

/**
 * showBanner - print me first
 **/
void showBanner() {
	const char originalFill = cout.fill();
	cout << setfill('*') << setw(50) << "*" << endl << endl;
	cout << "\tApplication to Manage Tasks (FINAL EXAM UPDATE)" << endl;
	cout << "\t===========================" << endl;
	cout << "\tProgram written by: Eden Meseret"<< endl;
	cout << "\tCourse info: CS-124-03" << endl;
	cout << "\tDue date: 05/13/2024"<< endl << endl;
	cout << setfill('*') << setw(50) << "*" << endl << endl;
	cout.fill(originalFill);
}

int hash_code(const string& str)
{
    int h = 0;
    for (int i = 0; i < str.length(); i++)
    {
        h = 31 * h + str[i];
    }
    return h;
}
