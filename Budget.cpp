#include "Budget.h"

bool Budget::isUserLoggedIn()
{
    if(userManager.isUserLoggedIn()) return true;
    else return false;
}

char Budget::selectOptionFromMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Close the program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = SuppMethods::readChar();

    return choice;
}
char Budget::selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance of the current month" << endl;
    cout << "4. Balance of the past month" << endl;
    cout << "5. Balance from the selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = SuppMethods::readChar();

    return choice;
}

void Budget::newUserRegistration()
{
    userManager.newUserRegistration();
}

int Budget::userLogin()
{
    userManager.userLogin();
    transactionManager = new TransactionManager(userManager.getLoggedUserNumberId(), INCOMES_FILE_NAME, EXPENSES_FILE_NAME);
}

void Budget::userLogout()
{
    userManager.userLogout();
}

void Budget::changeLoggedUserPassword()
{
    userManager.changeLoggedUserPassword();
}
//--------------------TRANSACTIONS--------------------------//

void Budget::addIncome()
{
    transactionManager -> addIncome();
}

void Budget::addExpense()
{
    transactionManager -> addExpense();
}

/*void Budget::currentMonthBalance()
{
    transactionManager -> currentMonthBalance();
}

void Budget::lastMonthBalance()
{
    transactionManager -> lastMonthBalance();
}

void Budget::selectedPeriodBalance()
{
    transactionManager -> selectedPeriodBalance();
}*/
