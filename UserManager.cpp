#include "UserManager.h"

void UserManager::newUserRegistration()
{
    User newUser = enterNewUserData();

    users.push_back(newUser);
    usersFile.addUserDataToFile(newUser);
}

User UserManager::enterNewUserData()
{
    User newUser;
    string newUserName;
    string newUserSurname;
    string newUserLogin;
    string newUserPassword;

    newUser.setUserId(getNewUserId());

    cout << "Name: ";
    cin >> newUserName;
    newUser.setUserName(newUserName);

    cout << "Surname: ";
    cin >> newUserSurname;
    newUser.setUserSurname(newUserSurname);

    do
    {
        cout << "Login: ";
        cin >> newUserLogin;
        newUser.setUserLogin(newUserLogin);
    }
    while(isThereSuchALogin(newUser.getUserLogin()) == true);

    cout << "Password: ";
    cin >> newUserPassword;
    newUser.setUserPassword(newUserPassword);
    return newUser;
}

int UserManager::getNewUserId()
{
    if(users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::isThereSuchALogin(string login)
{
    int numberOfUsers = users.size();
    for(int i = 0; i < numberOfUsers; i++)
    {
        if(users[i].getUserLogin() == login)
        {
            cout << endl << "The specified login is taken. Please enter a different login." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::userLogin()
{
    User user;
    string login = "";
    string password = "";
    string loginFromFile = "";
    int numberOfRegisteredUsers = users.size();

    cout << "Enter your login: " << endl;
    login = SuppMethods::readLine();

    for(int i = 0; i < numberOfRegisteredUsers; i++)
    {
        loginFromFile = users[i].getUserLogin();
        if(loginFromFile == login)
        {
            for(int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Enter the password. " << numberOfAttempts << " attempts left"  << ": ";
                password = SuppMethods::readLine();
                if(users[i].getUserPassword() == password)
                {
                    cout << endl << "You have logged in" << endl;
                    loggedUserNumebrId = i + 1;
                    system("pause");
                    return loggedUserNumebrId;
                }
            }
            cout << "Incorrect password entered 3 times" << endl;
            system("pause");
            return 0;
        }
    }
    cout << "There is no user with such login" << endl;
    system("pause");
    return 0;
}

int UserManager::getLoggedUserNumberId()
{
    return loggedUserNumebrId;
}

void UserManager::userLogout()
{
    loggedUserNumebrId = 0;
    cout << "You have been logged out" << endl;
}

void UserManager::wypiszWszystkichUzytkownikow()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getUserId() << endl;
        cout << users[i].getUserName() << endl;
        cout << users[i].getUserSurname() << endl;
        cout << users[i].getUserLogin() << endl;
        cout << users[i].getUserPassword() << endl;
        cout << "-------------" << endl;
    }
    system("pause");
}

bool UserManager::isUserLoggedIn()
{
    if(loggedUserNumebrId > 0) return true;
    else return false;
}

void UserManager::changeLoggedUserPassword()
{
    string newPassword = "";
    int numberOfUsers = users.size();
    cout << "Enter new password: ";
    newPassword = SuppMethods::readLine();

    for(int i = 0; i < numberOfUsers; i++)
    {
        if(users[i].getUserId() == loggedUserNumebrId)
        {
            users[i].setUserPassword(newPassword);
            cout << "Password has been changed" << endl << endl;
            system("pause");
            break;
        }
    }
    usersFile.changePasswordInUsersFile(newPassword, loggedUserNumebrId);
}
