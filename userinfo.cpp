//
//  userinfo.cpp
//  testproj
//
//  Created by Ryan Cope on 11/25/19.
//  Copyright © 2019 Ryan Cope. All rights reserved.
//

#include "userinfo.hpp"

using namespace std;

void UserInfo::printIntro()
{
  cout << "-----USER INFO-----" << endl << endl;
}

void UserInfo::setName()
{
  cout << "Please enter your first and last name: " << endl;
  cin >> userFirstName >> userLastName;
}

string UserInfo::getFullName()
{
  return userFirstName + " " + userLastName;
}

string UserInfo::getFirstName()
{
  return userFirstName;
}

string UserInfo::getLastName()
{
  return userLastName;
}

