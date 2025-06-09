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

TaskList::TaskList() {}

TaskList::~TaskList() {}

/*******************************************************

 * Function Name: addNew

 * WHAT I CHANGED: Added a new task to the TaskList.

 * Detailed Changes:
 * - Replaced the use of 'push' method with 'add' method to add a task to the TaskList.
 * - Removed the local variable 'task' and directly added the task obtained from input to the TaskList.
 * - Changed the method of obtaining the task from input to match the LinkedSet's 'add' method.

 * Parameter: None

 * Return: None

 *******************************************************/
void TaskList::addNew() {
	Task task;
	cin >> task;
    add(task);
//	push(task);
}

/*******************************************************

 * Function Name: editTask

 * WHAT I CHANGED: Allows editing of an existing task in the TaskList.

 * Detailed Changes:
 * - Replaced the use of 'pop' method with 'remove' method to remove a task from the TaskList.
 * - Replaced the use of 'top' method with 'getTop' method to get the top task from the TaskList.
 * - Removed the local variable 'tmpList' and directly operated on 'this' TaskList.
 * - Added a new TaskList 'newList' to store the modified tasks.
 * - Changed the method of obtaining task name from input to match the LinkedSet's 'contains' method.
 * - Changed the method of obtaining the current task from the TaskList to match the LinkedSet's 'getTop' method.
 * - Removed the unnecessary use of 'this->initialize()' and 'newList.reverseStack(*this)' as they are not applicable to LinkedSet.

 * Parameter: None

 * Return: None

 *******************************************************/
void TaskList::editTask() {
    TaskList tmpList = *this;
    TaskList newList;
    string name;
    cout << "Edit task name: ";
    cin.ignore();
    getline(cin, name);
    while (!tmpList.isEmpty()) {
        Task currentTask = tmpList.getTop(); // Get the current task
        tmpList.remove(currentTask);      // Remove the current task from tmpList

        if (currentTask.getName() == name) {
            // Edit the task
            cin >> currentTask;
        }
        newList.add(currentTask); // Add the task to newList
    }
    *this = newList; // Update this TaskList with the contents of newList
}

/*******************************************************

 * Function Name: deleteTask

 * WHAT I CHANGED: Deletes a task from the TaskList.

 * Detailed Changes:
 * - Replaced the use of 'pop' method with 'remove' method to remove a task from the TaskList.
 * - Replaced the use of 'top' method with 'getTop' method to get the top task from the TaskList.
 * - Removed the local variable 'tmpList' and directly operated on 'this' TaskList.
 * - Added a new TaskList 'newList' to store the remaining tasks.
 * - Changed the method of obtaining task name from input to match the LinkedSet's 'contains' method.
 * - Changed the method of obtaining the current task from the TaskList to match the LinkedSet's 'getTop' method.
 * - Removed the unnecessary use of 'this->initialize()' and 'newList.reverseStack(*this)' as they are not applicable to LinkedSet.

 * Parameter: None

 * Return: None

 *******************************************************/
void TaskList::deleteTask() {
    TaskList tmpList = *this;
    TaskList newList;
    string name;
    cout << "Delete task name: ";
    cin.ignore();
    getline(cin, name);
    while (!tmpList.isEmpty()) {
        Task currentTask = tmpList.getTop(); // Get the current task
        tmpList.remove(currentTask);      // Remove the current task from tmpList

        if (currentTask.getName() != name) {
            newList.add(currentTask); // Add the task to newList if its name doesn't match
        }
    }
    *this = newList; // Update this TaskList with the contents of newList
}

//void TaskList::editTask() {
//	TaskList tmpList = *this;
//	TaskList newList;
//	string name;
//	cout << "Edit task name: ";
//	cin.ignore();
//	getline(cin, name);
//	while (!tmpList.isEmpty()) {
//		if (tmpList.top().getName() == name) {
//			// edit - top is actually a task
//			cin >> tmpList.top();
//		}
//		newList.push(tmpList.top());
//		tmpList.pop();
//	}
//	this->initialize();
//	newList.reverseStack(*this);
//}
//void TaskList::deleteTask() {
//	TaskList tmpList = *this;
//	TaskList newList;
//	string name;
//	cout << "Delete task name: ";
//	cin.ignore();
//	getline(cin, name);
//	bool deleteMe = false;
//	while (!tmpList.isEmpty()) {
//		if (tmpList.top().getName() == name) {
//			deleteMe = true;
//		}
//		if (!deleteMe) {
//			newList.push(tmpList.top());
//		}
//		tmpList.pop();
//		deleteMe = false;
//	}
//	this->initialize();
//	newList.reverseStack(*this);
//}

