//
//  GradeScale.cpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#include "GradeScale.hpp"

GradeScale::GradeScale(){}

/*******************************************************

 * Function Name: GradeScale (destructor)

 * Purpose: Destructs a GradeScale object.

 * Parameter: None

 * Return: void

 *******************************************************/
GradeScale::~GradeScale(){}

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
GradeScale::GradeScale(int& groupID, const Course& courseSection, const string& categoryDescription, int weight){
        setGroupID(groupID);
        setCourseSection(courseSection);
        setCategoryDescription(categoryDescription);
        setWeight(weight);
}


/*******************************************************

 * Function Name: setGroupID

 * Purpose: Sets the ID of the assignment group.

 * Parameter:
 * - groupID: An integer representing the ID of the assignment group.

 * Return: void

 *******************************************************/
void GradeScale::setGroupID(int groupID){
    this->groupID = groupID;
}


/*******************************************************

 * Function Name: setCourseSection

 * Purpose: Sets the course section associated with the GradeScale.

 * Parameter:
 * - courseSection: A constant reference to a Course object representing the course section.

 * Return: void

 *******************************************************/
void GradeScale::setCourseSection(const Course& courseSection){
    this->courseSection = courseSection;
}


/*******************************************************

 * Function Name: setCategoryDescription

 * Purpose: Sets the category description of the assignment group.

 * Parameter:
 * - categoryDescription: A constant reference to a string representing the category description.

 * Return: void

 *******************************************************/
void GradeScale::setCategoryDescription(const string& categoryDescription){
    this->categoryDescription = categoryDescription;
}


/*******************************************************

 * Function Name: setWeight

 * Purpose: Sets the weight of the assignment group.

 * Parameter:
 * - weight: An integer representing the weight of the assignment group.

 * Return: void

 *******************************************************/
void GradeScale::setWeight(int weight){
    this->weight = weight;
}


/*******************************************************

 * Function Name: getGroupID

 * Purpose: Retrieves the ID of the assignment group.

 * Parameter: None

 * Return: int - The ID of the assignment group.

 *******************************************************/
int GradeScale::getGroupID() const {
    return groupID;
}


/*******************************************************

 * Function Name: getCourseSection

 * Purpose: Retrieves the course section associated with the GradeScale.

 * Parameter: None

 * Return: const Course& - A constant reference to a Course object representing the course section.

 *******************************************************/
const Course& GradeScale::getCourseSection() const {
    return courseSection;
}


/*******************************************************

 * Function Name: getCategoryDescription

 * Purpose: Retrieves the category description of the assignment group.

 * Parameter: None

 * Return: const string& - A constant reference to a string representing the category description.

 *******************************************************/
const string& GradeScale::getCategoryDescription() const {
    return categoryDescription;
}



/*******************************************************

 * Function Name: getWeight

 * Purpose: Retrieves the weight of the assignment group.

 * Parameter: None

 * Return: int - The weight of the assignment group.

 *******************************************************/
int GradeScale::getWeight() const {
    return weight;
}

/*******************************************************

 * Function Name: insertAssignment

 * Purpose: Inserts an assignment into the GradeScale.

 * Parameter:
 * - categoryDescription: A string representing the category description of the assignment.
 * - groupID: An integer representing the ID of the assignment group.
 * - assignment: A constant reference to an Assignment object to be inserted.

 * Return: void

 *******************************************************/
void GradeScale::insertAssignment(std::string categoryDescription, int groupID, const Assignment& assignment) {
    assignmentCategories[categoryDescription].insert(assignment);
    
    //should increase all ids (except categoryDescription)
    for (auto i = assignmentCategories.begin(); i != assignmentCategories.end(); i++){
        if (i->first != categoryDescription) {
            i->second.increaseIDs();
            setGetCurrentMaxAssignmentId(i->first);
        }
    }
}


