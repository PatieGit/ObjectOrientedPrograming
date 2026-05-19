#ifndef SAVINGS_H
#define SAVINGS_H
class Savings {
private:
    double savingsBalance;
    double interestRate;

public:
    Savings();
    void addSavings(double amount);
    double calculateInterest();
    void displaySavings();
};
#endif
