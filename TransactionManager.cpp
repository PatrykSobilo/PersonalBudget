#include "TransactionManager.h"

void TransactionManager::addIncome()
{
    TransactionData newTransactionData = enterNewIncomeData();
    incomes.push_back(newTransactionData);
    transactionsFile.addIncomeDataToFile(newTransactionData);
}

TransactionData TransactionManager::enterNewIncomeData()
{
    TransactionData newTransactionData;
    newTransactionData.setTransactionNumberId(getNewIncomeIdNumber());
    newTransactionData.setUserId(LOGGED_USER_NUMBER_ID);
    newTransactionData.setDate(date.readSelectedTransactionDate());

    cout << "Enter item: ";
    newTransactionData.setItem(SuppMethods::readLine());

    cout << "Enter amount: ";
    newTransactionData.setAmount(SuppMethods::readFloat());
    return newTransactionData;
}

int TransactionManager::getNewIncomeIdNumber()
{
    return transactionsFile.getLastIncomeIdNumberFromFile() + 1;
}

int TransactionManager::getNewExpenseIdNumber()
{
    return transactionsFile.getLastExpenseIdNumberFromFile() + 1;
}
void TransactionManager::addExpense()
{
    TransactionData newTransactionData = enterNewExpenseData();
    expenses.push_back(newTransactionData);
    transactionsFile.addExpenseDataToFile(newTransactionData);;
}

TransactionData TransactionManager::enterNewExpenseData()
{
    TransactionData newTransactionData;
    newTransactionData.setTransactionNumberId(getNewExpenseIdNumber());
    newTransactionData.setUserId(LOGGED_USER_NUMBER_ID);
    newTransactionData.setDate(date.readSelectedTransactionDate());

    cout << "Enter item: ";
    newTransactionData.setItem(SuppMethods::readLine());

    cout << "Enter amount: ";
    newTransactionData.setAmount(SuppMethods::readFloat());
    return newTransactionData;
}

void TransactionManager::showTransactionData(TransactionData data)
{
    cout << endl << "Transaction ID: " << data.getTransactionNumberId() << endl;
    cout << "Date:           " << data.getDate() << endl;
    cout << "Item:           " << data.getItem() << endl;
    cout << "Amount:         " << data.getAmount() << endl;
}
