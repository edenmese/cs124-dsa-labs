//
//  GradeBookMenu.hpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#ifndef GradeBookMenu_hpp
#define GradeBookMenu_hpp

#include "Menu.hpp"

#include "GradeScale.hpp"

#include "Course.hpp"

#include <vector>

class GradeBookMenu : public Menu{
    
public:
    
    /*******************************************************

         * Function Name: GradeBookMenu

         * Purpose: Constructor for GradeBookMenu class, initializes gradeScale

         * Parameter: None

         * Return: None

         *******************************************************/
        GradeBookMenu() : gradeScale(){}

        /*******************************************************

         * Function Name: activate

         * Purpose: Activate GradeBookMenu to start the menu system

         * Parameter: None

         * Return: None

         *******************************************************/
        void activate();

        /*******************************************************

         * Function Name: loadData

         * Purpose: Load data from a file

         * Parameter: string fileName - the name of the file to load data from

         * Return: None

         *******************************************************/
        void loadData(string fileName);

        /*******************************************************

         * Function Name: displayGradeBookCategories

         * Purpose: Display the categories in the grade book

         * Parameter: None

         * Return: None

         *******************************************************/
        void displayGradeBookCategories();

        /*******************************************************

         * Function Name: viewGradeBookCategory

         * Purpose: View a specific grade book category

         * Parameter: None

         * Return: None

         *******************************************************/
        void viewGradeBookCategory();

        /*******************************************************

         * Function Name: viewIndividualAssignment

         * Purpose: View an individual assignment within a category

         * Parameter: const string& selectedCategory - the selected category to view

         * Return: None

         *******************************************************/
        void viewIndividualAssignment(const string& selectedCategory) const;

        /*******************************************************

         * Function Name: displayCoursesAndFaculty

         * Purpose: Display courses and faculty

         * Parameter: None

         * Return: None

         *******************************************************/
        void displayCoursesAndFaculty(); //course vector

        /*******************************************************

         * Function Name: addAssignment

         * Purpose: Add a new assignment and increment all ID's

         * Parameter: None

         * Return: None

         *******************************************************/
        void addAssignment(); // adds new assignment and increments all ID's

        /*******************************************************

         * Function Name: removeAssignment

         * Purpose: Remove an assignment and update assignment ID's

         * Parameter: None

         * Return: None

         *******************************************************/
        void removeAssignment(); // update assignment ID's when removing

        /*******************************************************

         * Function Name: editAssignment

         * Purpose: Edit an assignment

         * Parameter: None

         * Return: None

         *******************************************************/
        void editAssignment();

        /*******************************************************

         * Function Name: calculateGrade

         * Purpose: Calculate the grade

         * Parameter: None

         * Return: None

         *******************************************************/
        void calculateGrade();

        /*******************************************************

         * Function Name: doExit

         * Purpose: Perform exit actions

         * Parameter: None

         * Return: None

         *******************************************************/
        void doExit();
    
private:
    GradeScale gradeScale;
    
    
};

#endif /* GradeBookMenu_hpp */
