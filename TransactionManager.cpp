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

void TransactionManager::showTransactionData(TransactionData data)
{
    cout << endl << "Transaction ID: " << data.getTransactionNumberId() << endl;
    cout << "Date:           " << data.getDate() << endl;
    cout << "Item:           " << data.getItem() << endl;
    cout << "Amount:         " << data.getAmount() << endl;
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

float TransactionManager::selectedPeriodIncomes(string beginDate, string endDate)
{
    int selectedPeriodIncomes = 0;
    int incomesNumber = incomes.size();
    int beginD = date.combinedDate(beginDate);
    int endD = date.combinedDate(endDate);
    int fileD = 0;
    string fileDate = "";

    for(int i = 0; i < incomesNumber; i++)
    {
        fileDate = incomes[i].getDate();
        fileD = date.combinedDate(fileDate);
        if(fileD >= beginD && fileD <= endD)
        {
            selectedPeriodIncomes += incomes[i].getAmount();
            showTransactionData(incomes[i]);
        }
    }
    cout << "Selected period incomes: " << selectedPeriodIncomes << endl;
    return selectedPeriodIncomes;
}
