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

int TransactionManager::currentMonthIncome()
{
    int numberOfIncomeTransactions = incomes.size();
    Date date;
    int currentMonth = date.getMonth();
    int currentYear = date.getYear();
    string dateFromFile = "";
    int monthFromFile = 0;
    int yearFromFile = 0;
    float currentMonthIncome = 0;

    for(int i = 0; i < numberOfIncomeTransactions; i++)
    {
        dateFromFile = incomes[i].getDate();
        monthFromFile = SuppMethods::convStringToInt(dateFromFile.substr(5,2));
        yearFromFile = SuppMethods::convStringToInt(dateFromFile.substr(0,4));
        if(monthFromFile == currentMonth && yearFromFile == currentYear)
        {

            showTransactionData(incomes[i]);
            currentMonthIncome += incomes[i].getAmount();
        }
    }
    cout << endl <<"TOTAL INCOMES IN THE CURRENT MONTH: " << currentMonthIncome << endl;
    return currentMonthIncome;
}

int TransactionManager::currentMonthExpense()
{
    int numberOfExpenseTransactions = expenses.size();
    Date date;
    int currentMonth = date.getMonth();
    int currentYear = date.getYear();
    string dateFromFile = "";
    int monthFromFile = 0;
    int yearFromFile = 0;
    float currentMonthExpense = 0;

    for(int i = 0; i < numberOfExpenseTransactions; i++)
    {
        dateFromFile = expenses[i].getDate();

        monthFromFile = SuppMethods::convStringToInt(dateFromFile.substr(5,2));
        yearFromFile = SuppMethods::convStringToInt(dateFromFile.substr(0,4));
        if(monthFromFile == currentMonth && yearFromFile == currentYear)
        {
            showTransactionData(expenses[i]);
            currentMonthExpense -= expenses[i].getAmount();
        }
    }
    cout << endl <<"TOTAL EXPENSES IN THE CURRENT MONTH: " << currentMonthExpense << endl;
    return currentMonthExpense;
}

void TransactionManager::currentMonthBalance()
{
    int totalIncome = currentMonthIncome();
    int totalExpense = currentMonthExpense();
    int balance = totalIncome + totalExpense;

    system("cls");
    cout << "Current month balance: " << balance << endl;
    cout << "----------------------------" << endl << endl;

    cout << "---Current month incomes---" << endl;
    cout << "---------------------------" << endl;
    currentMonthIncome();
    cout << endl;
    cout << "---Current month expenses---" << endl;
    currentMonthExpense();
    cout << endl;
    cout << "---------------------------" << endl;
    system("pause");
}

float TransactionManager::lastMonthIncome()
{
    int numberOfIncomeTransactions = incomes.size();
    Date date;
    int lastMonth = date.getMonth() - 1;
    int currentYear = date.getYear();
    string dateFromFile = "";
    int monthFromFile = 0;
    int yearFromFile = 0;
    float lastMonthIncome = 0;

    for(int i = 0; i < numberOfIncomeTransactions; i++)
    {
        dateFromFile = incomes[i].getDate();

        monthFromFile = SuppMethods::convStringToInt(dateFromFile.substr(5,2));
        yearFromFile = SuppMethods::convStringToInt(dateFromFile.substr(0,4));
        if(monthFromFile == lastMonth && yearFromFile == currentYear)
        {
            showTransactionData(incomes[i]);
            lastMonthIncome += incomes[i].getAmount();
        }
    }
    cout << endl <<"TOTAL INCOMES IN THE LAST MONTH: " << lastMonthIncome << endl;
    return lastMonthIncome;
}

float TransactionManager::lastMonthExpense()
{
    int numberOfExpensTransactions = expenses.size();
    Date date;
    int lastMonth = date.getMonth() - 1;
    int currentYear = date.getYear();
    string dateFromFile = "";
    int monthFromFile = 0;
    int yearFromFile = 0;
    float lastMonthExpense = 0;

    for(int i = 0; i < numberOfExpensTransactions; i++)
    {
        dateFromFile = expenses[i].getDate();

        monthFromFile = SuppMethods::convStringToInt(dateFromFile.substr(5,2));
        yearFromFile = SuppMethods::convStringToInt(dateFromFile.substr(0,4));
        if(monthFromFile == lastMonth && yearFromFile == currentYear)
        {
            showTransactionData(expenses[i]);
            lastMonthExpense -= expenses[i].getAmount();
        }
    }
    cout << endl <<"TOTAL EXPENSES IN THE LAST MONTH: " << lastMonthExpense << endl;
    return lastMonthExpense;
}

void TransactionManager::lastMonthBalance()
{
    int totalIncome = lastMonthIncome();
    int totalExpense = lastMonthExpense();
    int balance = totalIncome + totalExpense;

    system("cls");
    cout << "Last month balance: " << balance << endl;
    cout << "----------------------------" << endl << endl;

    cout << "---Last month incomes---" << endl;
    cout << "---------------------------" << endl;
    lastMonthIncome();
    cout << endl;
    cout << "---Last month expenses---" << endl;
    lastMonthExpense();
    cout << endl;
    cout << "---------------------------" << endl;
    system("pause");

}
