/*
    Ryan Cope & Cindy Ramirez
    DVC Fall 2019, Comsc 165, Section 5065
    Professor Heidi Gentry-Kolen
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

//Need to add in data files
// Zip Codes with Lat/Long

using namespace std;

//Struct for storing user's information
struct userInfo
{
  string userFirstName;
  string userLastName;
};

//Struct for storing user's job information
struct userJobInfo
{
  string jobTitle;
  string jobZipCode;
  double jobAnnualSalary;
};

//Struct for storing user's tax information
struct userTaxInfo
{
  string filingStatus;
  int dependentCount;
  float taxRate;
};

//Struct for expense information (will use in vector)
struct userExpenseInfo
{
  string expenseName;
  double expenseAmount;
  string expenseFrequency;
};

//Struct for items to save for (will use in vector)
struct itemSavingInfo
{
  string itemName;
  double itemAmount;
  double savingAmountPerMonth;
  int savingMonths;
};



// Main function
int main()
{




  return 0;
}
