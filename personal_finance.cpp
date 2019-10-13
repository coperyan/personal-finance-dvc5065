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
  return userFirstName << " " << userLastName;
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
class userJobInfo
{
  public:
    void setJobTitle();
    void setJobZip();
    void setJobSalary();
  private:
    string jobTitle;
    string jobZip;
    double jobSalary;
};

void userJobInfo::setJobTitle()
{
  cout << "Please enter your job title: " << endl;
  cin >> jobTitle;
}

void userJobInfo::setJobZip()
{
  cout << "Please enter your job's zip code: " << endl;
  cin >> jobZip;
}

void userJobInfo::setJobSalary()
{
  cout << "Please enter your job's salary: " < endl;
  cin >> jobSalary;
}

//Class for user tax info
class userTaxInfo
{
  public:
    void setFilingStatus();
    void setDependentCount();
    void setTaxRate();
  private:
    string filingStatus;
    int dependentCount;
    float taxRate;
};

void userTaxInfo::setFilingStatus();
{
  cout << "Please enter your filing status (Single, Married, etc.): "
  cin >> filingStatus;
}

void userTaxInfo::setDependentCount();
{
  cout << "Please enter the count of dependents you claim (int): "
  cin >> dependentCount;
}

void userTaxInfo::setTaxRate();
{
  switch()
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

    cout >> "Please enter the expense frequency (Daily, Weekly, Monthly): " << endl;
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




  return 0;
}
