//
//  Course.cpp
//  StudenPortfolio_Lab2
//
//  Created by Eden Meseret on 3/26/24.
//

#include "Course.hpp"
// Default constructor
course::course() : Department(""), Course(""), Title(""), Description(""), Prerequisite(""), Units(0) {}

// Parameterized constructor
course::course(string dept, string courseNum, string title, string desc, string prereq, int units)
    : Department(dept), Course(courseNum), Title(title), Description(desc), Prerequisite(prereq), Units(units) {}

// Getters and Setters
string course::getDepartment() const {
    return Department;
}

void course::setDepartment(string dept) {
    Department = dept;
}

string course::getCourse() const {
    return Course;
}

void course::setCourse(string courseNum) {
    Course = courseNum;
}

string course::getTitle() const {
    return Title;
}

void course::setTitle(string title) {
    Title = title;
}

string course::getDescription() const {
    return Description;
}

void course::setDescription(string desc) {
    Description = desc;
}

string course::getPrerequisite() const {
    return Prerequisite;
}

void course::setPrerequisite(string prereq) {
    Prerequisite = prereq;
}

int course::getUnits() const {
    return Units;
}

void course::setUnits(int units) {
    Units = units;
}

// Overloading stream insertion operator for printing
ostream& operator<<(ostream& os, const course& crs) {
    os << "Department: " << crs.Department << ", Course: " << crs.Course << ", Title: " << crs.Title
       << ", Description: " << crs.Description << ", Prerequisite: " << crs.Prerequisite << ", Units: " << crs.Units;
    return os;
}
