/**
* Author: Eden Meseret
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

#include "dateTime.h"
#include "menu.h"
#include "task.h"
#include "taskList.h"
#include "Hashtable.hpp"
#include "utils.h"

using namespace std;
using namespace key_val_hash;

//const string TASK_DATA = "task_data.csv";
enum COMMAND { ADD='a', EDIT='e', DELETE='d', PENDING = 'p', COMPLETE = 'c', QUIT = 'q' };

class TaskMenu: public Menu{
public: 
//    TaskMenu();
    TaskMenu(size_t numElements = 20);
    ~TaskMenu();
    
    void viewPendingTasks();
    void viewCompletedTasks();
    void addNewTask();
    void editTask();
    void deleteTask();
    void activate();
    bool isValidDate(const string& dateStr);
    
protected:
    void init();
    void showOption(string title);
    
private:
    fstream inFile;
    key_val_hash::Hashtable<string, Task>*tasksHashtable; //  pointer to Hashtable instead of LinkedStack
    unordered_map<string, Task> *tasksUnorderedMap; //  pointer to unordered_map
};
