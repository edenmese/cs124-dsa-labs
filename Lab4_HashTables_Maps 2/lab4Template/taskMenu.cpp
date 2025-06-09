/**
* Author: Eden Meseret
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "taskMenu.h"
#include "menu.h"
#include "dateTime.h"

using namespace std;

/*******************************************************

 * Function Name: <Task Menu Constructor>

 * WHAT I CHANGED : <taskMenu now takes the size numElements as a parameter and creates a new Hashtable and Map at initilization>

 * Parameter: <size_t numElements>

 * Return: <TaskMenu>

 *******************************************************/
TaskMenu::TaskMenu(size_t numElements) : Menu("Main Menu") {
    addOption("Add task");
    addOption("Edit task");
    addOption("Delete task");
    addOption("Pending tasks");
    addOption("Completed tasks");
    addOption("Quit");

    tasksHashtable = new Hashtable<string, Task>(numElements);
    tasksUnorderedMap = new unordered_map<string, Task>();
    
    init();
}

/*******************************************************

 * Function Name: <Task Menu deconstructor>

 * WHAT I CHANGED : <task menu checks that hashtable and maps are not set to nullptr then deletes >

 * Parameter: <N/A>

 * Return: <TaskMenu>

 *******************************************************/
TaskMenu::~TaskMenu() {
    if (tasksHashtable != nullptr) {
        delete tasksHashtable;
    }
    if (tasksUnorderedMap != nullptr) {
        delete tasksUnorderedMap;
    }
    inFile.close();
}


/*******************************************************

 * Function Name: <init>

 * WHAT I CHANGED : <implemented try catch to init function and reads file name from user input >

 * Parameter: <N/A>

 * Return: <TaskMenu>

 *******************************************************/
//implemented try-catch to init() function
void TaskMenu::init(){
    bool quit = false;
    
    while(!quit){
        quit = true;
        string fileName;
        cout << "Welcome to Tasks Menu!" << endl << endl;
        fileName = "/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab4_HashTables_Maps 2/Lab4_HashTables_Maps/test.csv";
        try{
            inFile.open(fileName.c_str());
            if (!inFile.is_open()){
                throw runtime_error("Failed to open the file");
            }
        }
            catch(const exception& e){
                cerr << "Error: " << e.what() << endl;
                quit = false;
            }
    }
        string text;
        string line = "";
        bool firstRow = true;
        while (getline(inFile, line)){
            if(firstRow){
                firstRow = false;
                continue;
            }
            stringstream ss(line);
            Task task;
            getline(ss,text, ',');
            task.setTerm(text);
            getline(ss, text, ',');
            task.setName(text);
            getline(ss, text, ',');
            task.setStartDate(text);
            getline(ss, text, ',');
            task.setEndDate(text);
            getline(ss, text, ',');
            task.setStatus(stoi(text));    // value =1 means DONE! and value = 0 is pending
            
            // Insert the task into the hashtable
            tasksHashtable->add(task.getName(), task);
            
            // Insert the task into the unordered_map
            (*tasksUnorderedMap)[task.getName()] = task;

            
//            list->push(task);
        }
        inFile.close();
    }

/*******************************************************

 * Function Name: <viewPendingTasks>

 * WHAT I CHANGED:  <Updated the function to print only the pending tasks stored in the tasksUnorderedMap. and added formating for better user viewing>

 * Parameter: <N/A>

 * Return: <TaskMenu>

 *******************************************************/
void TaskMenu::viewPendingTasks() {
    showOption(getName(3));

    // Print headers
    cout << left << setw(15) << "Term" << setw(20) << "Assignment Name" << setw(15) << "Start Date" << setw(15) << "End Date" << setw(10) << "Status" << endl;

    // Iterate through tasks and print each task
    for (const auto& pair : *tasksUnorderedMap) {
        if (!pair.second.isCompleted()) {
            // Print task details
            cout << left << setw(15) << pair.second.getTerm()
                 << setw(20) << pair.second.getName()
                 << setw(15) << pair.second.getStartDate().toString()
                 << setw(15) << pair.second.getEndDate().toString()
                 << setw(10) << pair.second.getStatus() << endl;
        }
    }
}
/*******************************************************

 * Function Name: <viewCompletedTasks>

 * WHAT I CHANGED: <Updated the function to print only the completed tasks stored in the tasksUnorderedMap. and added formating for better user viewing>

 * Parameter: <N/A>

 * Return: <TaskMenu>

 *******************************************************/
