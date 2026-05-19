#include <iostream>
#include "User.h"
#include "FinanceManager.h"
#include "Loan.h"
#include "Savings.h"
#include "PendingBill.h"
using namespace std;

int main() {
    User user;
    FinanceManager fm;
    Loan loan(3000, 10);   // Example loan object
    Savings savings;
    PendingBill pb;

    string uname, upin;
    cout << "Register username: ";
    cin >> uname;
    cout << "Set PIN: ";
    cin >> upin;
    user.registerUser(uname, upin);

    cout << "\nLogin username: ";
    cin >> uname;
    cout << "Enter PIN: ";
    cin >> upin;

    if (!user.login(uname, upin)) {
        cout << "Invalid login.\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n--- Personal Finance Manager ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Set Budget\n";
        cout << "5. Undo Last Transaction\n";
        cout << "6. Loan Request\n";
        cout << "7. Savings\n";
        cout << "8. Pending Bills\n";
        cout << "9. Show Transactions\n";
        cout << "10. Save & Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            double amt; string cat;
            cout << "Amount: "; cin >> amt;
            cout << "Category: "; cin >> cat;
            fm.deposit(amt, cat);
        }
        else if (choice == 2) {
            double amt; string cat;
            cout << "Amount: "; cin >> amt;
            cout << "Category: "; cin >> cat;
            fm.withdraw(amt, cat);
        }
        else if (choice == 3) {
            double amt; string cat;
            cout << "Amount: "; cin >> amt;
            cout << "Category: "; cin >> cat;
            fm.transfer(amt, cat);
        }
        else if (choice == 4) {
            double limit;
            cout << "Enter budget limit: ";
            cin >> limit;
            fm.setBudget(limit);
        }
        else if (choice == 5) {
            fm.undoLastTransaction();
        }
        else if (choice == 6) {
            if (loan.checkEligibility(fm.getBalance())) {
                loan.displayStatus();
            } else {
                loan.displayStatus();
            }
        }
        else if (choice == 7) {
            double amt;
            cout << "Enter savings amount: ";
            cin >> amt;
            savings.addSavings(amt);
            savings.displaySavings();
        }
        else if (choice == 8) {
            int subChoice;
            cout << "1. Add Bill\n2. Process Bills\nChoice: ";
            cin >> subChoice;
            if (subChoice == 1) {
                string bill;
                cout << "Enter bill name: ";
                cin >> bill;
                pb.addBill(bill);
            } else if (subChoice == 2) {
                pb.processBills();
            }
        }
        else if (choice == 9) {
            fm.displayTransactions();
            cout << "Balance: " << fm.getBalance() << endl;
        }
    } while (choice != 10);

    fm.saveToFile();
    cout << "Exiting system...\n";
    return 0;
}
