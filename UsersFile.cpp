#include "UsersFile.h"


void UsersFile::addUserDataToFile(User newUserData)
{
    CMarkup usersFile;

    if (!usersFile.Load(USERS_FILE_NAME))
    {
        usersFile.AddElem("Users");
        addToFile(newUserData, usersFile);
    }
    else
    {
        usersFile.FindElem("Users");
        addToFile(newUserData, usersFile);
    }
}

void UsersFile::addToFile(User newUserData, CMarkup usersFile)
{
    usersFile.IntoElem();
    usersFile.AddElem("User");
    usersFile.IntoElem();
    usersFile.AddElem("UserId", newUserData.getUserId());
    usersFile.AddElem("UserName", newUserData.getUserName());
    usersFile.AddElem("UserSurname", newUserData.getUserSurname());
    usersFile.AddElem("UserLogin", newUserData.getUserLogin());
    usersFile.AddElem("UserPassword", newUserData.getUserPassword());
    usersFile.Save(USERS_FILE_NAME);
}

vector <User> UsersFile::loadUsersDataFromFile()
{
    CMarkup usersFile;
    User user;
    vector <User> users;

    usersFile.Load(USERS_FILE_NAME);
    usersFile.FindElem("Users");
    usersFile.IntoElem();
    while(usersFile.FindElem("User"))
    {
        usersFile.IntoElem();
        usersFile.FindElem("UserId");
        user.setUserId(stoi(usersFile.GetData()));

        usersFile.FindElem("UserName");
        user.setUserName(usersFile.GetData());

        usersFile.FindElem("UserSurname");
        user.setUserSurname(usersFile.GetData());

        usersFile.FindElem("UserLogin");
        user.setUserLogin(usersFile.GetData());

        usersFile.FindElem("UserPassword");
        user.setUserPassword(usersFile.GetData());

        users.push_back(user);
        usersFile.OutOfElem();
    }
    return users;
}

void UsersFile::changePasswordInUsersFile(string newPassword, int loggedUserNumebrId)
{
    CMarkup usersFile;
    int numberIdFromFile = 0;

    usersFile.Load(USERS_FILE_NAME);
    usersFile.FindElem("Users");
    usersFile.IntoElem();

    while(usersFile.FindElem("User"))
    {
        usersFile.IntoElem();
        usersFile.FindElem("UserId");
        numberIdFromFile = stoi(usersFile.GetData());

        if(numberIdFromFile == loggedUserNumebrId)
        {
            usersFile.FindElem("UserPassword");
            usersFile.RemoveElem();
            usersFile.AddElem("UserPassword", newPassword);
            usersFile.OutOfElem();
            break;
        }
        usersFile.OutOfElem();
    }
    usersFile.Save(USERS_FILE_NAME);
}
