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

public:
    Budget(string usersFileName, string incomesFileName) : userManager(usersFileName),  INCOMES_FILE_NAME(incomesFileName)
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

    void addIncome();
};

#endif
