#include <iostream>
#include "Budget.h"

using namespace std;

int main()
{
    Budget budget("users.xml");
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
            cout << "W kolejnych krokach..." << endl;
            break;
        }
    }
    return 0;
}
