#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include <iostream>

#include <vector>
#include "SuppMethods.h"
#include "TransactionsFile.h"
#include "TransactionData.h"
using namespace std;

class TransactionManager
{

    vector <TransactionData> incomes;

    TransactionsFile transactionsFile;

    const int LOGGED_USER_NUMBER_ID;
    Date date;

    TransactionData enterNewIncomeData();
    int getNewIncomeIdNumber();
    void showTransactionData(TransactionData data);
    int currentMonthIncome();
    float lastMonthIncome();

    //float selectedPeriodIncomes(string beginDate,string endDate);

public:
    TransactionManager(int loggedUserIdNumber, string incomesFileName) : LOGGED_USER_NUMBER_ID(loggedUserIdNumber), transactionsFile(incomesFileName)
    {
        incomes = transactionsFile.loadIncomesFromFile(LOGGED_USER_NUMBER_ID);
    };
    void addIncome();
};



#endif
