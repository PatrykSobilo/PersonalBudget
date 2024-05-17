#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"
#include "SuppMethods.h"


using namespace std;

class UserManager
{
    vector <User> users;
    int loggedUserNumebrId;
    UsersFile usersFile;

    User enterNewUserData();
    int getNewUserId();
    bool isThereSuchALogin(string login);

public:
    UserManager(string usersFileName) : usersFile(usersFileName)
    {
        users = usersFile.loadUsersDataFromFile();
        loggedUserNumebrId = 0;
    }
    int getLoggedUserNumberId();
    void newUserRegistration();
    int userLogin();
    void userLogout();
    bool isUserLoggedIn();
    void changeLoggedUserPassword();
    void wypiszWszystkichUzytkownikow();
};


#endif
