//
//  StudentPortfolio.cpp
//  StudenPortfolio_Lab2
//
//  Created by Eden Meseret on 3/26/24.
//

#include "StudentPortfolio.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "CourseCatalog.hpp"

StudentPortfolio::StudentPortfolio() : pTransferCourse(new CourseCatalog()) {}

StudentPortfolio::~StudentPortfolio() {
    delete pTransferCourse;
}

void StudentPortfolio::viewList(int x) {
    pTransferCourse->sortByCourseNumber();

    if (x == 1) {
        // ascending order
        for (int i = 0; i < pTransferCourse->getSize(); ++i) {
            cout << "Course " << i + 1 << ": ";
            cout << "Department: " << pTransferCourse->get(i).getDepartment() << ", ";
            cout << "Course Number: " << pTransferCourse->get(i).getCourse() << ", ";
            cout << "Title: " << pTransferCourse->get(i).getTitle() << endl;
        }
    }
    else if (x == 2) {
        // descending order
        for (int i = pTransferCourse->getSize() - 1; i >= 0; --i) {
            cout << "Course " << i + 1 << ": ";
            cout << "Department: " << pTransferCourse->get(i).getDepartment() << ", ";
            cout << "Course Number: " << pTransferCourse->get(i).getCourse() << ", ";
            cout << "Title: " << pTransferCourse->get(i).getTitle() << endl;
        }
    }
    else {
        cout << "Bad Choice!!" << endl;
    }
}

void StudentPortfolio::viewCourse(const string& courseNumber) {
    pTransferCourse->sortByCourseNumber();
    pTransferCourse->searchByCourseNumber(courseNumber);
}

void StudentPortfolio::addCourse() {
    ofstream outfile("/Users/edenmese/Desktop/Ohlone/2024/CS-124/StudenPortfolio_Lab2/StudenPortfolio_Lab2/cs_transfer_courses.dat", ios::app);

    if (!outfile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    string department, course;
    cout << "Enter department and course number (e.g., CS 101): ";
    cin >> department >> course;
    outfile << department << " " << course << endl;

    string title;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    outfile << title << endl;

    string description;
    cout << "Enter description (press Enter twice to finish):\n";
    while (true) {
        getline(cin, description);
        if (description.empty()) break;
        outfile << description << endl;
    }

    string prerequisite;
    cout << "Enter prerequisite: ";
    getline(cin, prerequisite);
    outfile << prerequisite << endl;

    int units;
    cout << "Enter units: ";
    cin >> units;
    outfile << units << endl;

    outfile.close();

    cout << "Course added successfully." << endl;
}

void StudentPortfolio::editCourse(const string& courseNumber) {
    pTransferCourse->sortByCourseNumber();
    int index = pTransferCourse->searchByCourseNumber(courseNumber);
    if (index != -1) {
        string department = "", courseNum = "", title = "", description = "", prerequisite = "";
        int units = 0;

        cout << "Enter new department or write `skip` to let as it's: ";
        cin >> department;
        if (department != "skip") pTransferCourse->get(index).setDepartment(department);

        cout << "Enter new course number or write `skip` to let as it's: ";
        cin >> courseNum;
        if (courseNum != "skip") pTransferCourse->get(index).setCourse(courseNum);

        cout << "Enter new title or write `skip` to let as it's: ";
        cin >> title;
        if (title != "skip") pTransferCourse->get(index).setTitle(title);

        cout << "Enter new description or write `skip` to let as it's: ";
        cin >> description;
        if (description != "skip") pTransferCourse->get(index).setDescription(description);

        cout << "Enter new prerequisite or write `skip` to let as it's: ";
        cin >> prerequisite;
        if (prerequisite != "skip") pTransferCourse->get(index).setPrerequisite(prerequisite);

        cout << "Enter new units or enter `-1` to let as it's: ";
        cin >> units;
        if (units != -1) pTransferCourse->get(index).setUnits(units);

        saveCoursesToFile();
    }
    else {
        cout << "Course not found." << endl;
    }
}

void StudentPortfolio::removeCourse(const string& courseNumber) {
    pTransferCourse->sortByCourseNumber();
    int index = pTransferCourse->searchByCourseNumber(courseNumber);
    if (index != -1) {
        pTransferCourse->remove(index);
        saveCoursesToFile();
        cout << "Course removed successfully." << endl;
    }
    else {
        cout << "Course not found." << endl;
    }
}

void StudentPortfolio::quit() {
    cout << "Good Bye!!" << endl;
    exit(0);
}

void StudentPortfolio::saveCoursesToFile() {
    ofstream file("/Users/edenmese/Desktop/Ohlone/2024/CS-124/StudenPortfolio_Lab2/StudenPortfolio_Lab2/cs_transfer_courses.dat");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file cs_transfer_courses.dat" << endl;
        return;
    }

    for (int i = 0; i < pTransferCourse->getSize(); ++i) {
        file << pTransferCourse->get(i).getDepartment() << " "
             << pTransferCourse->get(i).getCourse() << endl;
        file << pTransferCourse->get(i).getTitle() << endl;
        file << pTransferCourse->get(i).getDescription() << endl;
        file << pTransferCourse->get(i).getPrerequisite() << endl;
        file << pTransferCourse->get(i).getUnits() << endl;
    }

    file.close();
}
