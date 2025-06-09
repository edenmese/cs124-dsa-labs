//
//  CourseCatalog.cpp
//  StudenPortfolio_Lab2
//
//  Created by Eden Meseret on 3/26/24.
//

#include "CourseCatalog.hpp"

#include <iostream>
#include <string>
#include "Course.hpp"
#include "AbstractList.hpp" 
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// Constructor
CourseCatalog::CourseCatalog() : UnorderedArrayList<course>() {
    // Read courses from file and add them to the list
    readCoursesFromFile("/Users/edenmese/Desktop/Ohlone/2024/CS-124/StudenPortfolio_Lab2/StudenPortfolio_Lab2/cs_transfer_courses.dat");
}

// Method to sort courses by course number using QuickSort
void CourseCatalog::sortByCourseNumber() {
    quickSort(0, getSize() - 1);
}

// Method to search for a course by course number and display its details
int CourseCatalog::searchByCourseNumber(string courseNumber) {
    int index = binarySearchByCourseNumber(courseNumber);
    if (index != -1) {
        course foundCourse = get(index);
        cout << "\n Course found:" << endl;
        cout << "Department: " << foundCourse.getDepartment() << endl;
        cout << "Course Number: " << foundCourse.getCourse() << endl;
        cout << "Title: " << foundCourse.getTitle() << endl;
        cout << "Description: " << foundCourse.getDescription() << endl;
        cout << "Prerequisite: " << foundCourse.getPrerequisite() << endl;
        cout << "Units: " << foundCourse.getUnits() << endl;
        return index;
    }
    else {
        cout << "\n Course not found." << endl;
        return index;
    }
}

// Helper function to read courses from file
void CourseCatalog::readCoursesFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    string department, title, description, prerequisite, courseNum;
    int units;
    bool test;

    while (getline(file, line)) {
        test = false;
        // Extract department and course number from the first line
        istringstream lineStream(line);
        lineStream >> department >> courseNum;

        getline(file, title);

        // Read description (potentially multiple lines)
        stringstream descriptionStream;

        while (true) {
            getline(file, line);
            if (line[line.length() - 2] == '\\') {
                descriptionStream << line.substr(0, line.size() - 1) << ' ';
            }
            else {
                if (line[line.length() - 2] == '.') {
                    descriptionStream << line;
                }
                else {
                    prerequisite = line;
                    test = true;
                }
                break;
            }
        }
        description = descriptionStream.str();

        if (!test) {
            getline(file, prerequisite);
        }
        file >> units;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        // Create course object
        course newCourse(department, courseNum, title, description, prerequisite, units);
        // Add course object to the list
        add(newCourse);
    }

    file.close();
}

// Helper function for QuickSort algorithm
void CourseCatalog::quickSort(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quickSort(low, pivotIndex - 1);
        quickSort(pivotIndex + 1, high);
    }
}

// Helper function to partition the array
int CourseCatalog::partition(int low, int high) {
    course pivot = get(high);
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (get(j).getCourse() <= pivot.getCourse()) {
            ++i;
            swap(i, j);
        }
    }
    swap(i + 1, high);
    return (i + 1);
}

// Helper function to swap two elements in the array
void CourseCatalog::swap(int i, int j) {
    course temp = get(i);
    set(i, get(j));
    set(j, temp);
}

// Helper function for binary search based on course number
int CourseCatalog::binarySearchByCourseNumber(const string& courseNum) {
    int low = 0;
    int high = getSize() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int result = compareStrings(get(mid).getCourse(), courseNum);

        if (result > 0) {
            high = mid - 1;
        }
        else if (result < 0) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

// Helper to compare two strings
int CourseCatalog::compareStrings(const string& str1, const string& str2) {
    size_t i = 0, j = 0;
    while (i < str1.size() && j < str2.size()) {
        if (isdigit(str1[i]) && isdigit(str2[j])) {
            int num1 = 0, num2 = 0;
            while (i < str1.size() && isdigit(str1[i])) {
                num1 = num1 * 10 + (str1[i] - '0');
                ++i;
            }
            while (j < str2.size() && isdigit(str2[j])) {
                num2 = num2 * 10 + (str2[j] - '0');
                ++j;
            }
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
        }
        else {
            if (str1[i] < str2[j]) return -1;
            else if (str1[i] > str2[j]) return 1;
            ++i;
            ++j;
        }
    }
    if (i < str1.size()) return 1;
    else if (j < str2.size()) return -1;
    return 0;
}
