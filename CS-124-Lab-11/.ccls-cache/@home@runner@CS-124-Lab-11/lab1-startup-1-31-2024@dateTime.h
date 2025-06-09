#ifndef DATETIME_H
#define DATETIME_H

#include <string>
#include "time.h"

using namespace std;


class DateTime : public Time {
public:
  DateTime() {}
	DateTime(string dt);
	DateTime(int mon, int day, int yr);
	DateTime(int mon, int day, int yr, int hr, int min, int second);

	void toString();

private:
	int month;
	int day;
	int year;
};

#endif