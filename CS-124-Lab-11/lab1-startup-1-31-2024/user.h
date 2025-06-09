#ifndef USER_H
#define USER_H
#include "dateTime.h"
#include <iostream>
#include <string>

using namespace std;
class User {
public:
  User() {}
  void setID(int id);
  void setUserName(string name);
  void setPassword(string pass);
  void setFName(string fName);
  void setLName(string LName);
  void setAddress(string addy);
  void setCity(string c);
  void setState(string s);
  void setZip(string z);
  void setPhone(string phoneNumber);
  void setEmail(string mail);

  int getID() const;
  string getUserName() const;
  string getPassword() const;
  string getFName() const;
  string getLName() const;
  string getAddress() const;
  string getCity() const;
  string getState() const;
  string getZip() const;
  string getPhone() const;
  string getEmail() const;
private:
  //Data members from users_data.csv
  int userID;
  string username, password, firstName, lastName, address, city, state, zip, phone, email;
  DateTime loginDateTime, logoutDateTime; 
};

#endif