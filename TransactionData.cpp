#include "TransactionData.h"

int TransactionData::getTransactionNumberId()
{
    return transactionNumberId;
}
int TransactionData::getUserId()
{
    return userId;
}
string TransactionData::getDate()
{
    return date;
}
string TransactionData::getItem()
{
    return item;
}
float TransactionData::getAmount()
{
    return amount;
}

void TransactionData::setTransactionNumberId(int newTransId)
{
    transactionNumberId = newTransId;
}
void  TransactionData::setUserId(int newUserId)
{
    userId = newUserId;
}
void  TransactionData::setDate(string newDate)
{
    date = newDate;
}
void  TransactionData::setItem(string newItem)
{
    item = newItem;
}
void  TransactionData::setAmount(float newAmount)
{
    amount = newAmount;
}
