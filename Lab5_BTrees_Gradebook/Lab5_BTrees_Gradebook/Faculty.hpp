//
//  Faculty.hpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#ifndef Faculty_hpp
#define Faculty_hpp
#include "CSVHandler.hpp"
#include <string>

using namespace std;
class Faculty{
public:
    /*******************************************************

        * Function Name: Faculty

        * Purpose: Default constructor for Faculty class

        * Parameter: None

        * Return: None

        *******************************************************/
        Faculty();

       /*******************************************************

        * Function Name: ~Faculty

        * Purpose: Destructor for Faculty class

        * Parameter: None

        * Return: None

        *******************************************************/
        ~Faculty();

       /*******************************************************

        * Function Name: Faculty

        * Purpose: Parameterized constructor for Faculty class

        * Parameter:
           - const string& FacultyId: ID of the faculty
           - const string& firstName: First name of the faculty
           - const string& lastName: Last name of the faculty
           - const string& department: Department of the faculty
           - const string& address: Address of the faculty
           - const string& city: City of the faculty
           - const string& state: State of the faculty
           - const string& zip: Zip code of the faculty
           - const string& email: Email of the faculty
           - const string& phone: Phone number of the faculty

        * Return: None

        *******************************************************/
        Faculty(const string& FacultyId, const string& firstName, const string& lastName, const string& department, const string& address, const string& city, const string& state, const string& zip, const string& email, const string& phone);


    /*******************************************************

         * Function Name: setFacultyId

         * Purpose: Set the ID of the faculty

         * Parameter:
            - const string facultyId: ID of the faculty

         * Return: None

         *******************************************************/
        void setFacultyId(const string facultyId);

        /*******************************************************

         * Function Name: setFirstName

         * Purpose: Set the first name of the faculty

         * Parameter:
            - const string firstName: First name of the faculty

         * Return: None

         *******************************************************/
        void setFirstName(const string firstName);

        /*******************************************************

         * Function Name: setLastName

         * Purpose: Set the last name of the faculty

         * Parameter:
            - const string lastName: Last name of the faculty

         * Return: None

         *******************************************************/
        void setLastName(const string lastName);

        /*******************************************************

         * Function Name: setDepartment

         * Purpose: Set the department of the faculty

         * Parameter:
            - const string department: Department of the faculty

         * Return: None

         *******************************************************/
        void setDepartment(const string department);

        /*******************************************************

         * Function Name: setAddress

         * Purpose: Set the address of the faculty

         * Parameter:
            - const string address: Address of the faculty

         * Return: None

         *******************************************************/
        void setAddress(const string address);

        /*******************************************************

         * Function Name: setCity

         * Purpose: Set the city of the faculty

         * Parameter:
            - const string city: City of the faculty

         * Return: None

         *******************************************************/
        void setCity(const string city);

        /*******************************************************

         * Function Name: setState

         * Purpose: Set the state of the faculty

         * Parameter:
            - const string state: State of the faculty

         * Return: None

         *******************************************************/
        void setState(const string state);
    
        /*******************************************************

         * Function Name: setZip

         * Purpose: Set the zip code of the faculty

         * Parameter:
            - const string zip: Zip code of the faculty

         * Return: None

         *******************************************************/
        void setZip(const string zip);

        /*******************************************************

         * Function Name: setEmail

         * Purpose: Set the email of the faculty

         * Parameter:
            - const string email: Email of the faculty

         * Return: None

         *******************************************************/
        void setEmail(const string email);

        /*******************************************************

         * Function Name: setPhone

         * Purpose: Set the phone number of the faculty

         * Parameter:
            - const string phone: Phone number of the faculty

         * Return: None

         *******************************************************/
        void setPhone(const string phone);
    

    /*******************************************************

         * Function Name: getFacultyId

         * Purpose: Get the ID of the faculty

         * Parameter: None

         * Return: string - ID of the faculty

         *******************************************************/
        string getFacultyId() const;

        /*******************************************************

         * Function Name: getFirstName

         * Purpose: Get the first name of the faculty

         * Parameter: None

         * Return: string - First name of the faculty

         *******************************************************/
        string getFirstName() const;

        /*******************************************************

         * Function Name: getLastName

         * Purpose: Get the last name of the faculty

         * Parameter: None

         * Return: string - Last name of the faculty

         *******************************************************/
        string getLastName() const;

        /*******************************************************

         * Function Name: getDepartment

         * Purpose: Get the department of the faculty

         * Parameter: None

         * Return: string - Department of the faculty

         *******************************************************/
        string getDepartment() const;

        /*******************************************************

         * Function Name: getAddress

         * Purpose: Get the address of the faculty

         * Parameter: None

         * Return: string - Address of the faculty

         *******************************************************/
        string getAddress() const;

        /*******************************************************

         * Function Name: getCity

         * Purpose: Get the city of the faculty

         * Parameter: None

         * Return: string - City of the faculty

         *******************************************************/
        string getCity() const;

        /*******************************************************

         * Function Name: getState

         * Purpose: Get the state of the faculty

         * Parameter: None

         * Return: string - State of the faculty

         *******************************************************/
        string getState() const;
    
        /*******************************************************

         * Function Name: getZip

         * Purpose: Get the zip code of the faculty

         * Parameter: None

         * Return: string - Zip code of the faculty

         *******************************************************/
        string getZip() const;

        /*******************************************************

         * Function Name: getEmail

         * Purpose: Get the email of the faculty

         * Parameter: None

         * Return: string - Email of the faculty

         *******************************************************/
        string getEmail() const;

        /*******************************************************

         * Function Name: getPhone

         * Purpose: Get the phone number of the faculty

         * Parameter: None

         * Return: string - Phone number of the faculty

         *******************************************************/
        string getPhone() const;
    
    /*******************************************************

         * Function Name: parseFacultyCSV

         * Purpose: Parse faculty data from a CSV file and return a vector of Faculty objects

         * Parameter:
            - const string& filename: Filename of the CSV file to parse

         * Return: vector<Faculty> - Vector of Faculty objects parsed from the CSV file

         *******************************************************/
    static vector<Faculty>parseFacultyCSV(const string& filename);
    
private:
    string FacultyId, firstName, lastName, department, address, city, state, zip, email, phone;
};

#endif /* Faculty_hpp */
