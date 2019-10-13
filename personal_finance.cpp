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

//Class for storing all data
class PersonalFinance
{
};

//Class for storing user's information
class UserInfo
{
  public:
    void SetName();
    string getFullName();
    string getFirstName();
    string getLastName();
  private:
    string userFirstName;
    string userLastName;
};

//Mutator function to add name to UserInfo class
void UserInfo::SetName()
{
  cout << "Please enter your first and last name: " << endl;
  cin >> userFirstName >> userLastName;
}

//Accessor function to get name
string UserInfo::getFullName()
{
  return userFirstName + " " + userLastName;
}

//Accessor function to get first name
string UserInfo::getFirstName()
{
  return userFirstName;
}

//Accessor function to get last name
string UserInfo::getLastName()
{
  return userLastName;
}

//Class for job info
class userIncomeInfo
{
  public:
    void setJobTitle();
    void setJobZip();
    void setJobSalary();
    void setFilingStatus();
    void setDependentCount();
    void setTaxRate();
  private:
    string jobTitle;
    string jobZip;
    double jobSalary;
    string filingStatus;
    int dependentCount;
    float taxRate;
    float estimatedNetSalary;
};

void userIncomeInfo::setJobTitle()
{
  cout << "Please enter your job title: " << endl;
  cin >> jobTitle;
}

void userIncomeInfo::setJobZip()
{
  cout << "Please enter your job's zip code: " << endl;
  cin >> jobZip;
}

void userIncomeInfo::setJobSalary()
{
  cout << "Please enter your job's salary: " << endl;
  cin >> jobSalary;
}

void userIncomeInfo::setFilingStatus()
{
  cout << "Please enter your filing status (Single or Married): " << endl;
  cin >> filingStatus;
}

void userIncomeInfo::setDependentCount()
{
  cout << "Please enter the count of dependents you claim (int): " << endl;
  cin >> dependentCount;
}

void userIncomeInfo::setTaxRate()
{
  if(filingStatus == "Single")
  {
    if(jobSalary <= 8544)
    {
      taxRate = 0.01;
    }
    else if (jobSalary <= 20255)
    {
      taxRate = 0.02;
    }
    else if (jobSalary <= 31969)
    {
      taxRate = 0.04;
    }
    else if (jobSalary <= 44377)
    {
      taxRate = 0.06;
    }
    else if (jobSalary <= 56085)
    {
      taxRate = 0.08;
    }
    else if (jobSalary <= 286492)
    {
      taxRate = 0.093;
    }
    else if (jobSalary <= 343788)
    {
      taxRate = 0.103;
    }
    else if (jobSalary <= 572980)
    {
      taxRate = 0.113;
    }
    else if (jobSalary >= 572981)
    {
      taxRate = 0.123;
    }
    else
    {
      taxRate = 0.00;
    }
  }
  else if(filingStatus == "Married")
  {
    if(jobSalary <= 17088)
    {
      taxRate = 0.01;
    }
    else if (jobSalary <= 40510)
    {
      taxRate = 0.02;
    }
    else if (jobSalary <= 63938)
    {
      taxRate = 0.04;
    }
    else if (jobSalary <= 88754)
    {
      taxRate = 0.06;
    }
    else if (jobSalary <= 112170)
    {
      taxRate = 0.08;
    }
    else if (jobSalary <= 572984)
    {
      taxRate = 0.093;
    }
    else if (jobSalary <= 687576)
    {
      taxRate = 0.103;
    }
    else if (jobSalary <= 1145960)
    {
      taxRate = 0.113;
    }
    else if (jobSalary >= 1145961)
    {
      taxRate = 0.123;
    }
    else
    {
      taxRate = 0.00;
    }
  }
}

//Struct for expense information (will use in vector)
struct userExpInfo
{
  string expenseName;
  double expenseAmount;
  string expenseFrequency;
};

class userExpenseInfo
{
  public:
    void collectUserExpenses();
  private:
    vector<userExpInfo> expInfo;
};

void userExpenseInfo::collectUserExpenses()
{

  bool continueCollect = true;
  while(continueCollect)
  {
    userExpInfo uei;
    char usrReply;

    cout << "Please enter the expense name: " << endl;
    cin >> uei.expenseName;

    cout << "Please enter the expense amount: " << endl;
    cin >> uei.expenseAmount;

    cout << "Please enter the expense frequency (Daily, Weekly, Monthly): " << endl;
    cin >> uei.expenseFrequency;

    expInfo.push_back(uei);

    cout << "Would you like to enter another expense? (Y/N)" << endl;
    cin >> usrReply;

    if(usrReply == 'Y')
    {
     continueCollect = true;
    }
    else
    {
      continueCollect = false;
    }
  }
}

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

  userExpenseInfo yaDude;
  yaDude.collectUserExpenses();

  cin.get();
  cin.get();

  return 0;
}
