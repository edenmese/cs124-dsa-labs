//
//  GradeBookMenu.cpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#include "GradeBookMenu.hpp"

/*******************************************************

     * Function Name: activate

     * Purpose: Activate GradeBookMenu to start the menu system, loads data and displays menu

     * Parameter: None

     * Return: None

     *******************************************************/
    void GradeBookMenu::activate(){
        AssignmentBST assignmentBST;
        gradeScale.loadData("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab5_BTrees_Gradebook/Lab5_data/grade-scale.csv", assignmentBST);
        displayMenu(*this);
    }

    /*******************************************************

     * Function Name: displayGradeBookCategories

     * Purpose: Display the categories in the grade book

     * Parameter: None

     * Return: None

     *******************************************************/
    void GradeBookMenu::displayGradeBookCategories(){
//        gradeScale.displayCategories();
        gradeScale.printAllAssignments();
    }



/*******************************************************

     * Function Name: viewGradeBookCategory

     * Purpose: View a specific grade book category, including individual assignments if requested by the user

     * Parameter: None

     * Return: None

     *******************************************************/
    void GradeBookMenu::viewGradeBookCategory() {
        // Display categories
        gradeScale.displayCategories();

        // Get user choice for category
        int choice;
        cout << "Enter the index of the category you want to view: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character

        // Find the category corresponding to the user's choice
        vector<string> categoryOrder = {"Assignments", "Quizzes", "Labs", "Midterm", "Final Exam"};
        if (choice >= 1 && choice <= categoryOrder.size()) {
            string selectedCategory = categoryOrder[choice - 1];
            
            // View assignments under the selected category
            gradeScale.viewCategory(selectedCategory);

            // Ask user if they want to view a specific assignment
            char viewAssignmentChoice;
            cout << "Do you want to view a specific assignment from this category? (y/n): ";
            cin >> viewAssignmentChoice;
            if (viewAssignmentChoice == 'y' || viewAssignmentChoice == 'Y') {
                viewIndividualAssignment(selectedCategory); // Call function to view individual assignment
            }
        } else {
            cout << "Invalid category index." << endl;
        }
    }

    /*******************************************************

     * Function Name: viewIndividualAssignment

     * Purpose: View an individual assignment within a category

     * Parameter: const string& selectedCategory - the selected category to view

     * Return: None

     *******************************************************/
    void GradeBookMenu::viewIndividualAssignment(const string& selectedCategory) const {
        // Search for the assignment
        // Get user input for assignment ID
        int assignmentID;
        cout << "Enter the assignment ID: ";
        cin >> assignmentID;
        
        // Search for assignment
        const Assignment* assignment = gradeScale.searchAssignment(assignmentID, selectedCategory);

        // Check if the assignment was found
        if (assignment != nullptr) {
            // Use the printAssignment function from gradeScale
            gradeScale.printAssignment(assignmentID, selectedCategory);
        } else {
            cout << "Category not found." << endl;
        }
    }



/*******************************************************

     * Function Name: displayCoursesAndFaculty

     * Purpose: Display available courses and optionally view faculty details

     * Parameter: None

     * Return: None

     *******************************************************/
void GradeBookMenu::displayCoursesAndFaculty() {
    vector<Course>allCourses = Course::parseCourseCSV("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab5_BTrees_Gradebook/Lab5_data/course-data.csv");
    cout << "Available Courses: " << endl << endl;
    int index = 1;
    for (const auto& course : allCourses ){
        cout << "---- Course (" << index++ << ") ----" << endl;
        cout << "Term: " << course.getTerm() << endl;
        cout << "Section: " << course.getCourseSection() << endl;
        cout << "Name: " << course.getCourseName() << endl;
        cout << "Units: " << course.getUnits() << endl;
        cout << "FacultyID: " << course.getFacultyID() << endl << endl;
    }
    cout << "Would you like to view Faculty? (y/n)" << endl;
    char choice;
    cin >> choice;
    if (choice == tolower('y')){
        vector<Faculty>facultyList;
        facultyList = Faculty::parseFacultyCSV("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab5_BTrees_Gradebook/Lab5_data/faculty-data.csv");
        int facultyIndex = 1;
        cout << "---- Faculty Directory ----" << endl;
        for(const auto& faculty : facultyList){
            cout << facultyIndex++ << ") -- " << faculty.getFirstName() << " " << faculty.getLastName() << endl;
        }
        cout << "Enter Faculty Index to view Faculty Details: ";
        int indexChoice;
        cin >> indexChoice;
            if (indexChoice >= 1 && indexChoice <= facultyList.size()) {
                const auto& faculty = facultyList[indexChoice - 1];
                cout << "\n---- " << faculty.getFirstName() << " " << faculty.getLastName() << " Details ----" << endl;
                cout << "ID: " << faculty.getFacultyId() << endl;
                cout << "Department: " << faculty.getDepartment() << endl;
                cout << "Address: " << faculty.getAddress() << endl;
                cout << "City: " << faculty.getCity() << endl;
                cout << "State: " << faculty.getState() << endl;
                cout << "Zip: " << faculty.getZip() << endl;
                cout << "Email: " << faculty.getEmail() << endl;
                cout << "Phone: " << faculty.getPhone() << endl << endl;
            } else {
                cout << "Invalid faculty index choice." << endl;
            }
    }
}

