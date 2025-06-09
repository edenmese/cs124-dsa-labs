#include <iostream>
#include <string>
#include "dateTime.h"
#include "time.h"


DateTime::DateTime(int mon, int day, int yr, int hr, int min, int second) 
	: Time(hr, min, second) {
	month = mon;
	this->day = day;
	year = yr;
}

DateTime::DateTime(string dt) {
	// TODO
}


DateTime::DateTime(int mon, int day, int yr)
	: Time(0, 0, 0) {

}

void DateTime::toString() {
	cout << month << "/" << day << "/" << year << " " << getHour() << ":" << getMinute() << ":" << getSecond() << endl;
}