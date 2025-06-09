//
//  Assignment.cpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#include "Assignment.hpp"

//constructors and destructor

/*******************************************************

     * Function Name: Assignment

     * Purpose: Default constructor for Assignment class

     * Parameter: None

     * Return: None

     *******************************************************/
Assignment::Assignment(){}

/*******************************************************

     * Function Name: ~Assignment

     * Purpose: Destructor for Assignment class

     * Parameter: None

     * Return: None

     *******************************************************/
Assignment::~Assignment(){}

/*******************************************************

     * Function Name: Assignment

     * Purpose: Parameterized constructor for Assignment class

     * Parameter:
        - int& id: ID of the assignment
        - int& groupNum: Group number of the assignment
        - string& description: Description of the assignment
        - DateTime& startDate: Start date of the assignment
        - DateTime& endDate: End date of the assignment
        - int& possiblePoints: Possible points for the assignment
        - int& pointsEarned: Points earned for the assignment

     * Return: None

     *******************************************************/
Assignment::Assignment(int& id, int& groupNum, string& description, DateTime& startDate, DateTime& endDate, int& possiblePoints, int& pointsEarned) : id(id), groupNum(groupNum), description(description), startDate(startDate), endDate(endDate), possiblePoints(possiblePoints), pointsEarned(pointsEarned){}




/*******************************************************

     * Function Name: setId

     * Purpose: Set ID of the assignment

     * Parameter:
        - int id: ID of the assignment

     * Return: None

     *******************************************************/
void Assignment::setId(int id){
    this->id = id;
}

/*******************************************************

 * Function Name: setGroupNum

 * Purpose: Set group number of the assignment

 * Parameter:
    - int groupNum: Group number of the assignment

 * Return: None

 *******************************************************/
void Assignment::setGroupNum(int groupNum){
    this->groupNum = groupNum;

}

/*******************************************************

 * Function Name: setPossiblePoints

 * Purpose: Set possible points for the assignment

 * Parameter:
    - int possiblePoints: Possible points for the assignment

 * Return: None

 *******************************************************/
void Assignment::setPossiblePoints(int possiblePoints){
    this->possiblePoints = possiblePoints;

}

/*******************************************************

 * Function Name: setPoints

 * Purpose: Set points earned for the assignment

 * Parameter:
    - int pointsEarned: Points earned for the assignment

 * Return: None

 *******************************************************/
void Assignment::setPoints(int pointsEarned){
    this->pointsEarned = pointsEarned;

}

/*******************************************************

 * Function Name: setDescription

 * Purpose: Set description of the assignment

 * Parameter:
    - string description: Description of the assignment

 * Return: None

 *******************************************************/
void Assignment::setDescription(string description){
    this->description = description;

}

/*******************************************************

 * Function Name: setStartDate

 * Purpose: Set start date of the assignment

 * Parameter:
    - DateTime startDate: Start date of the assignment

 * Return: None

 *******************************************************/
void Assignment::setStartDate(DateTime startDate){
    this->startDate = startDate;

}

/*******************************************************

 * Function Name: setEndDate

 * Purpose: Set end date of the assignment

 * Parameter:
    - DateTime endDate: End date of the assignment

 * Return: None

 *******************************************************/
void Assignment::setEndDate(DateTime endDate){
    this->endDate = endDate;

}


/*******************************************************

     * Function Name: getId

     * Purpose: Get ID of the assignment

     * Parameter: None

     * Return: int - ID of the assignment

     *******************************************************/
int Assignment::getId()const{
    return id;
}

/*******************************************************

 * Function Name: getGroupNum

 * Purpose: Get group number of the assignment

 * Parameter: None

 * Return: int - Group number of the assignment

 *******************************************************/
int Assignment::getGroupNum()const{
    return groupNum;
}

/*******************************************************

 * Function Name: getPossiblePoints

 * Purpose: Get possible points for the assignment

 * Parameter: None

 * Return: int - Possible points for the assignment

 *******************************************************/
int Assignment::getPossiblePoints()const{
    return possiblePoints;
}

/*******************************************************

 * Function Name: getPointsEarned

 * Purpose: Get points earned for the assignment

 * Parameter: None

 * Return: int - Points earned for the assignment

 *******************************************************/
int Assignment::getPointsEarned()const{
    return pointsEarned;
}

/*******************************************************

 * Function Name: getDescription

 * Purpose: Get description of the assignment

 * Parameter: None

 * Return: string - Description of the assignment

 *******************************************************/
string Assignment::getDescription()const{
    return description;
}

/*******************************************************

 * Function Name: getStartDate

 * Purpose: Get start date of the assignment

 * Parameter: None

 * Return: DateTime - Start date of the assignment

 *******************************************************/
DateTime Assignment::getStartDate()const{
    return startDate;
}


/*******************************************************

 * Function Name: getEndDate

 * Purpose: Get end date of the assignment

 * Parameter: None

 * Return: DateTime - End date of the assignment

 *******************************************************/
DateTime Assignment::getEndDate()const{
    return endDate;
}

/*******************************************************

    * Function Name: parseAssignmentsCSV

    * Purpose: Parse assignments from a CSV file and return a vector of Assignment objects

    * Parameter:
       - const string& filename: Filename of the CSV file to parse

    * Return: vector<Assignment> - Vector of Assignment objects parsed from the CSV file

    *******************************************************/
vector<Assignment>Assignment::parseAssignmentsCSV(const string& filename){
    vector<Assignment>assignmentsData;
    
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error: Could not open file " << filename << endl;
        return assignmentsData;
    }
    
    string line;
    
    getline(file, line);
    
    while(getline(file,line)){
        stringstream ss(line);
        
        string token;
        Assignment assignment;
        
        getline(ss,token,',');
        assignment.setId(stoi(token));
        
        getline(ss,token,',');
        assignment.setGroupNum(stoi(token));
        
        getline(ss,token,',');
        assignment.setDescription(token);
        
        DateTime dateTime;
        
        getline(ss,token,',');
        dateTime.setDateTime(token);
        assignment.setStartDate(dateTime);
        
        getline(ss,token,',');
        dateTime.setDateTime(token);
        assignment.setEndDate(dateTime);
        
        getline(ss,token,',');
        assignment.setPossiblePoints(stoi(token));
        
        getline(ss,token,',');
        assignment.setPoints(stoi(token));

        assignmentsData.push_back(assignment);
        
    }
    return assignmentsData;
}