void TaskMenu::viewCompletedTasks() {
    showOption(getName(4));
    
    // Print headers
    cout << left << setw(15) << "Term"
         << setw(20) << "Assignment Name"
         << setw(15) << "Start Date"
         << setw(15) << "End Date"
         << setw(10) << "Status" << endl;
    
    // Print completed tasks
    for (const auto& pair : *tasksUnorderedMap) {
        if (pair.second.isCompleted()) {
            cout << left << setw(15) << pair.second.getTerm()
                 << setw(20) << pair.second.getName()
                 << setw(15) << pair.second.getStartDate().toString()  // Assuming DateTime::toString() exists
                 << setw(15) << pair.second.getEndDate().toString()    // Assuming DateTime::toString() exists
                 << setw(10) << pair.second.getStatus() << endl;
        }
    }
}

/*******************************************************

 * Function Name: <AddNewTask>

 * WHAT I CHANGED: <Updated the function to add a new task to both the tasksHashtable and tasksUnorderedMap. also implemented date validation using try-catch error>

 * Parameter: <N/A>

 * Return: <TaskMenu>

 *******************************************************/
void TaskMenu::addNewTask() {
    showOption(getName(0));
    Task newTask;
    string term, name;
    string startDate, endDate;
    
    
    
    try{
        cout << "Enter task details: " << endl;
        cout << "Term: ";
//        cin.ignore();
        getline(cin, term);
        newTask.setTerm(term);
        
        cout << "Name: ";
        getline(cin, name);
        newTask.setName(name);
        
        
    //    string startDate;
        cout << "Start Date (MM/DD/YYYY): ";
//        cin.ignore();
        getline(cin, startDate);
        if(!isValidDate(startDate)){
            throw invalid_argument("Invalid start date entered.");
        }
        newTask.setStartDate(startDate);
    
    cout << "End Date (MM/DD/YYYY): ";
//    cin.ignore();
    getline(cin, endDate);
    if(!isValidDate(endDate)){
        throw invalid_argument("Invalid start date entered.");
    }
    newTask.setEndDate(endDate);
    tasksHashtable->add(newTask.getName(), newTask);
    (*tasksUnorderedMap)[newTask.getName()] = newTask;
    cout << "New task added successfully!" << endl;
        
}catch(const exception& e){
    cerr << "Error: " << e.what() << endl;
}
    cout << endl;
    
    
}

/*******************************************************

 * Function Name: <editTask>

 * WHAT I CHANGED: <Updated the function to edit a task in both the tasksHashtable and tasksUnorderedMap.>

 * Parameter: <N/A>

 * Return: <TaskMenu>

 *******************************************************/

void TaskMenu::editTask() {
    showOption(getName(1));
    cout << "Enter the name of the task to edit: ";
    string taskName;
//    cin.ignore();
    
    getline(cin, taskName);
    
//    taskName = "/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab4_HashTables_Maps 2/lab4Template/task_data.csv";
    
    // Search for the task in the hashtable
    Task* taskPtr = tasksHashtable->search(taskName);
    if (taskPtr != nullptr) {
        Task editedTask = *taskPtr; // Make a copy of the task to edit
        
        //print the found task details
        cout << left << setw(15) << "Term"
                  << setw(20) << "Assignment Name"
                  << setw(15) << "Start Date"
                  << setw(15) << "End Date"
                  << setw(10) << "Status" << endl;
             
             cout << left << setw(15) << editedTask.getTerm()
                  << setw(20) << editedTask.getName()
                  << setw(15) << editedTask.getStartDate().toString()  // Assuming DateTime::toString() exists
                  << setw(15) << editedTask.getEndDate().toString()    // Assuming DateTime::toString() exists
                  << setw(10) << editedTask.getStatus() << endl;
        
        bool doneEditing = false;
        while (!doneEditing) {
            Menu editDetails("Enter new details for the task");
            editDetails.addOption("Term");
            editDetails.addOption("Name");
            editDetails.addOption("Start Date");
            editDetails.addOption("End Date");
            editDetails.addOption("Done Editing");
            
            // Display menu and get user choice
            int choice;
            cout << "Choose an option to edit the task:" << endl;
               cout << "1) Term" << endl;
               cout << "2) Name" << endl;
               cout << "3) Start Date" << endl;
               cout << "4) End Date" << endl;
               cout << "5) Done Editing" << endl;
            cin >> choice;
            
            switch (choice) {
                case 1: {
                    cout << "Enter new term: ";
                    cin.ignore();
                    string term;
                    getline(cin, term);
                    editedTask.setTerm(term);
                    break;
                }
                case 2: {
                    cout << "Enter new name: ";
                    cin.ignore();
                    string name;
                    getline(cin, name);
                    editedTask.setName(name);
                    break;
                }
                case 3: {
                    cout << "Enter new start date(MM/DD/YYYY): ";
                    cin.ignore();
                    string startDate;
                    getline(cin, startDate);
                    if(!isValidDate(startDate)){
                        throw invalid_argument("Invalid start date entered.");
                    }
                    editedTask.setStartDate(startDate);
                    break;
                }
                case 4: {
                    cout << "Enter new end date(MM/DD/YYYY): ";
                    cin.ignore();
                    string endDate;
                    getline(cin, endDate);
                    if(!isValidDate(endDate)){
                        throw invalid_argument("Invalid start date entered.");
                    }
                    editedTask.setEndDate(endDate);
                    break;
                }
                case 5: {
                    doneEditing = true;
                    break;
                }
                default:
                    cout << "Invalid choice." << endl;
                    break;
            }
            //print the updated task details after each edit
            cout << left << setw(15) << "Term"
                 << setw(20) << "Assignment Name"
                 << setw(15) << "Start Date"
                 << setw(15) << "End Date"
                 << setw(10) << "Status" << endl;
            cout << left << setw(15) << editedTask.getTerm()
                 << setw(20) << editedTask.getName()
                 << setw(15) << editedTask.getStartDate().toString()  // Assuming DateTime::toString() exists
                 << setw(15) << editedTask.getEndDate().toString()    // Assuming DateTime::toString() exists
                 << setw(10) << editedTask.getStatus() << endl;
                
        }
        
        // Update the task in the hashtable
        tasksHashtable->editValue(taskName, editedTask);
        
        // Update the task in the unordered_map
        (*tasksUnorderedMap)[taskName] = editedTask;
        
        cout << "Task edited successfully!" << endl;
    } else {
        cout << "Task not found." << endl;
    }

    cout << endl;
}


