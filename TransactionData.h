#ifndef TRANSACTIONDATA_H
#define TRANSACTIONDATA_H
#include <iostream>
#include "Date.h"

using namespace std;

class TransactionData :public Date
{
protected:

    int transactionNumberId;
    int userId;

    string date;
    string item;
    float amount;
public:
    TransactionData(int transactionNumberId = 0, int userId = 0, string date = "", string item = "", float amount = 0)
    {
        this->transactionNumberId = transactionNumberId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    };
    int getTransactionNumberId();
    int getUserId();
    string getDate();
    string getItem();
    float getAmount();

    void setTransactionNumberId(int newTransId);
    void  setUserId(int newUserId);
    void  setDate(string newDate);
    void  setItem(string newItem);
    void  setAmount(float newAmount);

};
#endif