/*******************************************************

 * Function Name: searchAssignment

 * Purpose: Searches for an assignment in the GradeScale.

 * Parameter:
 * - assignmentID: An integer representing the ID of the assignment to search for.
 * - categoryDescription: A constant reference to a string representing the category description of the assignment.

 * Return: Assignment* - A pointer to the found Assignment object, or nullptr if not found.

 *******************************************************/
Assignment* GradeScale::searchAssignment(int assignmentID, const string& categoryDescription)const {
    // Find the AssignmentBST corresponding to the given category
    auto it = assignmentCategories.find(categoryDescription);
    if (it != assignmentCategories.end()) {
        // If the AssignmentBST is found, search for the assignment by ID within it
        return it->second.searchAssignmentByID(assignmentID);
    }
    return nullptr; // Category not found
}


/*******************************************************

 * Function Name: removeAssignment

 * Purpose: Removes an assignment with the specified ID from the given category.

 * Parameter:
 * - assignmentID: An integer representing the ID of the assignment to remove.
 * - categoryDescription: A constant reference to a string representing the category description of the assignment.

 * Return: bool - True if the assignment was successfully removed, false otherwise.

 *******************************************************/

bool GradeScale::removeAssignment(int assignmentID, const string& categoryDescription) {
    // Find the AssignmentBST corresponding to the given category
    auto it = assignmentCategories.find(categoryDescription);
    if (it != assignmentCategories.end()) {
        // If the AssignmentBST is found, attempt to remove the assignment by ID
        bool removed = assignmentCategories[categoryDescription].remove(assignmentID);
        if (removed) {
            // If the assignment is successfully removed, update other relevant data
            // For example, if you're keeping track of maximum assignment IDs, update them here
            // If there are other data structures or variables related to assignments, update them as needed
            
            //reduce the id
            //should reduce all ids
            for (auto i = assignmentCategories.begin(); i != assignmentCategories.end(); i++){
                assignmentCategories[i->first].reduceIDs(assignmentID);//reduce all ids that are > assignmentID
                
                //manage the maximum ?
                currentMaxAssignmentIds[i->first] -= 1;
            }
            return true;
        }
    }
    return false; // Assignment not found or unable to remove
}

/*******************************************************

 * Function Name: printAssignment

 * Purpose: Prints all assignments in the given category.

 * Parameter:
 * - categoryDescription: A constant reference to a string representing the category description of the assignments.

 * Return: void

 *******************************************************/

void GradeScale::printAssignment(int assignmentID, const string& categoryDescription) const {
   // Search for the assignment in the AssignmentBST
   const Assignment* assignment = searchAssignment(assignmentID, categoryDescription);
//Id,GroupId,Description,Start Date,End Date,Possible Points,Points
   // Check if the assignment was found
   if (assignment != nullptr) {
       // Print details of the assignment
       cout << "Assignment ID: " << assignment->getId() << endl;
       cout << "Group ID: " << assignment->getGroupNum() << endl;
       cout << "Description: " << assignment->getDescription() << endl;
       cout << "Start Date: " << assignment->getStartDate().toString() << endl;
       cout << "End Date: " << assignment->getEndDate().toString() << endl;
       cout << "Possible Points: " << assignment->getPossiblePoints()<< endl;
       cout << "Points Earned: " << assignment->getPointsEarned() << endl;

       // Add more details if needed
   } else {
       cout << "Assignment not found." << endl;
   }
}


/*******************************************************

 * Function Name: printAssignment

 * Purpose: Prints details of the assignment with the specified ID from the given category.

 * Parameter:
 * - assignmentID: An integer representing the ID of the assignment to print.
 * - categoryDescription: A constant reference to a string representing the category description of the assignment.

 * Return: void

 *******************************************************/
void GradeScale::printAssignment(const string& categoryDescription) {
    assignmentCategories[categoryDescription].printInorder();
}

/*******************************************************

 * Function Name: printAllAssignments

 * Purpose: Prints all assignments categorized by assignment category.

 * Parameter: None

 * Return: void

 *******************************************************/
