//
//  Course.cpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#include "Course.hpp"

/*******************************************************

   * Function Name: Course

   * Purpose: Default constructor for Course class

   * Parameter: None

   * Return: None

   *******************************************************/
Course::Course(){}

/*******************************************************

 * Function Name: ~Course

 * Purpose: Destructor for Course class

 * Parameter: None

 * Return: None

 *******************************************************/
Course::~Course(){}

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
Course::Course(string& term, string& courseSection, string& courseName, int& units, string& facultyID, Faculty& courseFaculty) : term(term), courseSection(courseSection), courseName(courseName), units(units), facultyID(facultyID) , courseFaculty(courseFaculty){}

/*******************************************************

     * Function Name: setTerm

     * Purpose: Set the term of the course

     * Parameter:
        - string term: Term of the course

     * Return: None

     *******************************************************/
void Course::setTerm(string term){
    this->term = term;
}

/*******************************************************

 * Function Name: setCourseSection

 * Purpose: Set the section of the course

 * Parameter:
    - string courseSection: Section of the course

 * Return: None

 *******************************************************/
void Course::setCourseSection(string courseSection){
    this->courseSection = courseSection;
}

/*******************************************************

 * Function Name: setCourseName

 * Purpose: Set the name of the course

 * Parameter:
    - string courseName: Name of the course

 * Return: None

 *******************************************************/
void Course::setCourseName(string courseName){
    this->courseName = courseName;
}

/*******************************************************

 * Function Name: setUnits

 * Purpose: Set the units of the course

 * Parameter:
    - int units: Units of the course

 * Return: None

 *******************************************************/
void Course::setUnits(int units){
    this->units = units;
}

/*******************************************************

 * Function Name: setCourseFaculty

 * Purpose: Set the faculty of the course

 * Parameter:
    - Faculty courseFaculty: Faculty object representing the course faculty

 * Return: None

 *******************************************************/
void Course::setCourseFaculty(Faculty courseFaculty){
    this->courseFaculty = courseFaculty;
}


/*******************************************************

 * Function Name: setFacultyID

 * Purpose: Set the ID of the faculty teaching the course

 * Parameter:
    - string facultyID: ID of the faculty teaching the course

 * Return: None

 *******************************************************/
void Course::setFacultyID(string facultyID){
    this->facultyID = facultyID;
}



/*******************************************************

     * Function Name: getTerm

     * Purpose: Get the term of the course

     * Parameter: None

     * Return: string - Term of the course

     *******************************************************/
string Course::getTerm() const{
    return term;
}

/*******************************************************

 * Function Name: getCourseSection

 * Purpose: Get the section of the course

 * Parameter: None

 * Return: string - Section of the course

 *******************************************************/
string Course::getCourseSection() const{
    return courseSection;
}

/*******************************************************

 * Function Name: getCourseName

 * Purpose: Get the name of the course

 * Parameter: None

 * Return: string - Name of the course

 *******************************************************/
string Course::getCourseName() const{
    return courseName;
}

/*******************************************************

 * Function Name: getUnits

 * Purpose: Get the units of the course

 * Parameter: None

 * Return: int - Units of the course

 *******************************************************/
int Course::getUnits() const{
    return units;
}

/*******************************************************

 * Function Name: getFacultyID

 * Purpose: Get the ID of the faculty teaching the course

 * Parameter: None

 * Return: string - ID of the faculty teaching the course

 *******************************************************/
string Course::getFacultyID() const{
    return facultyID;
}

/*******************************************************

 * Function Name: getCourseFaculty

 * Purpose: Get the faculty of the course

 * Parameter: None

 * Return: Faculty - Faculty object representing the course faculty

 *******************************************************/
Faculty Course::getCourseFaculty() const{
    return courseFaculty;
}




/*******************************************************

    * Function Name: parseCourseCSV

    * Purpose: Parse courses from a CSV file and return a vector of Course objects

    * Parameter:
       - const string& filename: Filename of the CSV file to parse

    * Return: vector<Course> - Vector of Course objects parsed from the CSV file

    *******************************************************/
vector<Course> Course::parseCourseCSV(const string& filename) {
    vector<Course> courseData;
    
    
    vector<Faculty> facultyData = Faculty::parseFacultyCSV("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab5_BTrees_Gradebook/Lab5_data/faculty-data.csv");

    // Build a map of Faculty IDs to Faculty objects
    unordered_map<string, Faculty> facultyMap;
    for (const auto& faculty : facultyData) {
        facultyMap[faculty.getFacultyId()] = faculty;
    }

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return courseData;
    }

    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        Course course;

        // Read course information
        getline(ss, token, ',');
        course.setTerm(token);

        getline(ss, token, ',');
        course.setCourseSection(token);

        getline(ss, token, ',');
        course.setCourseName(token);

        getline(ss, token, ',');
        course.setUnits(stoi(token));

        getline(ss, token, ','); // FacultyId
        if (!token.empty() && token.back() == '\r') {
                token.pop_back();
            }
        auto it = facultyMap.find(token);
        course.setFacultyID(token);
        
        if (it != facultyMap.end()) {
            // Matched the faculty, set it to the course
            course.setCourseFaculty(it->second);
        } else {
            cerr << "Error: Faculty ID not found: " << token << endl;
            // Handle error or skip the course
        }

        courseData.push_back(course);
    }

    return courseData;
}