/*******************************************************

     * Function Name: addAssignment

     * Purpose: Add a new assignment to the grade book

     * Parameter: None

     * Return: None

     *******************************************************/
void GradeBookMenu::addAssignment() {
    // Get the groupID corresponding to the category description
    string categoryDescription;
    cout << "Enter the category description (Assignments, Quizzes, Labs, Midterm, Final Exam): ";
    //    getline(cin, categoryDescription);
    cin >> categoryDescription;
    int groupID = gradeScale.categoryDescriptionToGroupID(categoryDescription);
    if (groupID == -1) {
        cout << "Invalid category description." << endl;
        return;
    }
    cout << "Enter Assignment Title: " << endl;
    string assignmentTitle;
    cin >> assignmentTitle;
    
    // Continue with the rest of the implementation...
    DateTime startDateTime, endDateTime;
    string startDateTimeString, endDateTimeString;
    cout << "Enter Start Date (MM/DD/YYYY)";
    cin >> startDateTimeString;
    startDateTime.setDate(startDateTimeString);
    
    cout << "Enter End Date (MM/DD/YYYY)";
    cin >> endDateTimeString;
    endDateTime.setDate(endDateTimeString);
    
    cout << "Enter Possible Points: " << endl;
    int possiblePoints;
    cin >> possiblePoints;
    
    cout << "Enter Points Earned: " << endl;
    int pointsEarned;
    cin >> pointsEarned;
    
    // Get the next available assignment ID
    int assignmentID = gradeScale.setGetCurrentMaxAssignmentId(categoryDescription);
    
    Assignment newAssignment(assignmentID, groupID, assignmentTitle, startDateTime, endDateTime, possiblePoints, pointsEarned);
    
    // Insert the new assignment into the appropriate BST
    gradeScale.insertAssignment(categoryDescription, groupID, newAssignment);
    
    // Inform the user about the successful addition
    cout << "Assignment added successfully!" << endl;
    //gradeScale.printAssignment(assignmentID, categoryDescription);
    
    gradeScale.printAssignment(categoryDescription);
}

/*******************************************************

     * Function Name: editAssignment

     * Purpose: Edit an assignment within a selected category

     * Parameter: None

     * Return: None

     *******************************************************/
void GradeBookMenu::editAssignment() {
    
    // Display categories
    gradeScale.displayCategories();
    
    // Get user choice for category
    int choice;
    cout << "Enter the index of the category you want to view: ";
    cin >> choice;
    cin.ignore(); // Ignore newline character
    
    // Find the category corresponding to the user's choice
    vector<string> categoryOrder = {"Assignments", "Quizzes", "Labs", "Midterm", "Final Exam"};
    if (choice >= 1 && choice <= categoryOrder.size()) {
        string selectedCategory = categoryOrder[choice - 1];
        
        // View assignments under the selected category
        gradeScale.viewCategory(selectedCategory);
        
        // Get user input for assignment ID
        int assignmentID;
        cout << "Enter the assignment ID you want to edit: ";
        cin >> assignmentID;
        
        // Search for the assignment
        Assignment* assignment = gradeScale.searchAssignment(assignmentID, selectedCategory);
        
        // Check if the assignment was found
        if (assignment != nullptr) {
            // Print the current assignment details
            cout << "Current assignment details:" << endl;
            gradeScale.printAssignment(assignmentID, selectedCategory);
            
            // Offer edit options
            int choice;
            do {
                cout << "Select an option to edit:" << endl;
                cout << "1. Title" << endl;
                cout << "2. Possible Points" << endl;
                cout << "3. Points Earned" << endl;
                cout << "4. Due Date" << endl;
                cout << "5. Done Editing" << endl;
                cout << "Choice: ";
                cin >> choice;
                //Id,GroupId,Description,Start Date,End Date,Possible Points,Points
                
                switch (choice) {
                    case 1: {
                        string newTitle;
                        cout << "Enter the new Assignment title: ";
                        cin.ignore(); // Ignore newline character
                        getline(cin, newTitle);
                        assignment->setDescription(newTitle);
                        break;
                    }
                    case 2: {
                        int newPossiblePoints;
                        cout << "Enter the new possible points: ";
                        cin >> newPossiblePoints;
                        assignment->setPossiblePoints(newPossiblePoints);
                        break;
                    }
                    case 3: {
                        int newPointsEarned;
                        cout << "Enter the new points earned: ";
                        cin >> newPointsEarned;
                        assignment->setPoints(newPointsEarned);
                        break;
                    }
                    case 4: {
                        // You can implement setting due date here
                        break;
                    }
                    case 5: {
                        // User doesn't want to edit anything else
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                    }
                }
            } while (choice != 5);
            
            // Print the updated assignment details
            cout << "Assignment successfully edited. Updated details:" << endl;
            gradeScale.printAssignment(assignmentID, selectedCategory);
        } else {
            cout << "Assignment not found." << endl;
        }
    }
}

