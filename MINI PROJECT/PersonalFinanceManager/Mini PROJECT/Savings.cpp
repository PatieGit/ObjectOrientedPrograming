#include "Savings.h"
#include <iostream>
using namespace std;

Savings::Savings() : savingsBalance(0), interestRate(5.0) {}

void Savings::addSavings(double amount) {
    savingsBalance += amount;
}

double Savings::calculateInterest() {
    return savingsBalance * (interestRate / 100);
}

void Savings::displaySavings() {
    cout << "Savings Balance: " << savingsBalance
         << " | Interest: " << calculateInterest() << endl;
}
