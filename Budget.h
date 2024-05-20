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

public:
    Budget(string usersFileName) : userManager(usersFileName)
    {};
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
