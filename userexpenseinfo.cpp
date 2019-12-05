

#include "userexpenseinfo.hpp"
using namespace std;

void UserExpenseInfo::printIntro()
{
  cout << "----------EXPENSE INFO----------" << endl << endl;
}

void UserExpenseInfo::collectUserExpenses()
{

  int vectorLen = 0;
  double vectorTotal = 0.00;
  bool continueCollect = true;
  while(continueCollect)
  {
    UserExpInfo uei;
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

  vectorLen = expInfo.size();
  for(int i = 0; i < vectorLen; i++)
  {
    if(expInfo[i].expenseFrequency == "Daily")
    {
      vectorTotal = vectorTotal + (expInfo[i].expenseAmount * 30);
    }
    else if(expInfo[i].expenseFrequency == "Weekly")
    {
      vectorTotal = vectorTotal + (expInfo[i].expenseAmount * 4);
    }
    else if(expInfo[i].expenseFrequency == "Monthly")
    {
      vectorTotal = vectorTotal + expInfo[i].expenseAmount;
    }
  }

    setTotalMonthlyExpenses(vectorTotal);
    showTotalMonthlyExpenses();

}

void UserExpenseInfo::setTotalMonthlyExpenses(double expenseTotal)
{
    totalMonthlyExpenses = expenseTotal;
}

void UserExpenseInfo::showTotalMonthlyExpenses()
{
    cout << "Total Monthly Expenses: $" << totalMonthlyExpenses << endl;
}

double UserExpenseInfo::getTotalMonthlyExpenses()
{
    return totalMonthlyExpenses;
}
