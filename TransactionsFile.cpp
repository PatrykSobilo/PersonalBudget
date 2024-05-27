#include "TransactionsFile.h"

vector <TransactionData> TransactionsFile::loadIncomesFromFile(int loggedUserIdNumber)
{
    CMarkup incomesFile;
    TransactionData income;
    vector <TransactionData> incomes;
    int userIdNumberFromFile = 0;
    bool fileExist = incomesFile.Load(INCOMES_FILE_NAME);

    if(fileExist)
    {
        incomesFile.FindElem("Incomes");
        incomesFile.IntoElem();

        while(incomesFile.FindElem("Income"))
        {
            incomesFile.IntoElem();
            incomesFile.FindElem("UserId");
            userIdNumberFromFile = SuppMethods::convStringToInt(incomesFile.GetData());

            if(loggedUserIdNumber == userIdNumberFromFile)
            {
                incomesFile.ResetMainPos();
                incomesFile.FindElem("IncomeId");
                income.setTransactionNumberId(stoi(incomesFile.GetData()));

                incomesFile.FindElem("UserId");
                income.setUserId(stoi(incomesFile.GetData()));

                incomesFile.FindElem("Date");
                income.setDate(incomesFile.GetData());

                incomesFile.FindElem("Item");
                income.setItem(incomesFile.GetData());

                incomesFile.FindElem("Amount");
                income.setAmount(stof(incomesFile.GetData()));

                incomes.push_back(income);
                incomesFile.OutOfElem();
            }
            else incomesFile.OutOfElem();
        }
        return incomes;
    }
}

vector <TransactionData> TransactionsFile::loadExpensesFromFile(int  loggedUserIdNumber)
{
    CMarkup expensesFile;
    TransactionData expens;
    vector <TransactionData> expenses;
    int userIdNumberFromFile = 0;

    bool fileExist = expensesFile.Load(EXPENSES_FILE_NAME);

    if(fileExist)
    {
        expensesFile.FindElem("Expenses");
        expensesFile.IntoElem();

        while(expensesFile.FindElem("Expense"))
        {
            expensesFile.IntoElem();
            expensesFile.FindElem("UserId");
            userIdNumberFromFile = SuppMethods::convStringToInt(expensesFile.GetData());
            if(loggedUserIdNumber == userIdNumberFromFile)
            {
                expensesFile.ResetMainPos();
                expensesFile.FindElem("ExpenseId");
                expens.setTransactionNumberId(stoi(expensesFile.GetData()));

                expensesFile.FindElem("UserId");
                expens.setUserId(stoi(expensesFile.GetData()));

                expensesFile.FindElem("Date");
                expens.setDate(expensesFile.GetData());

                expensesFile.FindElem("Item");
                expens.setItem(expensesFile.GetData());

                expensesFile.FindElem("Amount");
                expens.setAmount(stof(expensesFile.GetData()));

                expenses.push_back(expens);
                expensesFile.OutOfElem();
            }
            else expensesFile.OutOfElem();
        }
        return expenses;
    }
}

void TransactionsFile::addIncomeDataToFile(TransactionData newTransactionData)
{
    CMarkup incomeFile;
    if (!incomeFile.Load("Incomes.xml"))
    {
        incomeFile.AddElem("Incomes");
    }
    else
    {
        incomeFile.FindElem("Incomes");
    }
    incomeFile.IntoElem();
    incomeFile.AddElem("Income");
    incomeFile.IntoElem();
    incomeFile.AddElem("IncomeId", newTransactionData.getTransactionNumberId());
    incomeFile.AddElem("UserId", newTransactionData.getUserId());
    incomeFile.AddElem("Date", newTransactionData.getDate());
    incomeFile.AddElem("Item", newTransactionData.getItem());
    incomeFile.AddElem("Amount", newTransactionData.getAmount());
    incomeFile.Save("Incomes.xml");

}

void TransactionsFile::addExpenseDataToFile(TransactionData newTransactionData)
{
    CMarkup incomeFile;
    if (!incomeFile.Load(EXPENSES_FILE_NAME))
    {
        incomeFile.AddElem("Expenses");
    }
    else
    {
        incomeFile.FindElem("Expenses");
    }
    incomeFile.IntoElem();
    incomeFile.AddElem("Expense");
    incomeFile.IntoElem();
    incomeFile.AddElem("ExpenseId", newTransactionData.getTransactionNumberId());
    incomeFile.AddElem("UserId", newTransactionData.getUserId());
    incomeFile.AddElem("Date", newTransactionData.getDate());
    incomeFile.AddElem("Item", newTransactionData.getItem());
    incomeFile.AddElem("Amount", newTransactionData.getAmount());
    incomeFile.Save(EXPENSES_FILE_NAME);
}

int TransactionsFile::getLastIncomeIdNumberFromFile()
{
    CMarkup file;

    file.Load(INCOMES_FILE_NAME);
    if(file.FindElem("Incomes"))
    {
        file.IntoElem();
        while(file.FindElem("Income"))
        {
            file.IntoElem();
            while(file.FindElem("IncomeId"))
            {
                lastIncomeNumberId = SuppMethods::convStringToInt(file.GetData());
            }
            file.OutOfElem();
        }
        file.OutOfElem();
    }
    return lastIncomeNumberId;
}

int TransactionsFile::getLastExpenseIdNumberFromFile()
{
    CMarkup file;

    file.Load(EXPENSES_FILE_NAME);
    if(file.FindElem("Expenses"))
    {
        file.IntoElem();
        while(file.FindElem("Expense"))
        {
            file.IntoElem();
            while(file.FindElem("ExpenseId"))
            {
                lastExpenseNumberId = SuppMethods::convStringToInt(file.GetData());
            }
            file.OutOfElem();
        }
        file.OutOfElem();
    }
    return lastExpenseNumberId;
}
