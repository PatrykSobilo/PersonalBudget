#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>
#include <string>


#include "SuppMethods.h"

using namespace std;

class Date
{
    int year;
    int month;
    int day;

    string convertDateFromIntToString(int year, int month, int day);
    bool isTheTransactionDateFormatCorrect(string &date);

public:
    Date(int year = 2000, int month = 1, int day = 1)
    {
      // domyslnie ustawia date na dzisiejsza
        this->year = stoi(getTodayDate().substr(0,4));
        this->month = stoi(getTodayDate().substr(5,2));
        this->day = stoi(getTodayDate().substr(8,2));
    };

    int getYear();
    int getMonth();
    int getDay();
    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);
    string getTodayDate();
    void generateActualDate();
    string convertTodaysDateToString();
    string todayDate;

    string readSelectedTransactionDate();

};
#endif
