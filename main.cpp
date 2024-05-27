#include <iostream>
#include "Budget.h"

using namespace std;

int main()
{
    Budget budget("users.xml", "Incomes.xml");
    char choice;

    while(true)
    {
        if(budget.isUserLoggedIn() == false)
        {
            choice = budget.selectOptionFromMenu();
            switch (choice)
            {
            case '1': budget.newUserRegistration(); break;
            case '2': budget.userLogin(); break;
            case '9': exit(0); break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = budget.selectOptionFromUserMenu();

            switch (choice)
            {
            case '1': budget.addIncome(); break;
            //case '2': budget.addExpense(); break;
            //case '3': budget.currentMonthBalance(); break;
            //case '4': budget.lastMonthBalance(); break;
            //case '5': budget.selectedPeriodBalance(); break;
            //case '6': budget.changeLoggedUserPassword(); break;
            case '7': budget.userLogout(); break;
            case '8': budget.userLogout(); system ("pause"); exit(0); break;
            }
        }
    }
    return 0;
}
