#pragma once
#include <string>
#include "time.h"

using namespace std;


class DateTime : public Time {
public:
	DateTime(string dt);
	DateTime(int mon, int day, int yr);
	DateTime(int mon, int day, int yr, int hr, int min, int second);

	void toString();

private:
	int month;
	int day;
	int year;
};
