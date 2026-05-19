#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H
#include "Transaction.h"
#include "Loan.h"
#include "Savings.h"
#include "PendingBill.h"
#include <vector>
#include <stack>
#include <string>
using namespace std;

class FinanceManager {
private:
    double balance;
    vector<Transaction> transactions;
    stack<Transaction> undoStack;
    double budgetLimit;

public:
    FinanceManager();
    void deposit(double amount, string category);
    void withdraw(double amount, string category);
    void transfer(double amount, string category);
    void setBudget(double limit);
    void checkBudget(double amount);
    void undoLastTransaction();
    void displayTransactions();
    void saveToFile();
    void loadFromFile();
    double getBalance();
};
#endif
