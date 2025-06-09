/**
* Author: Eden Meseret
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 04/20/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "menu.h"
#include "dateTime.h"

#include "Hashtable.hpp"
#include "taskList.h"
#include "task.h"

const string TASK_DATA = "/Users/edenmese/Desktop/Ohlone/2024/CS-124/Hashtable/Hashtable/task_data.csv";
enum COMMAND { ADD='a', EDIT='e', DELETE='d', PENDING = 'p', DONE = 'c', EXIT = 'x' };


class TaskMenu: public Menu{
    TaskMenu();
    TaskMenu(size_t numElements);
    ~TaskMenu();
    
    void viewPendingTasks();
    void viewCompletedTasks();
    void addNewTask();
    void editTask();
    void deleteTask();
    void activate();
    
protected:
    void init();
    void showOption(string title);
    
private:
    fstream inFile;
    Hashtable<string, Task>*tasksHashtable; //  using Hashtable instead of LinkedStack
};





//#pragma once
//#include <fstream>
//#include "menu.h"
//#include "task.h"
//#include "taskList.h"
//
//using namespace std;
//
//const string TASK_DATA = "task_data.csv";
//enum COMMAND { ADD='a', EDIT='e', DELETE='d', PENDING = 'p', DONE = 'c', EXIT = 'x' };
//
//class TaskMenu :public Menu {
//public:
//    TaskMenu();
//    ~TaskMenu();
//
//    void viewPendingTasks();
//    void viewCompletedTasks();
//    void addNewTask();
//    void editTask();
//    void deleteTask();
//    void activate();
//
//protected:
//    void init();
//    void showOption(string title);
//
//private:
//    fstream inFile;
//    TaskList* list;
//};
