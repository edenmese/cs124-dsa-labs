/**
* Author: John Doe
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024d*/


#include "taskMenu.h"

TaskMenu::TaskMenu(){}


TaskMenu::TaskMenu(size_t numElements) : Menu("Main Menu") {
	addOption("a) Add task");
	addOption("e) Edit task");
	addOption("d) Delete task");
	addOption("p) List pending tasks");
	addOption("c) List completed tasks");
	addOption("x) Exit");

	tasksHashtable = new Hashtable<string, Task>(numElements);
	init();
}

TaskMenu::~TaskMenu() {
    if(tasksHashtable != nullptr){
        delete tasksHashtable;
    }
	inFile.close();
}



//implemented try-catch to init() function
void TaskMenu::init(){
    bool quit = false;
    
    while(!quit){
        quit = true;
        string fileName;
        cout << "Enter the name of the file: ";
        cin >> fileName;
        
        try{
            inFile.open(fileName);
            if (!inFile.is_open()){
                throw runtime_error("Failed to open the file"); // why use throw if there is catch? if there is an error doesnt the computer stop and then figure it out?
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
            
            //insert the task into the hashtable
            tasksHashtable->add(task.getName(), task);
//            list->push(task);
        }
        inFile.close();
    }


//void TaskMenu::init() {
//	inFile.open(TASK_DATA);
//
//	string text;
//	string line = "";
//	bool firstRow = true;
//	while (getline(inFile, line)) {
//		// Skip the first row
//		if (firstRow) {
//			firstRow = false;
//			continue;
//		}
//		stringstream ss(line);		
//		Task task;
//		getline(ss, text, ',');
//		task.setTerm(text);
//		getline(ss, text, ',');
//		task.setName(text);
//		getline(ss, text, ',');
//		task.setStartDate(text);
//		getline(ss, text, ',');
//		task.setEndDate(text);
//		getline(ss, text, ',');
//		task.setStatus(stoi(text));	// value =1 means DONE! and value = 0 is pending
//		list->push(task);
//	}
//	inFile.close();
//}

void TaskMenu::viewPendingTasks() {
	showOption(getName(3).substr(3));
    tasksHashtable->printValues(false);
//	list->printTable(false);
}

void TaskMenu::viewCompletedTasks() {
	showOption(getName(4).substr(3));
    tasksHashtable->printValues(true);
//	list->printTable(true);
}

void TaskMenu::addNewTask() {
	showOption(getName(0).substr(3));
    Task newTask;
    string term, name;
    cout << "Enter task details: " << endl;
    cout << "Term: ";
    cin >> term;
    newTask.setTerm(term);
    
    cout << "Name: ";
    cin >> name;
    newTask.setName(name);
    
    tasksHashtable->add(newTask.getName(), newTask);
    cout << "New task added successfully!" << endl;
    
//	list->addNew();
	cout << endl;
}

void TaskMenu::editTask() {
	showOption(getName(1).substr(3));
    string taskName;
    cout << "Enter the name of the task to edit: " << endl;
    cin >> taskName;
    
    //search for the task in the hashtable
    Task* taskPtr = tasksHashtable->search(taskName);
    if (taskPtr != nullptr){
        Task editedTask = *taskPtr; // make a copy of the task to edit
        
        //prompt user for new task details
        
        cout << "Enter new details for the task: " << endl;
        cout << "Term: ";
        string term;
        editedTask.setTerm(term);
        
        cout << "Name: ";
        string name;
        cin >> name;
        editedTask.setName(name);
        
        //start date, end date, status
        
        //update the task in the hashtable
        tasksHashtable->editValue(taskName, editedTask);
        cout << "Task edited successfully!" << endl;
    }else{
        cout << "Task not found." << endl;
    }

//	list->editTask();
	cout << endl;
}

void TaskMenu::deleteTask() {
	showOption(getName(2).substr(3));
    cout << "Enter task to delete: ";
    string taskName;
    cin >> taskName;
    
    if (tasksHashtable->search(taskName)){
        tasksHashtable->deleteKey(taskName);
    }else{
        cout << "Task not found." << endl;
    }
    
    
    
//	list->deleteTask();
	cout << endl;
}

void TaskMenu::activate() {
	char command = COMMAND::ADD;
	while (command != EXIT) {
		command = doMenuOption();
		switch (command) {		
		case ADD:
			addNewTask();
			break;
		case EDIT:
			editTask();
			break;
		case DELETE:
			deleteTask();
			break;
		case PENDING:
			viewPendingTasks();
			break;
		case DONE:
			viewCompletedTasks();
			break;
		case EXIT:
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
