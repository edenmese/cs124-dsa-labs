//
//  CSVHandler.hpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 4/25/24.
//

#ifndef CSVHandler_hpp
#define CSVHandler_hpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


template <typename T>
class CSVHandler{
public:
    /*******************************************************

     * Function Name: CSVHandler

     * Purpose: Constructor for the CSVHandler class. Initializes the object with the specified filename.

     * Parameter:
     * - filename: A constant reference to a string representing the filename of the CSV file.

     * Return: None

     *******************************************************/
    CSVHandler(const string& filename);

    /*******************************************************

     * Function Name: processCSV

     * Purpose: Processes the CSV file specified in the constructor.

     * Parameter: None

     * Return: void

     *******************************************************/
    void processCSV();

    /*******************************************************

     * Function Name: saveToCSV

     * Purpose: Saves the provided data to a CSV file.

     * Parameter:
     * - data: A constant reference to a vector of objects of type T to be saved to the CSV file.

     * Return: void

     *******************************************************/
    void saveToCSV(const vector<T>& data);

    
private:
    string filename;
};

/*******************************************************

 * Constructor Name: CSVHandler

 * Purpose: Initializes a CSVHandler object with the specified filename.

 * Parameter:
 * - filename: A constant reference to a string representing the filename of the CSV file.

 * Return: None

 *******************************************************/
template <typename T>
CSVHandler<T>::CSVHandler(const string& filename) : filename(filename){}



/*******************************************************

 * Function Name: processCSV

 * Purpose: Reads and processes the CSV file specified in the constructor.

 * Parameter: None

 * Return: void

 *******************************************************/
template<typename T>
void CSVHandler<T>::processCSV(){
    
            std::ifstream file(filename);
            if (!file.is_open()) {
                std::cerr << "Error: Could not open file " << filename << std::endl;
                return;
            }

            std::string line;
            while (std::getline(file, line)) {
                // Process each line of the CSV file
                std::istringstream iss(line);
                std::string token;
                std::vector<std::string> tokens;
                while (std::getline(iss, token, ',')) {
                    // Store each token in a vector
                    tokens.push_back(token);
                }
                // Now, we have the tokens from the current line
                // We can process them according to the type T
                // For now, let's just print them
                for (const auto& t : tokens) {
                    std::cout << t << ", ";
                }
                std::cout << std::endl;
            }
     
        }


/*******************************************************

 * Function Name: saveToCSV

 * Purpose: Saves the provided data to a CSV file.

 * Parameter:
 * - data: A constant reference to a vector of objects of type T to be saved to the CSV file.

 * Return: void

 *******************************************************/
template<typename T>
void CSVHandler<T>::saveToCSV(const vector<T>& data) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << " for writing." << endl;
        return;
    }

    // Write each entry to the file in CSV format
    for (const auto& entry : data) {
        file << entry << endl;
    }

    file.close();
    cout << "Data saved to " << filename << " successfully." << endl;
}

#endif /* CSVHandler_hpp */