void GradeScale::printAllAssignments() {

    for (auto i = assignmentCategories.begin(); i != assignmentCategories.end(); i++){
        
        cout << i->first << endl;
        
        AssignmentBST bst = i->second;
        vector<Assignment> allAssignments;
        bst.getAllAssignments(allAssignments);
        
        for (auto assign: allAssignments){
            cout << assign.getId() << "\t" << assign.getDescription() << endl;
        }
        
    }
}

/*******************************************************

 * Function Name: loadData

 * Purpose: Loads assignment data from the given file into the AssignmentBST.

 * Parameter:
 * - fileName: A constant reference to a string representing the name of the file to load data from.
 * - assignmentBST: A reference to an AssignmentBST object to load data into.

 * Return: void

 *******************************************************/
void GradeScale::loadData(const string& fileName, AssignmentBST& assignmentBST){
    parseGradeScaleCSV(fileName, assignmentBST);

}

/*******************************************************

 * Function Name: displayCategories

 * Purpose: Displays all assignment categories.

 * Parameter: None

 * Return: void

 *******************************************************/
void GradeScale::displayCategories() {
    vector<string> categoryOrder = {"Assignments", "Quizzes", "Labs", "Midterm", "Final Exam"};
    int index = 1;
    for (const string& category : categoryOrder) {
        auto it = assignmentCategories.find(category);
        if (it != assignmentCategories.end()) {
            cout << index++ << ") " << category << endl;
        }
    }
}
/*******************************************************

 * Function Name: viewCategory

 * Purpose: Displays assignments under the specified category.

 * Parameter:
 * - category: A constant reference to a string representing the category to view.

 * Return: void

 *******************************************************/
void GradeScale::viewCategory(const string& category) const{
    auto it = assignmentCategories.find(category);
            if (it != assignmentCategories.end()) {
                cout << "Assignments under category '" << category << "':" << endl;
                it->second.printInorder(); // Assuming there's a function to print assignments in AssignmentBST
            } else {
                cout << "Category '" << category << "' not found." << endl;
            }
}
/*******************************************************

 * Function Name: categoryDescriptionToGroupID

 * Purpose: Retrieves the group ID corresponding to the given category description.

 * Parameter:
 * - categoryDescription: A constant reference to a string representing the category description.

 * Return: int - The group ID corresponding to the category description.

 *******************************************************/

int GradeScale::categoryDescriptionToGroupID(const string &categoryDescription)const{
    if (categoryDescription == "Assignments") {
        return 1;
    } else if (categoryDescription == "Quizzes") {
        return 2;
    } else if (categoryDescription == "Labs") {
        return 3;
    } else if (categoryDescription == "Midterm") {
        return 4;
    } else if (categoryDescription == "Final Exam") {
        return 5;
    } else {
        return -1; // Return -1 for invalid category descriptions
    }
}

/*******************************************************

 * Function Name: setGetCurrentMaxAssignmentId

 * Purpose: Sets and retrieves the current maximum assignment ID for the given category.

 * Parameter:
 * - categoryDescription: A constant reference to a string representing the category description.

 * Return: int - The current maximum assignment ID for the given category.

 *******************************************************/

int GradeScale::setGetCurrentMaxAssignmentId(const string& categoryDescription)  {
    currentMaxAssignmentIds[categoryDescription] += 1;
    
    return currentMaxAssignmentIds[categoryDescription];
}

/*******************************************************

 * Function Name: parseGradeScaleCSV

 * Purpose: Parses the grade scale data from the specified CSV file and populates the AssignmentBST.

 * Parameter:
 * - filename: A constant reference to a string representing the name of the CSV file to parse.
 * - assignmentBST: A reference to an AssignmentBST object to populate with the parsed data.

 * Return: void

 *******************************************************/
