//
//  CourseCatalog.hpp
//  StudenPortfolio_Lab2
//
//  Created by Eden Meseret on 3/26/24.
//

#ifndef CourseCatalog_hpp
#define CourseCatalog_hpp

#include "AbstractList.hpp" // Include the AbstractList header file
#include "Course.hpp"    // Include the Course header file
#include "UnorderedArrayList.hpp"

using namespace std;
class CourseCatalog : public UnorderedArrayList<course> {
public:
    // Constructor
    CourseCatalog();

    // Method to sort courses by course number using QuickSort
    void sortByCourseNumber();

    // Method to search for a course by course number and display its details
    int searchByCourseNumber(string courseNumber);

private:
    // Helper function to read courses from file
    void readCoursesFromFile(const string& filename);

    // Helper function for QuickSort algorithm
    void quickSort(int low, int high);

    // Helper function to partition the array
    int partition(int low, int high);

    // Helper function to swap two elements in the array
    void swap(int i, int j);

    // Helper function for binary search based on course number
    int binarySearchByCourseNumber(const string& courseNum);

    // Helper to compare two strings
    int compareStrings(const string& str1, const string& str2);
};


#endif /* CourseCatalog_hpp */



