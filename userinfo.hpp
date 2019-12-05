

#ifndef userinfo_hpp
#define userinfo_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class UserInfo
{
public:
  UserInfo()
    {
        printIntro();
        setName();
    }
  void printIntro();
  void setName();
  string getFullName();
  string getFirstName();
  string getLastName();
private:
  string userFirstName;
  string userLastName;
};


#endif /* userinfo_hpp */
