#include "Loan.h"
#include <iostream>
using namespace std;

Loan::Loan(double amount, double rate)
    : loanAmount(amount), interestRate(rate), approved(false) {}

bool Loan::checkEligibility(double balance) {
    approved = (balance > loanAmount / 2);
    return approved;
}

double Loan::calculateInterest() {
    return loanAmount * (interestRate / 100);
}

void Loan::displayStatus() {
    if (approved)
        cout << "Loan approved! Interest: " << calculateInterest() << endl;
    else
        cout << "Loan rejected.\n";
}
