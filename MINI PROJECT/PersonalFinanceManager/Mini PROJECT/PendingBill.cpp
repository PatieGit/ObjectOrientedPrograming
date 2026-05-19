#include "PendingBill.h"
#include <iostream>
using namespace std;

void PendingBill::addBill(string bill) {
    billQueue.push(bill);
    cout << "Bill added to queue.\n";
}

void PendingBill::processBills() {
    while (!billQueue.empty()) {
        cout << "Processing bill: " << billQueue.front() << endl;
        billQueue.pop();
    }
}
