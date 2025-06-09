#define _CRT_SECURE_NO_WARNINGS // For VS only

#include <ctime>
#include "utils.h"

using namespace std;
//Returns the system time
void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec) {
	time_t t = time(0);    // get time now
	tm* now = localtime(&t);

	mo = now->tm_mon + 1;
	d = now->tm_mday;
	yr = now->tm_year + 1900;

	hr = now->tm_hour;
	min = now->tm_min;
	sec = now->tm_sec;
}