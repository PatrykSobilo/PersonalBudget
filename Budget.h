#ifndef BUDGET_H
#define BUDGET_H
#include <iostream>

#include "UserManager.h"
#include "TransactionManager.h"
#include "Markup.h"

using namespace std;

class Budget
{
    UserManager userManager;
    TransactionManager *transactionManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    Budget(string usersFileName, string incomesFileName, string expensesFileName) : userManager(usersFileName),  INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    { transactionManager = NULL;};
    ~Budget()
    {
        delete transactionManager;
        transactionManager = NULL;
    }
    bool isUserLoggedIn();
    void newUserRegistration();
    int userLogin();
    char selectOptionFromMenu();
    char selectOptionFromUserMenu();
    void userLogout();
    void changeLoggedUserPassword();
    //------------------------------------//
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void lastMonthBalance();
    //void selectedPeriodBalance();
};

#endif
