#include "User.h"
#include <iostream>
using namespace std;

User::User() {}
User::User(string uname, string upin) : username(uname), pin(upin) {}

bool User::login(string uname, string upin) {
    return (uname == username && upin == pin);
}

void User::registerUser(string uname, string upin) {
    username = uname;
    pin = upin;
    cout << "User registered successfully!\n";
}

string User::getUsername() {
    return username;
}
