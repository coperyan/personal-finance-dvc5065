

#ifndef userincomeinfo_hpp
#define userincomeinfo_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class UserIncomeInfo
{
public:
    UserIncomeInfo()
    {
        printIntro();
        setJobTitle();
        setJobZip();
        setJobSalary();
        setFilingStatus();
        setDependentCount();
        setTaxRate();
        showEstNetIncome();
    }
    void printIntro();
    void setJobTitle();
    void setJobZip();
    void setJobSalary();
    void setFilingStatus();
    void setDependentCount();
    void setTaxRate();
    void showEstNetIncome();
    string getJobZip();
private:
    string jobTitle;
    string jobZip;
    double jobSalary;
    string filingStatus;
    int dependentCount;
    float taxRate;
    float estimatedNetSalary;
};

#endif /* userincomeinfo_hpp */
