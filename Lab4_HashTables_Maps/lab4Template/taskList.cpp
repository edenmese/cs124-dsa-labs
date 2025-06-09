/**
* Author: Eden Meseret
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "taskList.h"
#include "task.h"

using namespace std;
/*******************************************************
 * class Name: TaskList constructor
 *
 * WHAT I CHANGED: Constructs an empty TaskList.
 *
 * parameter: None
 *******************************************************/
TaskList::TaskList() {}

/*******************************************************
 * class Name: ~TaskList
 *
 * WHAT I CHANGED: Destructs a TaskList.
 *******************************************************/
TaskList::~TaskList() {}

/*******************************************************
 * class Name: addNew
 *
 * WHAT I CHANGED: Adds a new task to the TaskList.
 *
 * parameter: None
 *******************************************************/
void TaskList::addNew() {
    Task task;
    cin >> task;
    insert(task);
}

/*******************************************************
 * class Name: editTask
 *
 * WHAT I CHANGED: Edits a task in the TaskList.
 *
 * parameter: None
 *******************************************************/
void TaskList::editTask() {
    string name;
    cout << "Edit task name: ";
    cin.ignore();
    getline(cin, name);
    typename LinkedSet<Task>::LinkedSetIterator iter = begin();
    while (!iter.equals(end())) {
        if (iter.get().getName() == name) {
            // Edit the task
            // cin >> iter.get();
            break;
        }
        iter.next();
    }
}

/*******************************************************
 * class Name: deleteTask
 *
 * WHAT I CHANGED: Deletes a task from the TaskList.
 *
 * parameter: None
 *******************************************************/
void TaskList::deleteTask() {
    string name;
    cout << "Delete task name: ";
    cin.ignore();
    getline(cin, name);
    typename LinkedSet<Task>::LinkedSetIterator iter = begin();
    while (!iter.equals(end())) {
        if (iter.get().getName() == name) {
            // Erase the task
            // erase(iter);
            break;
        }
        iter.next();
    }
}

/*******************************************************
 * class Name: printTable
 *
 * WHAT I CHANGED: Prints a formatted table of tasks from the TaskList.
 *
 * parameter: complete - bool flag indicating whether to print completed tasks or not
 *******************************************************/
void TaskList::printTable(bool complete) {
    typename LinkedSet<Task>::LinkedSetIterator iter = begin();
    printHeader();
    while (!iter.equals(end())) {
        if (iter.get().isCompleted() == complete) {
            printRow(iter.get());
        }
        iter.next();
    }
    cout << endl;
}

/*******************************************************
 * class Name: printHeader
 *
 * WHAT I CHANGED: Prints the header row for the task table.
 *******************************************************/
void TaskList::printHeader() {
    const char originalFill = cout.fill();
    cout << left << setw(10) << "Term"
        << left << setw(30) << "Name"
        << left << setw(15) << "Start Date"
        << left << setw(15) << "End Date"
        << left << setw(10) << "Status"
        << endl;
    cout << setfill('=') << setw(80) << "=" << endl;
    cout.fill(originalFill);
}

/*******************************************************
 * class Name: printRow
 *
 * WHAT I CHANGED: Prints a single row of task information.
 *
 * parameter: task - Task object to print
 *******************************************************/
void TaskList::printRow(const Task task) {
    const char originalFill = cout.fill();
    cout << left << setw(10) << task.getTerm()
        << left << setw(30) << task.getName()
        << left << setw(15) << task.getStartDate().toString()
        << left << setw(15) << task.getEndDate().toString()
        << left << setw(10) << (task.isCompleted() ? "Done" : "Pending")
        << endl;
    cout.fill(originalFill);
}

/*******************************************************
 * class Name: printRaw
 *
 * WHAT I CHANGED: Prints raw task information without formatting.
 *
 * parameter: complete - bool flag indicating whether to print completed tasks or not
 *******************************************************/
void TaskList::printRaw(bool complete) {
    typename LinkedSet<Task>::LinkedSetIterator iter = begin();
    while (!iter.equals(end())) {
        if (iter.get().isCompleted() == complete) {
            cout << iter.get() << endl;
        }
        iter.next();
    }
    cout << endl;
}
