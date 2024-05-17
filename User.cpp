#include "User.h"

void User::setUserId(int newUserId)
{
    userId = newUserId;
}

void User::setUserName(string newUserName)
{
    userName = newUserName;
}

void User::setUserSurname (string newUserSurname)
{
    userSurname = newUserSurname;
}

void User::setUserLogin(string newUserLogin)
{
    userLogin = newUserLogin;
}

void User::setUserPassword (string newUserPassword)
{
    userPassword = newUserPassword;
}

int User::getUserId()
{
    return userId;
}
string User::getUserName()
{
    return userName;
}
string User::getUserSurname()
{
    return userSurname;
}
string User::getUserLogin()
{
    return userLogin;
}
string User::getUserPassword()
{
    return userPassword;
}
