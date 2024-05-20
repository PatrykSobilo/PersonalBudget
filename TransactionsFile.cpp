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
