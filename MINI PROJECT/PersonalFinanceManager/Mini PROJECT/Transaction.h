#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
using namespace std;

class Transaction {
private:
    string type;
    string category;
    double amount;

public:
    Transaction(string t, string c, double a);
    string getType();
    string getCategory();
    double getAmount();
    void display();
};
#endif