/*******************************************************

     * Function Name: removeAssignment

     * Purpose: Remove an assignment from a selected category

     * Parameter: None

     * Return: None

     *******************************************************/
void GradeBookMenu::removeAssignment() {
    // Display categories
    gradeScale.displayCategories();

    // Get user choice for category
    int choice;
    cout << "Enter the index of the category you want to view: ";
    cin >> choice;
    cin.ignore(); // Ignore newline character

    // Find the category corresponding to the user's choice
    vector<string> categoryOrder = {"Assignments", "Quizzes", "Labs", "Midterm", "Final Exam"};
    if (choice >= 1 && choice <= categoryOrder.size()) {
        string selectedCategory = categoryOrder[choice - 1];
        
        // View assignments under the selected category
        gradeScale.viewCategory(selectedCategory);
        
        // Get user input for assignment ID to remove
        int assignmentId;
        cout << "Enter ID of the assignment you want to remove: ";
        cin >> assignmentId;

        // Remove the assignment from the grade scale
        bool removed = gradeScale.removeAssignment(assignmentId, selectedCategory);
        if (removed) {
            cout << "Assignment successfully removed." << endl;
            gradeScale.printAssignment(selectedCategory);
        } else {
            cout << "Assignment not found or unable to remove." << endl;
        }
    } else {
        cout << "Invalid category choice." << endl;
    }
}

/*******************************************************

     * Function Name: calculateGrade

     * Purpose: Calculate the final grade percentage and letter grade

     * Parameter: None

     * Return: None

     *******************************************************/
void GradeBookMenu::calculateGrade() {

    // Initialize variables to store total points earned and total possible points
    double totalPointsEarned = 0.0;
    double totalPossiblePoints = 0.0;

    // Iterate over each grade scale to calculate points earned and possible points
   
    string categoryDescription = gradeScale.getCategoryDescription();
    double weight = gradeScale.getWeight();
    
    // Retrieve points earned and possible points for the current category
    vector<Assignment> allAssignments = gradeScale.getAllAssigments();
    for (const auto& assign: allAssignments){
        
        double pointsEarned = assign.getPointsEarned(); // Retrieve points earned for the category
        double possiblePoints = assign.getPossiblePoints(); // Retrieve possible points for the category
        
        // Add points earned and possible points to the totals
        totalPointsEarned += pointsEarned;
        totalPossiblePoints += possiblePoints * weight;
    }

    // Calculate the final grade percentage
    double finalGradePercentage = (totalPointsEarned / totalPossiblePoints) * 100.0;

    // Determine the letter grade based on the final percentage
    string letterGrade;
    if (finalGradePercentage >= 90) {
        letterGrade = "A";
    } else if (finalGradePercentage >= 80) {
        letterGrade = "B";
    } else if (finalGradePercentage >= 65) {
        letterGrade = "C";
    } else if (finalGradePercentage >= 55) {
        letterGrade = "D";
    } else {
        letterGrade = "F";
    }

    // Output the final grade
    cout << "Final Grade: " << finalGradePercentage << "% (" << letterGrade << ")" << endl;
}


/*******************************************************

     * Function Name: doExit

     * Purpose: Perform exit actions

     * Parameter: None

     * Return: None

     *******************************************************/
void GradeBookMenu::doExit(){
    gradeScale.saveAssignmentsToCSV("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab5_BTrees_Gradebook/Lab5_BTrees_Gradebook/assignment-data.csv");
}
