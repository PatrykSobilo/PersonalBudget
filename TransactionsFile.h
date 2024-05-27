#ifndef TRANSACTIONSFILE_H
#define TRANSACTIONSFILE_H
#include <iostream>
#include <string>
#include "Markup.h"
#include "TransactionData.h"
#include "SuppMethods.h"
#include <vector>
using namespace std;

class TransactionsFile
{
    int lastIncomeNumberId;
    const string INCOMES_FILE_NAME;

public:
    TransactionsFile(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName)
    {
        lastIncomeNumberId = 0;
    };
    int getLastIncomeIdNumberFromFile();
    void addIncomeDataToFile(TransactionData newTransactionData);
    vector <TransactionData> loadIncomesFromFile(int loggedUserIdNumber);
};



#endif
