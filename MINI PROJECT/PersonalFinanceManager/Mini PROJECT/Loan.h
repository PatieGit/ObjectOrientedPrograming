#ifndef LOAN_H
#define LOAN_H
#include <string>
using namespace std;

class Loan {
private:
    double loanAmount;
    double interestRate;
    bool approved;

public:
    Loan(double amount, double rate);
    bool checkEligibility(double balance);
    double calculateInterest();
    void displayStatus();
};
#endif