/*******************************************************

 * Function Name: <deleteTask>
 * WHAT I CHANGED: <Updated the function to delete a task from both the tasksHashtable and tasksUnorderedMap.>
 * Parameter: <N/A>

 * Return: <TaskMenu>

 *******************************************************/
void TaskMenu::deleteTask() {
    showOption(getName(2));
    cout << "Enter task to delete: ";
    string taskName;
//    cin.ignore();
    getline(cin, taskName);
    
    if (tasksHashtable->search(taskName)){
        tasksHashtable->deleteKey(taskName);
        tasksUnorderedMap->erase(taskName);
        cout << "Task deleted successfully!" << endl;
    } else {
        cout << "Task not found." << endl;
    }
    
    cout << endl;
}

/*******************************************************

 * Function Name: <isValidDate>
 * WHAT I CHANGED: <this is a date validation function that is implemented to addTask to check if date that user input are of valid numbers>
 * Parameter: <const string &dateStr>

 * Return: <TaskMenu>

 *******************************************************/
bool TaskMenu::isValidDate(const string &dateStr){
    // Parse the date string
    stringstream ss(dateStr);
    int day, month, year;
    char delimiter;
    ss >> month >> delimiter >> day >> delimiter >> year;
    
    // Check if parsing succeeded and date components are within valid ranges
    if (ss.fail() || ss.peek() != EOF || month < 1 || month > 12 || day < 1 || day > 31 || year < 0) {
        return false;
    }
    
    // Check if the date components are reasonable
    if (month > 12 || day > 31 || year > 9999) {
        return false;
    }
    
    // Check for valid months and days
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > daysInMonth[month - 1]) {
        // Check for February in a leap year
        if (month == 2 && day == 29 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            return true;
        }
        return false;
    }
    
    // Date is valid
    return true;
}

/*******************************************************

 * Function Name: <deleteTask>
 * WHAT I CHANGED: <Added saveTocsv (EXTRA CREDIT)>
 * Parameter: <N/A>

 * Return: <TaskMenu>

 *******************************************************/
void TaskMenu::activate() {
    char command = COMMAND::ADD;
    while (command != QUIT) {
        command = doMenuOption();
        switch (command) {
        case ADD://a
            addNewTask();
            break;
        case EDIT://e
            editTask();
            break;
        case DELETE://d
            deleteTask();
            break;
        case PENDING://p
            viewPendingTasks();
            break;
        case COMPLETE://c
            viewCompletedTasks();
            break;
        case QUIT: //q
                // Save tasks to CSV before exiting
                saveToCSV("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab4_HashTables_Maps 2/Lab4_HashTables_Maps/test.csv", *tasksUnorderedMap);
                cout << "Tasks saved to task_data.csv" << endl;
                cout << "Bye!" << endl;
                break;
        default:
            cout << "Not a valid command. Please try again." << endl << endl;
            break;
        }
    }
}

void TaskMenu::showOption(const string title) {
    cout << "***** " << title << " *****" << endl;
}



