//
//  GradeScale.hpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#ifndef GradeScale_hpp
#define GradeScale_hpp
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <map>


#include <iterator>
#include "CSVHandler.hpp"
#include "Assignment.hpp"
#include "AssignmentBST.hpp"
#include "Course.hpp"




using namespace std;
class GradeScale {
public:
    
   
    GradeScale();
    /*******************************************************

     * Function Name: GradeScale (destructor)

     * Purpose: Destructs a GradeScale object.

     * Parameter: None

     * Return: void

     *******************************************************/
    ~GradeScale();
    
    /*******************************************************

     * Function Name: GradeScale (constructor)

     * Purpose: Constructs a GradeScale object.

     * Parameter:
     * - groupID: An integer representing the ID of the assignment group.
     * - courseSection: A constant reference to a Course object representing the course section.
     * - categoryDescription: A constant reference to a string representing the category description.
     * - weight: An integer representing the weight of the assignment group.

     * Return: void

     *******************************************************/
    GradeScale(int& groupID, const Course& courseSection, const string& categoryDescription, int weight);

    // Setters
    /*******************************************************

     * Function Name: setGroupID

     * Purpose: Sets the ID of the assignment group.

     * Parameter:
     * - groupID: An integer representing the ID of the assignment group.

     * Return: void

     *******************************************************/
    void setGroupID(int groupID);

    /*******************************************************

     * Function Name: setCourseSection

     * Purpose: Sets the course section associated with the GradeScale.

     * Parameter:
     * - courseSection: A constant reference to a Course object representing the course section.

     * Return: void

     *******************************************************/
    void setCourseSection(const Course& courseSection);

    /*******************************************************

     * Function Name: setCategoryDescription

     * Purpose: Sets the category description of the assignment group.

     * Parameter:
     * - categoryDescription: A constant reference to a string representing the category description.

     * Return: void

     *******************************************************/
    void setCategoryDescription(const string& categoryDescription);

    /*******************************************************

     * Function Name: setWeight

     * Purpose: Sets the weight of the assignment group.

     * Parameter:
     * - weight: An integer representing the weight of the assignment group.

     * Return: void

     *******************************************************/
    void setWeight(int weight);


    /*******************************************************

     * Function Name: getGroupID

     * Purpose: Retrieves the ID of the assignment group.

     * Parameter: None

     * Return: int - The ID of the assignment group.

     *******************************************************/
    int getGroupID() const;

    /*******************************************************

     * Function Name: getCourseSection

     * Purpose: Retrieves the course section associated with the GradeScale.

     * Parameter: None

     * Return: const Course& - A constant reference to a Course object representing the course section.

     *******************************************************/
    const Course& getCourseSection() const;

    /*******************************************************

     * Function Name: getCategoryDescription

     * Purpose: Retrieves the category description of the assignment group.

     * Parameter: None

     * Return: const string& - A constant reference to a string representing the category description.

     *******************************************************/
    const string& getCategoryDescription() const;

    /*******************************************************

     * Function Name: getWeight

     * Purpose: Retrieves the weight of the assignment group.

     * Parameter: None

     * Return: int - The weight of the assignment group.

     *******************************************************/
    int getWeight() const;

    /*******************************************************

     * Function Name: insertAssignment

     * Purpose: Inserts an assignment into the GradeScale.

     * Parameter:
     * - categoryDescription: A string representing the category description of the assignment.
     * - groupID: An integer representing the ID of the assignment group.
     * - assignment: A constant reference to an Assignment object to be inserted.

     * Return: void

     *******************************************************/
    void insertAssignment(std::string categoryDescription, int groupID, const Assignment& assignment);

    /*******************************************************

     * Function Name: searchAssignment

     * Purpose: Searches for an assignment in the GradeScale.

     * Parameter:
     * - assignmentID: An integer representing the ID of the assignment to search for.
     * - categoryDescription: A constant reference to a string representing the category description of the assignment.

     * Return: Assignment* - A pointer to the found Assignment object, or nullptr if not found.

     *******************************************************/
    Assignment* searchAssignment(int assignmentID, const string& categoryDescription) const;

   
    /*******************************************************

     * Function Name: removeAssignment

     * Purpose: Removes an assignment with the specified ID from the given category.

     * Parameter:
     * - assignmentID: An integer representing the ID of the assignment to remove.
     * - categoryDescription: A constant reference to a string representing the category description of the assignment.

     * Return: bool - True if the assignment was successfully removed, false otherwise.

     *******************************************************/
    bool removeAssignment(int assignmentID, const string& categoryDescription);

