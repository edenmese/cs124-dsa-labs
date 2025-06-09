#pragma once
#include <string>
#include "task.h"
#include "linkedStack.h"
#include "LinkedSet.hpp"


using namespace std;

class TaskList : public LinkedSet<Task> {
public:
    TaskList();
    ~TaskList();

    void addNew();
    void editTask();
    void deleteTask();
    void printTable(bool complete = true);

protected:
    void printRaw(bool complete = true);
    void printRow(const Task task);

private:
    void printHeader();
};

