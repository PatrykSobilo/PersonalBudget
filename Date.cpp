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

bool Date::isTheTransactionDateFormatCorrect(string &date)
{
    int enteredYear = 0;
    int enteredMonth = 0;
    int enteredDay = 0;

    if(date.length() != 10) return false; //sprawdza czy wprowadzono 10 znakow
    for(int i = 0; i < 10; i++)
    {
        if(!(isdigit(date[i]) || date[i] == '-')) return false; //sprawdza kolejne znaki czy to cyfra lub "-"
        if((i == 4 || i == 7) && date[i] != '-') return false; // sprawdza czy myslniki sa na odpowiedniej pozycji
    }
    enteredYear = stoi(date.substr(0,4));
    enteredMonth = stoi(date.substr(5,2));
    enteredDay = stoi(date.substr(8,2));

    if(enteredYear < 2000 || enteredYear > year) return false;
    if(enteredMonth < 1 || enteredMonth > 12 || enteredMonth > month) return false;
    //if(enteredDay < 1 || enteredDay > 31) return false;

    //maksymalnie ostatni dzien biezacego miesiaca
    if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        if(enteredDay < 1 || enteredDay > 30) return false;
    }
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if(enteredDay < 1 || enteredDay > 31) return false;
    }
    if(month == 2)
    {
        if(enteredYear % 4 != 0)
        {
            if(enteredDay < 1 || enteredDay > 28) return false;
        }
        else
        {
            if(enteredDay < 1 || enteredDay > 2) return false;
        }
    }

    return true;
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
