#include "Date.h"

int Date::getYear()
{
    return year;
}
int Date::getMonth()
{
    return month;
}
int Date::getDay()
{
    return day;
}
string Date::getTodayDate()
{
    return convertTodaysDateToString();
}

void Date::setYear(int newYear)
{
    year = newYear;
}
void Date::setMonth(int newMonth)
{
    month = newMonth;
}
void Date::setDay(int newDay)
{
    day = newDay;
}

void Date::generateActualDate()
{
    time_t actualTime = time(nullptr); //pobieranie aktualnego czasu
    tm* localTime = localtime(&actualTime); // konwersja czasu na lokalny

    //---POBIERANIE DZISIEJSZEJ DATY----//

    year = localTime -> tm_year + 1900;
    month = localTime ->tm_mon +1;
    day = localTime ->tm_mday;
}

string Date::convertTodaysDateToString()
{
    string convertedData = "";
    generateActualDate();
    convertedData = SuppMethods::convIntToString(year) + "-" +(month < 10 ? "0" : "") + SuppMethods::convIntToString(month) + "-" + (day < 10 ? "0" : "") + SuppMethods::convIntToString(day);
    return convertedData;
}

string Date::convertDateFromIntToString(int year, int month, int day)
{
    string convertedData = "";
    convertedData = SuppMethods::convIntToString(year) + "-" +(month < 10 ? "0" : "") + SuppMethods::convIntToString(month) + "-" + (day < 10 ? "0" : "") + SuppMethods::convIntToString(day);
    return convertedData;
}

string Date::readSelectedTransactionDate()
{
    string date;
    char choice;
    system("cls");
    cout << ">>> Add information about transaction <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Today's date" << endl;
    cout << "2. Other day" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = SuppMethods::readChar();

    switch(choice)
    {
    case '1':
        return getTodayDate();
        break;
    case '2':
        //cout << "getTodaysDate: " << getTodayDate() << endl;
        //cout << year << "-" << month << "-" << day << endl;
        cout << "You can add a transaction up to the last day of the current month." << endl;
        cout << "Today's date: " << getTodayDate() << endl;
        do
        {
            cout << "Enter date in YYYY-MM-DD format: ";
            date = SuppMethods::readLine();
        }
        while(!isTheTransactionDateFormatCorrect(date));
        return date;
    }
}
