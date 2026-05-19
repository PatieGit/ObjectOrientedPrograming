#include "FinanceManager.h"
#include <iostream>
#include <fstream>
using namespace std;

FinanceManager::FinanceManager() : balance(0), budgetLimit(0) {}

void FinanceManager::deposit(double amount, string category) {
    balance += amount;
    Transaction t("Deposit", category, amount);
    transactions.push_back(t);
    undoStack.push(t);
}

void FinanceManager::withdraw(double amount, string category) {
    balance -= amount;
    Transaction t("Withdraw", category, amount);
    transactions.push_back(t);
    undoStack.push(t);
    checkBudget(amount);
}

void FinanceManager::transfer(double amount, string category) {
    balance -= amount;
    Transaction t("Transfer", category, amount);
    transactions.push_back(t);
    undoStack.push(t);
}

void FinanceManager::setBudget(double limit) {
    budgetLimit = limit;
    cout << "Budget set to: " << budgetLimit << endl;
}

void FinanceManager::checkBudget(double amount) {
    if (amount > budgetLimit)
        cout << "⚠️ Budget limit exceeded!\n";
}

void FinanceManager::undoLastTransaction() {
    if (!undoStack.empty()) {
        Transaction last = undoStack.top();
        undoStack.pop();
        if (last.getType() == "Deposit") balance -= last.getAmount();
        else balance += last.getAmount();
        cout << "Last transaction undone.\n";
    } else {
        cout << "No transactions to undo.\n";
    }
}

void FinanceManager::displayTransactions() {
    cout << "\n--- Transaction History ---\n";
    for (auto &t : transactions) t.display();
}

void FinanceManager::saveToFile() {
    ofstream file("finance_data.txt");
    for (auto &t : transactions)
        file << t.getType() << "," << t.getCategory() << "," << t.getAmount() << endl;
    file.close();
    cout << "Data saved.\n";
}

void FinanceManager::loadFromFile() {
    ifstream file("finance_data.txt");
    string type, category;
    double amount;
    while (file >> type >> category >> amount) {
        transactions.push_back(Transaction(type, category, amount));
    }
    file.close();
    cout << "Data loaded.\n";
}

double FinanceManager::getBalance() {
    return balance;
}
