//
//  Course.hpp
//  StudenPortfolio_Lab2
//
//  Created by Eden Meseret on 3/26/24.
//

#ifndef Course_hpp
#define Course_hpp

#include <iostream>
#include <string>
using namespace std;

class course {
private:
    string Department;
    string Course;
    string Title;
    string Description;
    string Prerequisite;
    int Units;

public:
    // Constructors
    course();
    course(string dept, string courseNum, string title, string desc, string prereq, int units);

    // Getters and Setters
    string getDepartment() const;
    void setDepartment(string dept);

    string getCourse() const;
    void setCourse(string courseNum);

    string getTitle() const;
    void setTitle(string title);

    string getDescription() const;
    void setDescription(string desc);

    string getPrerequisite() const;
    void setPrerequisite(string prereq);

    int getUnits() const;
    void setUnits(int units);

    // Overloading stream insertion operator for printing
    friend ostream& operator<<(ostream& os, const course& crs);
};


#endif /* Course_hpp */