void GradeScale::parseGradeScaleCSV(const string& filename, AssignmentBST& assignmentBST) {
    

    // Parse course data
    vector<Course> coursesData = Course::parseCourseCSV("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab5_BTrees_Gradebook/Lab5_data/course-data.csv");
    // Parse assignments data
    
    if (coursesData.empty()) {
        cerr << "Error: No Course data is available." << endl;
        return;
    }
    
    string assignmentsFilename = "/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab5_BTrees_Gradebook/Lab5_BTrees_Gradebook/assignment-data.csv"; // Adjust path to assignments.csv
    vector<Assignment> assignments = Assignment::parseAssignmentsCSV(assignmentsFilename);

    // Open grade scale CSV file
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename;
        return;
    }

    string line;
    getline(file, line); // Read and discard header line

    // Parse each line in the grade scale CSV file
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        
        // Parse group ID
        getline(ss, token, ',');
        int groupID = stoi(token);  // 1
        setGroupID(groupID);
        
        
        getline(ss, token, ','); // CS-124-01
        // Assign section from the top of courseData
        if (!coursesData.empty()) {
            Course course = coursesData.back();
            course.setCourseSection(token);
            setCourseSection(course);
            coursesData.pop_back();
        }
        
        // Parse category description and weight
        getline(ss, token, ',');
        string categoryDescription = token;
        setCategoryDescription(token);// Assignments
        
        
        getline(ss, token, ','); // Skip weight for now
        int weight = stoi(token);
        setWeight(weight);
        
        // Filter assignments for this groupID
        vector<Assignment> filteredAssignments;
        for (const auto& assignment : assignments) {
            if (assignment.getGroupNum() == groupID) {
                filteredAssignments.push_back(assignment);
            }
        }
        
        // Insert corresponding assignments into AssignmentBST and assignmentCategories map
        for (const auto& assignment : filteredAssignments) {
            assignmentBST.insert(assignment);
            assignmentCategories[categoryDescription].insert(assignment);
            
            if (currentMaxAssignmentIds[categoryDescription] < assignment.getId()){
                currentMaxAssignmentIds[categoryDescription] = assignment.getId();
            }
            
            assignmentCategories[categoryDescription].insert(assignment);
        }
    }
}

/*******************************************************

 * Function Name: saveAssignmentsToCSV

 * Purpose: Saves all assignments to a CSV file with the specified filename.

 * Parameter:
 * - filename: A constant reference to a string representing the name of the CSV file to save assignments to.

 * Return: void

 *******************************************************/
void GradeScale::saveAssignmentsToCSV(const string& filename) {
    // Open the file for writing
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << " for writing." << endl;
        return;
    }

    // Write the header line
    file << "Id,GroupId,Description,Start Date,End Date,Possible Points,Points Earned" << endl;

    // Iterate over the assignmentCategories map and write each assignment to the file
    for (auto& categoryEntry : assignmentCategories) {
        //const string& categoryDescription = categoryEntry.first;
        //const AssignmentBST& bst = categoryEntry.second;
        
        categoryEntry.second.save(file);
        
        //for (const auto& assignment : bst.g) {
            // Write each assignment to the file
            //file << assignment.toCSVFormat() << endl;
        //}
    }
    // Close the file
    file.close();
    cout << "Assignments saved to " << filename << " successfully." << endl;
}



/*******************************************************

 * Function Name: getAllAssigments

 * Purpose: Retrieves all assignments stored in the GradeScale.

 * Parameter: None

 * Return: vector<Assignment> - A vector containing all assignments stored in the GradeScale.

 *******************************************************/
vector<Assignment> GradeScale::getAllAssigments() const{
    
    vector<Assignment> allAssignments;
    
    for (auto i = assignmentCategories.begin(); i != assignmentCategories.end(); i++){
        AssignmentBST bst = i->second;
        
        bst.getAllAssignments(allAssignments);
        
    }
    
    return allAssignments;
}



