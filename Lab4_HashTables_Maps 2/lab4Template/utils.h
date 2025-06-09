/**
* Author: Eden Meseret
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#pragma once
#include <fstream>
#include <string>
#include <unordered_map>
#include "task.h"

using namespace std;

void openFile(fstream& inFile, string fileName);

void saveToCSV(const string& fileName, const unordered_map<string, Task>& tasks); // added this function (extra credit) for saving to csv

//Returns the system time
void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec);

string getDateTimeNow();


