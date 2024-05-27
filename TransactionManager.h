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
    vector <TransactionData> expenses;

    TransactionsFile transactionsFile;

    const int LOGGED_USER_NUMBER_ID;
    Date date;

    TransactionData enterNewIncomeData();
    TransactionData enterNewExpenseData();
    int getNewIncomeIdNumber();
    int getNewExpenseIdNumber();
    void showTransactionData(TransactionData data);
    int currentMonthIncome();
    int currentMonthExpense();
    float lastMonthIncome();
    float lastMonthExpense();

    float selectedPeriodIncomes(string beginDate,string endDate);
    float selectedPeriodExpenses(string beginDate,string endDate);
    void showSelectedPeriodBlance(string beginDate, string endDate);

public:
    TransactionManager(int loggedUserIdNumber, string incomesFileName, string expensesFileName) : LOGGED_USER_NUMBER_ID(loggedUserIdNumber), transactionsFile(incomesFileName, expensesFileName)
    {
        incomes = transactionsFile.loadIncomesFromFile(LOGGED_USER_NUMBER_ID);
        expenses = transactionsFile.loadExpensesFromFile(LOGGED_USER_NUMBER_ID);
    };
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedPeriodBalance();
};



#endif
