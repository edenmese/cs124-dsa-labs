#include <iostream>
#include "time.h"

using namespace std;

void Time::toString() {
	cout << hour << ":" << minute << ":" << second << endl; // AM/PM or 24H
}