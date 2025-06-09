#pragma once
#include <string>
#include "task.h"
#include "linkedSet.hpp"
/***********************************************************

 * Summary: Implementation of LinkedSet and TaskList classes.
 *          LinkedSet represents a set data structure with
 *          unique elements, providing operations like add,
 *          remove, and isEmpty. TaskList extends LinkedSet
 *          to manage a list of tasks, offering functions
 *          for task manipulation such as adding, editing,
 *          and deleting tasks.
 *
 * Changes from LinkedStack to LinkedSet:
 *  - Altered functionality to fit a set data structure.
 *  - Replaced stack-specific methods (push, pop, top) with
 *    set-specific methods (add, remove, isEmpty).
 *  - Adapted methods to maintain a set of unique elements
 *    instead of a stack's LIFO behavior.
 *
 ************************************************************/
using namespace std;

class TaskList : public LinkedSet<Task> {

public:
    /*******************************************************

    Function Name: TaskList

    WHAT I CHANGED: Constructor of the TaskList class.

    Parameter: None

    Return: None

    *******************************************************/
	TaskList();
    
    /*******************************************************

    Function Name: ~TaskList

    WHAT I CHANGED: Destructor of the TaskList class.

    Parameter: None

    Return: None

    *******************************************************/
	~TaskList();

    
    /*******************************************************

    Function Name: addNew

    WHAT I CHANGED: Adds a new task to the TaskList.

    Parameter: None

    Return: None

    *******************************************************/
	void addNew();
    
    /*******************************************************

    Function Name: editTask

    WHAT I CHANGED: Allows editing of an existing task in the TaskList.

    Parameter: None

    Return: None

    *******************************************************/
	void editTask();
    
    /*******************************************************

    Function Name: deleteTask

    WHAT I CHANGED: Deletes a task from the TaskList.

    Parameter: None

    Return: None

    *******************************************************/
	void deleteTask();
    
    /*******************************************************

    Function Name: printTable

    WHAT I CHANGED: Prints the tasks in the TaskList, optionally filtered by completion status.

    Parameter: complete - Optional parameter to filter tasks by completion status (default is true).

    Return: None

    *******************************************************/
	void printTable(bool complete = true);

protected:
    /*******************************************************

    Function Name: printRaw

    WHAT I CHANGED: Prints the tasks in the TaskList in a raw format, optionally filtered by completion status.

    Parameter: complete - Optional parameter to filter tasks by completion status (default is true).

    Return: None

    *******************************************************/
	void printRaw(bool complete = true);
    
    /*******************************************************

    Function Name: printRow

    WHAT I CHANGED: Prints a single task in a formatted row.

    Parameter: task - The task to print.

    Return: None

    *******************************************************/
	void printRow(const Task task);

private:
    
    /*******************************************************

    Function Name: printHeader

    WHAT I CHANGED: Prints the header for the table of tasks.

    Parameter: None

    Return: None

    *******************************************************/
	void printHeader();
};
