#ifndef PENDINGBILL_H
#define PENDINGBILL_H
#include <queue>
#include <string>
using namespace std;

class PendingBill {
private:
    queue<string> billQueue;

public:
    void addBill(string bill);
    void processBills();
};
#endif
