#include "Transaction.h"
#include <iostream>
using namespace std;

Transaction::Transaction(string t, string c, double a)
    : type(t), category(c), amount(a) {}

string Transaction::getType() { return type; }
string Transaction::getCategory() { return category; }
double Transaction::getAmount() { return amount; }

void Transaction::display() {
    cout << type << " | " << category << " | " << amount << endl;
}
