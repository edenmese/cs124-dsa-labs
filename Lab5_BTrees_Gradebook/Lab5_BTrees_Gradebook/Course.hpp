//
//  Course.hpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#ifndef Course_hpp
#define Course_hpp
#include "Faculty.hpp"
#include "CSVHandler.hpp"
#include <unordered_map>
#include <string>

using namespace std;
class Course{
public:
    /*******************************************************

       * Function Name: Course

       * Purpose: Default constructor for Course class

       * Parameter: None

       * Return: None

       *******************************************************/
        Course();

      /*******************************************************

       * Function Name: ~Course

       * Purpose: Destructor for Course class

       * Parameter: None

       * Return: None

       *******************************************************/
        ~Course();

      /*******************************************************

       * Function Name: Course

       * Purpose: Parameterized constructor for Course class

       * Parameter:
          - string& term: Term of the course
          - string& section: Section of the course
          - string& courseName: Name of the course
          - int& units: Units of the course
          - string& facultyID: ID of the faculty teaching the course
          - Faculty& courseFaculty: Faculty object representing the course faculty

       * Return: None

       *******************************************************/
        Course(string& term, string& section, string& courseName, int& units, string& facultyID, Faculty& courseFaculty);
    
    
    /*******************************************************

         * Function Name: setTerm

         * Purpose: Set the term of the course

         * Parameter:
            - string term: Term of the course

         * Return: None

         *******************************************************/
        void setTerm(string term);

        /*******************************************************

         * Function Name: setCourseSection

         * Purpose: Set the section of the course

         * Parameter:
            - string courseSection: Section of the course

         * Return: None

         *******************************************************/
        void setCourseSection(string courseSection);

        /*******************************************************

         * Function Name: setCourseName

         * Purpose: Set the name of the course

         * Parameter:
            - string courseName: Name of the course

         * Return: None

         *******************************************************/
        void setCourseName(string courseName);

        /*******************************************************

         * Function Name: setUnits

         * Purpose: Set the units of the course

         * Parameter:
            - int units: Units of the course

         * Return: None

         *******************************************************/
        void setUnits(int units);

        /*******************************************************

         * Function Name: setCourseFaculty

         * Purpose: Set the faculty of the course

         * Parameter:
            - Faculty courseFaculty: Faculty object representing the course faculty

         * Return: None

         *******************************************************/
        void setCourseFaculty(Faculty courseFaculty);

        /*******************************************************

         * Function Name: setFacultyID

         * Purpose: Set the ID of the faculty teaching the course

         * Parameter:
            - string facultyID: ID of the faculty teaching the course

         * Return: None

         *******************************************************/
        void setFacultyID(string facultyID);

    

    /*******************************************************

         * Function Name: getTerm

         * Purpose: Get the term of the course

         * Parameter: None

         * Return: string - Term of the course

         *******************************************************/
        string getTerm() const;

        /*******************************************************

         * Function Name: getCourseSection

         * Purpose: Get the section of the course

         * Parameter: None

         * Return: string - Section of the course

         *******************************************************/
        string getCourseSection() const;

        /*******************************************************

         * Function Name: getCourseName

         * Purpose: Get the name of the course

         * Parameter: None

         * Return: string - Name of the course

         *******************************************************/
        string getCourseName() const;

        /*******************************************************

         * Function Name: getUnits

         * Purpose: Get the units of the course

         * Parameter: None

         * Return: int - Units of the course

         *******************************************************/
        int getUnits() const;

        /*******************************************************

         * Function Name: getFacultyID

         * Purpose: Get the ID of the faculty teaching the course

         * Parameter: None

         * Return: string - ID of the faculty teaching the course

         *******************************************************/
        string getFacultyID() const;

        /*******************************************************

         * Function Name: getCourseFaculty

         * Purpose: Get the faculty of the course

         * Parameter: None

         * Return: Faculty - Faculty object representing the course faculty

         *******************************************************/
        Faculty getCourseFaculty() const;
    
    /*******************************************************

        * Function Name: parseCourseCSV

        * Purpose: Parse courses from a CSV file and return a vector of Course objects

        * Parameter:
           - const string& filename: Filename of the CSV file to parse

        * Return: vector<Course> - Vector of Course objects parsed from the CSV file

        *******************************************************/
    static vector<Course>parseCourseCSV(const string& filename);
    

private:
    string term, courseSection, courseName, facultyID;
    int units;
    Faculty courseFaculty;
};
#endif /* Course_hpp */
