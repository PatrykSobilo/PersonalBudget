#include "SuppMethods.h"

string SuppMethods::readLine()
{
    cin.sync();
    string enterLine = "";
    getline(cin, enterLine);
    return enterLine;
}

char SuppMethods::readChar()
{
    string entrance = "";
    char character  = {0};

    while (true)
    {
        getline(cin, entrance);

        if (entrance.length() == 1)
        {
            character = entrance[0];
            break;
        }
        cout << "This is not a single character. Please enter again." << endl;
    }
    return character;
}

string SuppMethods::convIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SuppMethods::convStringToInt(string numb)
{
    int numbInt;
    istringstream iss(numb);
    iss >> numbInt;

    return numbInt;
}

float SuppMethods::readFloat()
{
    cin.sync();
    float enterNumber = 0;
    cin >> enterNumber;
    return enterNumber;
}
