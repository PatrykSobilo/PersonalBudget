#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <string>
#include <vector>
#include "Markup.h"

#include "User.h"

using namespace std;

class UsersFile
{
    const string USERS_FILE_NAME;
    void addToFile(User newUserData, CMarkup usersFile);
public:
    UsersFile(string usersFileName) : USERS_FILE_NAME(usersFileName){};
    void addUserDataToFile(User newUserData);
    vector <User> loadUsersDataFromFile();
    void changePasswordInUsersFile(string newPassword, int loggedUserNumebrId);
};

#endif
