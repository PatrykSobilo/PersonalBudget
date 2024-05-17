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
