//
//  StudentPortfolio.hpp
//  StudenPortfolio_Lab2
//
//  Created by Eden Meseret on 3/26/24.
//

#ifndef StudentPortfolio_hpp
#define StudentPortfolio_hpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "CourseCatalog.hpp"

using namespace std;
class StudentPortfolio {
private:
    CourseCatalog* pTransferCourse;

public:
    // Constructor
    StudentPortfolio();

    // Destructor
    ~StudentPortfolio();

    // Method to view list of courses
    void viewList(int x);

    // Method to view details of a specific course
    void viewCourse(const string& courseNumber);

    // Method to add a new course
    void addCourse();

    // Method to edit a course
    void editCourse(const string& courseNumber);

    // Method to remove a course
    void removeCourse(const string& courseNumber);

    // Method to save the courses and exit
    void quit();

private:
    // Helper method to save the updated course list to the file
    void saveCoursesToFile();
};
#endif /* StudentPortfolio_hpp */
