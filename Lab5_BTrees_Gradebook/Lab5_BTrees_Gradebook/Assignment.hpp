//
//  Assignment.hpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#ifndef Assignment_hpp
#define Assignment_hpp
#include "DateTime.hpp"
#include "CSVHandler.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Assignment{
public:
    
    /*******************************************************

         * Function Name: Assignment

         * Purpose: Default constructor for Assignment class

         * Parameter: None

         * Return: None

         *******************************************************/
    Assignment();
    
    /*******************************************************

         * Function Name: ~Assignment

         * Purpose: Destructor for Assignment class

         * Parameter: None

         * Return: None

         *******************************************************/
    ~Assignment();
    
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
    Assignment(int& id, int& groupNum, string& description, DateTime& startDate, DateTime& endDate, int& possiblePoints, int& pointsEarned);

    
    //setters
    /*******************************************************

         * Function Name: setId

         * Purpose: Set ID of the assignment

         * Parameter:
            - int id: ID of the assignment

         * Return: None

         *******************************************************/
        void setId(int id);

        /*******************************************************

         * Function Name: setGroupNum

         * Purpose: Set group number of the assignment

         * Parameter:
            - int groupNum: Group number of the assignment

         * Return: None

         *******************************************************/
        void setGroupNum(int groupNum);

        /*******************************************************

         * Function Name: setPossiblePoints

         * Purpose: Set possible points for the assignment

         * Parameter:
            - int possiblePoints: Possible points for the assignment

         * Return: None

         *******************************************************/
        void setPossiblePoints(int possiblePoints);

        /*******************************************************

         * Function Name: setPoints

         * Purpose: Set points earned for the assignment

         * Parameter:
            - int pointsEarned: Points earned for the assignment

         * Return: None

         *******************************************************/
        void setPoints(int pointsEarned);

        /*******************************************************

         * Function Name: setDescription

         * Purpose: Set description of the assignment

         * Parameter:
            - string description: Description of the assignment

         * Return: None

         *******************************************************/
        void setDescription(string description);

        /*******************************************************

         * Function Name: setStartDate

         * Purpose: Set start date of the assignment

         * Parameter:
            - DateTime startDate: Start date of the assignment

         * Return: None

         *******************************************************/
        void setStartDate(DateTime startDate);

        /*******************************************************

         * Function Name: setEndDate

         * Purpose: Set end date of the assignment

         * Parameter:
            - DateTime endDate: End date of the assignment

         * Return: None

         *******************************************************/
        void setEndDate(DateTime endDate);
    
    /*******************************************************

         * Function Name: getId

         * Purpose: Get ID of the assignment

         * Parameter: None

         * Return: int - ID of the assignment

         *******************************************************/
        int getId() const;

        /*******************************************************

         * Function Name: getGroupNum

         * Purpose: Get group number of the assignment

         * Parameter: None

         * Return: int - Group number of the assignment

         *******************************************************/
        int getGroupNum() const;

        /*******************************************************

         * Function Name: getPossiblePoints

         * Purpose: Get possible points for the assignment

         * Parameter: None

         * Return: int - Possible points for the assignment

         *******************************************************/
        int getPossiblePoints() const;

        /*******************************************************

         * Function Name: getPointsEarned

         * Purpose: Get points earned for the assignment

         * Parameter: None

         * Return: int - Points earned for the assignment

         *******************************************************/
        int getPointsEarned() const;

        /*******************************************************

         * Function Name: getDescription

         * Purpose: Get description of the assignment

         * Parameter: None

         * Return: string - Description of the assignment

         *******************************************************/
        string getDescription() const;

        /*******************************************************

         * Function Name: getStartDate

         * Purpose: Get start date of the assignment

         * Parameter: None

         * Return: DateTime - Start date of the assignment

         *******************************************************/
        DateTime getStartDate() const;

        /*******************************************************

         * Function Name: getEndDate

         * Purpose: Get end date of the assignment

         * Parameter: None

         * Return: DateTime - End date of the assignment

         *******************************************************/
        DateTime getEndDate() const;
    
    
    /*******************************************************

        * Function Name: toCSVFormat

        * Purpose: Convert assignment data to CSV format

        * Parameter: None

        * Return: string - Assignment data in CSV format

        *******************************************************/
    string toCSVFormat() const {
            stringstream ss;
            // Write assignment data to stringstream in CSV format
            ss << id << "," << groupNum << "," << description << ","
               << startDate.toString() << "," << endDate.toString() << ","
               << possiblePoints << "," << pointsEarned;
            return ss.str();
        }
    
    
    /*******************************************************

         * Function Name: parseAssignmentsCSV

         * Purpose: Parse assignments from a CSV file and return a vector of Assignment objects

         * Parameter:
            - const string& filename: Filename of the CSV file to parse

         * Return: vector<Assignment> - Vector of Assignment objects parsed from the CSV file

         *******************************************************/
    static vector<Assignment> parseAssignmentsCSV(const string& filename);
    
    
    /*******************************************************

         * Function Name: increaseId

         * Purpose: Increase the ID of the assignment

         * Parameter: None

         * Return: None

         *******************************************************/
    void increaseId(){
        id++;
    }
    
    /*******************************************************

         * Function Name: reduceId

         * Purpose: Reduce the ID of the assignment

         * Parameter: None

         * Return: None

         *******************************************************/
    void reduceId(){
        id--;
    }
    
private:
    int id, groupNum, possiblePoints, pointsEarned;
    string description;
    DateTime startDate, endDate;
};

#endif /* Assignment_hpp */
