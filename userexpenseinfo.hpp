

#ifndef userexpenseinfo_hpp
#define userexpenseinfo_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct UserExpInfo
{
    string expenseName;
    double expenseAmount;
    string expenseFrequency;
};

class UserExpenseInfo
{
public:
    UserExpenseInfo()
    {
        printIntro();
        collectUserExpenses();
    }
    void printIntro();
    void collectUserExpenses();
    void setTotalMonthlyExpenses(double);
    void showTotalMonthlyExpenses();
    double getTotalMonthlyExpenses();
private:
    vector<UserExpInfo> expInfo;
    double totalMonthlyExpenses;
};

#endif /* userexpenseinfo_hpp */
