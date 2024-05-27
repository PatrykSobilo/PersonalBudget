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
    int lastExpenseNumberId;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    TransactionsFile(string incomesFileName, string expensesFileName) : INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        lastIncomeNumberId = 0;
        lastExpenseNumberId = 0;
    };
    int getLastIncomeIdNumberFromFile();
    int getLastExpenseIdNumberFromFile();
    void addIncomeDataToFile(TransactionData newTransactionData);
    void addExpenseDataToFile(TransactionData newTransactionData);
    vector <TransactionData> loadIncomesFromFile(int loggedUserIdNumber);
    vector <TransactionData> loadExpensesFromFile(int  loggedUserIdNumber);
};



#endif
