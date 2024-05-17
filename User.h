#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User
{
    int userId;
    string userName;
    string userSurname;
    string userLogin;
    string userPassword;

public:
    User(int userId = 0, string userName = "", string userSurname = "", string userLogin = "", string userPassword = "")
    {
        this->userId = userId;
        this->userName = userName;
        this->userSurname = userSurname;
        this->userLogin = userLogin;
        this->userPassword = userPassword;
    }
    void setUserId(int newUserId);
    void setUserName(string newUserName);
    void setUserSurname (string newUserSurname);
    void setUserLogin(string newUserLogin);
    void setUserPassword (string newUserPassword);

    int getUserId();
    string getUserName();
    string getUserSurname();
    string getUserLogin();
    string getUserPassword();
};

#endif