    /*******************************************************

     * Function Name: printAssignment

     * Purpose: Prints details of the assignment with the specified ID from the given category.

     * Parameter:
     * - assignmentID: An integer representing the ID of the assignment to print.
     * - categoryDescription: A constant reference to a string representing the category description of the assignment.

     * Return: void

     *******************************************************/
    void printAssignment(int assignmentID, const string& categoryDescription) const;

    /*******************************************************

     * Function Name: printAssignment

     * Purpose: Prints all assignments in the given category.

     * Parameter:
     * - categoryDescription: A constant reference to a string representing the category description of the assignments.

     * Return: void

     *******************************************************/
    void printAssignment(const string& categoryDescription);

    /*******************************************************

     * Function Name: printAllAssignments

     * Purpose: Prints all assignments categorized by assignment category.

     * Parameter: None

     * Return: void

     *******************************************************/
    void printAllAssignments();

    /*******************************************************

     * Function Name: loadData

     * Purpose: Loads assignment data from the given file into the AssignmentBST.

     * Parameter:
     * - fileName: A constant reference to a string representing the name of the file to load data from.
     * - assignmentBST: A reference to an AssignmentBST object to load data into.

     * Return: void

     *******************************************************/
    void loadData(const string& fileName, AssignmentBST& assignmentBST);

    /*******************************************************

     * Function Name: displayCategories

     * Purpose: Displays all assignment categories.

     * Parameter: None

     * Return: void

     *******************************************************/
    void displayCategories();

    /*******************************************************

     * Function Name: viewCategory

     * Purpose: Displays assignments under the specified category.

     * Parameter:
     * - category: A constant reference to a string representing the category to view.

     * Return: void

     *******************************************************/
    void viewCategory(const string& category) const;

    /*******************************************************

     * Function Name: categoryDescriptionToGroupID

     * Purpose: Retrieves the group ID corresponding to the given category description.

     * Parameter:
     * - categoryDescription: A constant reference to a string representing the category description.

     * Return: int - The group ID corresponding to the category description.

     *******************************************************/
    int categoryDescriptionToGroupID(const string& categoryDescription) const;
    
    /*******************************************************

     * Function Name: setGetCurrentMaxAssignmentId

     * Purpose: Sets and retrieves the current maximum assignment ID for the given category.

     * Parameter:
     * - categoryDescription: A constant reference to a string representing the category description.

     * Return: int - The current maximum assignment ID for the given category.

     *******************************************************/
    int setGetCurrentMaxAssignmentId(const string& categoryDescription);


private:
    int groupID;
    Course courseSection;
    string categoryDescription;
    int weight;
    
    /*******************************************************

     * Function Name: parseGradeScaleCSV

     * Purpose: Parses the grade scale data from the specified CSV file and populates the AssignmentBST.

     * Parameter:
     * - filename: A constant reference to a string representing the name of the CSV file to parse.
     * - assignmentBST: A reference to an AssignmentBST object to populate with the parsed data.

     * Return: void

     *******************************************************/
    void parseGradeScaleCSV(const string& filename, AssignmentBST& assignmentBST);
    
    unordered_map<string, AssignmentBST> assignmentCategories; //key is categoryDescription
    unordered_map<string, int> currentMaxAssignmentIds;
        
public:
    /*******************************************************

     * Function Name: saveAssignmentsToCSV

     * Purpose: Saves all assignments to a CSV file with the specified filename.

     * Parameter:
     * - filename: A constant reference to a string representing the name of the CSV file to save assignments to.

     * Return: void

     *******************************************************/
    void saveAssignmentsToCSV(const string& filename);

    /*******************************************************

     * Function Name: getAllAssigments

     * Purpose: Retrieves all assignments stored in the GradeScale.

     * Parameter: None

     * Return: vector<Assignment> - A vector containing all assignments stored in the GradeScale.

     *******************************************************/
    vector<Assignment> getAllAssigments() const;
};

#endif /* GradeScale_hpp */
