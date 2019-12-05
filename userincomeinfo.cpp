

#include "userincomeinfo.hpp"

using namespace std;

void UserIncomeInfo::printIntro()
{
  cout << "----------INCOME INFO----------" << endl << endl;
}

void UserIncomeInfo::setJobTitle()
{
  cout << "Please enter your job title: " << endl;
  cin >> jobTitle;
}

void UserIncomeInfo::setJobZip()
{
  cout << "Please enter your job's zip code: " << endl;
  cin >> jobZip;
}

void UserIncomeInfo::setJobSalary()
{
  cout << "Please enter your job's salary (int): " << endl;
  cin >> jobSalary;
}

void UserIncomeInfo::setFilingStatus()
{
  cout << "Please enter your filing status (Single or Married): " << endl;
  cin >> filingStatus;
}

void UserIncomeInfo::setDependentCount()
{
  cout << "Please enter the count of dependents you claim (int): " << endl;
  cin >> dependentCount;
}

void UserIncomeInfo::setTaxRate()
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

void UserIncomeInfo::showEstNetIncome()
{
    cout << "Estimated Net Income: $"  << jobSalary * (1.00 - taxRate) << endl;
}

string UserIncomeInfo::getJobZip()
{
    return jobZip;
}
