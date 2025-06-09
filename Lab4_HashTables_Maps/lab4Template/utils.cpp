/**
* Author: Eden Meseret
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/
#define _CRT_SECURE_NO_WARNINGS // supress localtime warning

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "utils.h"

using namespace std;

//Returns the system time
void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec) {
	time_t t = std::time(0);    // get time now
	tm* now = localtime(&t);

	mo = now->tm_mon + 1;
	d = now->tm_mday;
	yr = now->tm_year + 1900;

	hr = now->tm_hour;
	min = now->tm_min;
	sec = now->tm_sec;
}

string getDateTimeNow() {
	int mo, d, yr, hr, min, sec;
	// Format ex. 2/6/2023 18:30:01   
	getCurrentTime(mo, d, yr, hr, min, sec);
	/*DateTime dt;
	dt.setMonth(mo);
	dt.setDay(d);
	dt.setYear(yr);
	dt.setHour(hr);
	dt.setMinute(min);
	dt.setSecond(sec);

	return dt.toString();
	*/
	return "";
}

void openFile(fstream& inFile, string fileName) {
	inFile.open(fileName);
}


/*******************************************************
 * private function Name: <saveToCSV>

 * WHAT I CHANGED : <Saves task data from an unordered_map into a CSV file.>

 * parameter: <const string& fileName, const unordered_map<string, Task>& tasks>
 *******************************************************/
void saveToCSV(const string& fileName, const unordered_map<string, Task>& tasks) {
    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }

    // Write header
    outFile << "Term,Name,Start Date,End Date,Status" << endl;

    // Write tasks
    for (const auto& pair : tasks) {
        const Task& task = pair.second;
        outFile << task.getTerm() << "," << task.getName() << ","
                << task.getStartDate().toString() << ","
                << task.getEndDate().toString() << ","
                << task.getStatus() << endl;
    }

    outFile.close();
}
