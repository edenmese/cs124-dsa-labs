//
//  Faculty.cpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#include "Faculty.hpp"

/*******************************************************

    * Function Name: Faculty

    * Purpose: Default constructor for Faculty class

    * Parameter: None

    * Return: None

    *******************************************************/
Faculty::Faculty(){}

/*******************************************************

 * Function Name: ~Faculty

 * Purpose: Destructor for Faculty class

 * Parameter: None

 * Return: None

 *******************************************************/
Faculty::~Faculty(){}

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
Faculty::Faculty(const string& FacultyId, const string& firstName, const string& lastName,const string& department,const string& address, const string& city,const string& state,const string& zip, const string& email,const string& phone): FacultyId(FacultyId), firstName(firstName), lastName(lastName), department(department), address(address), city(city), state(state), zip(zip), email(email), phone(phone){}


/*******************************************************

     * Function Name: setFacultyId

     * Purpose: Set the ID of the faculty

     * Parameter:
        - const string facultyId: ID of the faculty

     * Return: None

     *******************************************************/
void Faculty::setFacultyId(const string facultyId){
    this->FacultyId = facultyId;
}

/*******************************************************

 * Function Name: setFirstName

 * Purpose: Set the first name of the faculty

 * Parameter:
    - const string firstName: First name of the faculty

 * Return: None

 *******************************************************/
void Faculty::setFirstName(const string firstName){
    this->firstName = firstName;
}

/*******************************************************

 * Function Name: setLastName

 * Purpose: Set the last name of the faculty

 * Parameter:
    - const string lastName: Last name of the faculty

 * Return: None

 *******************************************************/
void Faculty::setLastName(const string lastName){
    this->lastName = lastName;
}

/*******************************************************

 * Function Name: setDepartment

 * Purpose: Set the department of the faculty

 * Parameter:
    - const string department: Department of the faculty

 * Return: None

 *******************************************************/
void Faculty::setDepartment(const string department){
    this->department = department;
}

/*******************************************************

 * Function Name: setAddress

 * Purpose: Set the address of the faculty

 * Parameter:
    - const string address: Address of the faculty

 * Return: None

 *******************************************************/
void Faculty::setAddress(const string address){
    this->address = address;
}

/*******************************************************

 * Function Name: setCity

 * Purpose: Set the city of the faculty

 * Parameter:
    - const string city: City of the faculty

 * Return: None

 *******************************************************/
void Faculty::setCity(const string city){
    this->city = city;
}

/*******************************************************

 * Function Name: setState

 * Purpose: Set the state of the faculty

 * Parameter:
    - const string state: State of the faculty

 * Return: None

 *******************************************************/
void Faculty::setState(const string state){
    this->state = state;
}

/*******************************************************

 * Function Name: setZip

 * Purpose: Set the zip code of the faculty

 * Parameter:
    - const string zip: Zip code of the faculty

 * Return: None

 *******************************************************/
void Faculty::setZip(const string zip){
    this->zip = zip;
}

/*******************************************************

 * Function Name: setEmail

 * Purpose: Set the email of the faculty

 * Parameter:
    - const string email: Email of the faculty

 * Return: None

 *******************************************************/
void Faculty::setEmail(const string email){
    this->email = email;
}

/*******************************************************

 * Function Name: setPhone

 * Purpose: Set the phone number of the faculty

 * Parameter:
    - const string phone: Phone number of the faculty

 * Return: None

 *******************************************************/
void Faculty::setPhone(const string phone){
    this->phone = phone;
}


/*******************************************************

     * Function Name: getFacultyId

     * Purpose: Get the ID of the faculty

     * Parameter: None

     * Return: string - ID of the faculty

     *******************************************************/
string Faculty::getFacultyId() const{
    return FacultyId;
}

/*******************************************************

 * Function Name: getFirstName

 * Purpose: Get the first name of the faculty

 * Parameter: None

 * Return: string - First name of the faculty

 *******************************************************/
string Faculty::getFirstName()const{
    return firstName;
}

/*******************************************************

 * Function Name: getLastName

 * Purpose: Get the last name of the faculty

 * Parameter: None

 * Return: string - Last name of the faculty

 *******************************************************/
string Faculty::getLastName()const{
    return lastName;
}

/*******************************************************

 * Function Name: getDepartment

 * Purpose: Get the department of the faculty

 * Parameter: None

 * Return: string - Department of the faculty

 *******************************************************/
string Faculty::getDepartment()const{
    return department;
}

/*******************************************************

 * Function Name: getAddress

 * Purpose: Get the address of the faculty

 * Parameter: None

 * Return: string - Address of the faculty

 *******************************************************/
string Faculty::getAddress()const{
    return address;

}

/*******************************************************

 * Function Name: getCity

 * Purpose: Get the city of the faculty

 * Parameter: None

 * Return: string - City of the faculty

 *******************************************************/
string Faculty::getCity()const{
    return city;

}

/*******************************************************

 * Function Name: getState

 * Purpose: Get the state of the faculty

 * Parameter: None

 * Return: string - State of the faculty

 *******************************************************/
string Faculty::getState()const{
    return state;

}

/*******************************************************

 * Function Name: getZip

 * Purpose: Get the zip code of the faculty

 * Parameter: None

 * Return: string - Zip code of the faculty

 *******************************************************/
string Faculty::getZip()const{
    return zip;

}

/*******************************************************

 * Function Name: getEmail

 * Purpose: Get the email of the faculty

 * Parameter: None

 * Return: string - Email of the faculty

 *******************************************************/
string Faculty::getEmail()const{
    return email;

}

/*******************************************************

 * Function Name: getPhone

 * Purpose: Get the phone number of the faculty

 * Parameter: None

 * Return: string - Phone number of the faculty

 *******************************************************/
string Faculty::getPhone()const{
    return phone;

}


/*******************************************************

     * Function Name: parseFacultyCSV

     * Purpose: Parse faculty data from a CSV file and return a vector of Faculty objects

     * Parameter:
        - const string& filename: Filename of the CSV file to parse

     * Return: vector<Faculty> - Vector of Faculty objects parsed from the CSV file

     *******************************************************/
vector<Faculty>Faculty::parseFacultyCSV(const string& filename){
    vector<Faculty>facultyData;
    
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error: Could not open file " << filename << endl;
        return facultyData;
    }
    
    string line;
    
    getline(file, line);
    
    while(getline(file,line)){
        stringstream ss(line);
        string token;
        Faculty faculty;
        
        getline(ss,token,',');
        faculty.setFacultyId(token);
        
        getline(ss,token,',');
        faculty.setFirstName(token);
        
        getline(ss,token,',');
        faculty.setLastName(token);
        
        getline(ss,token,',');
        faculty.setDepartment(token);
        
        getline(ss,token,',');
        faculty.setAddress(token);
        
        getline(ss,token,',');
        faculty.setCity(token);
        
        getline(ss,token,',');
        faculty.setState(token);
        
        getline(ss,token,',');
        faculty.setZip(token);
        
        getline(ss,token,',');
        faculty.setEmail(token);
        
        getline(ss,token,',');
        faculty.setPhone(token);

        // Add the course to the vector
        facultyData.push_back(faculty);
    }
    
    return facultyData;
}