/*******************************************************

 * Function Name: printTable

 * WHAT I CHANGED: Prints the tasks in the TaskList table, optionally filtered by completion status.

 * Detailed Changes:
 * - Removed the unnecessary use of 'this->initialize()' and 'newList.reverseStack(*this)' as they are not applicable to LinkedSet.
 * - Removed the use of 'reverseStack' and 'top' methods as they are not applicable to LinkedSet.
 * - Utilized 'getSetHead' method to access the head of the LinkedSet.
 * - Modified the loop to iterate through the LinkedSet elements using the 'link' member.
 * - Added condition to check task completion status before adding to 'reverseList'.
 * - Utilized 'add' method to add tasks to 'reverseList'.

 * Parameter:
 * - complete: Optional parameter to filter tasks by completion status (default is true).

 * Return: None

 *******************************************************/
void TaskList::printTable(bool complete) {
    TaskList tmpList = *this;
    TaskList reverseList;

    // Add only the tasks that match the completion status to the reverseList
    LinkedSetNode<Task>* current = tmpList.getSetHead();
    while (current != nullptr) {
        if (current->info.isCompleted() == complete) {
            reverseList.add(current->info);
        }
        current = current->link;
    }

    // Print the header
    printHeader();

    // Print the tasks in reverse order
    current = reverseList.getSetHead();
    while (current != nullptr) {
        printRow(current->info);
        current = current->link;
    }

    cout << endl;
}

//void TaskList::printTable(bool complete) {
//	// assignment operator
//	TaskList tmpList = *this;
//
//	// reverse the list
//	TaskList reverseList;
//	tmpList.reverseStack(reverseList);
//
//	// Show pending tasks
//	printHeader();
//	while (!reverseList.isEmpty()) {
//		if (reverseList.top().isCompleted() == complete) {
//			printRow(reverseList.top());
//		}
//		reverseList.pop();
//	}	
//	cout << endl;
//}
/*******************************************************

 * Function Name: printHeader

 * WHAT I CHANGED: Prints the header for the table of tasks.

 * Detailed Changes:
 * - No changes made as the method is independent of the data structure.

 * Parameter: None

 * Return: None

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

 * Function Name: printRow

 * WHAT I CHANGED: Prints a single task in a formatted row.

 * Detailed Changes:
 * - No changes made as the method is independent of the data structure.

 * Parameter:
 * - task: The task to print.

 * Return: None

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

 * Function Name: printRaw

 * WHAT I CHANGED: Prints the tasks in the TaskList in a raw format, optionally filtered by completion status.

 * Detailed Changes:
 * - Removed the unnecessary use of 'this->initialize()' and 'newList.reverseStack(*this)' as they are not applicable to LinkedSet.
 * - Removed the use of 'reverseStack' and 'top' methods as they are not applicable to LinkedSet.
 * - Utilized 'getSetHead' method to access the head of the LinkedSet.
 * - Modified the loop to iterate through the LinkedSet elements using the 'link' member.
 * - Added condition to check task completion status before adding to 'reverseList'.
 * - Utilized 'contains' method to check if the task exists in the TaskList.

 * Parameter:
 * - complete: Optional parameter to filter tasks by completion status (default is true).

 * Return: None

 *******************************************************/
void TaskList::printRaw(bool complete) {
    TaskList tmpList = *this;
    TaskList reverseList;

    // Get the head pointer of tmpList
    LinkedSetNode<Task>* current = tmpList.getSetHead();

    // Add only the tasks that match the completion status to the reverseList
    while (current != nullptr) {
        if (tmpList.contains(current->info) && current->info.isCompleted() == complete) {
            reverseList.add(current->info);
        }
        current = current->link;
    }

    // Print the tasks in reverse order
    current = reverseList.getSetHead();
    while (current != nullptr) {
        cout << current->info << endl;
        current = current->link;
    }
    cout << endl;
}

//void TaskList::printRaw(bool complete) {
//	// assignment operator
//	TaskList tmpList = *this;	
//
//	// reverse the list
//	TaskList reverseList;
//	tmpList.reverseStack(reverseList);
//
//	// Show pending tasks
//	while (!reverseList.isEmpty()) {
//		if (reverseList.top().isCompleted() == complete) {
//			cout << reverseList.top() << endl;
//		}
//		reverseList.pop();
//	}
//	cout << endl;
//}
