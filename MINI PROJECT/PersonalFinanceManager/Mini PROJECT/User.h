#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
private:
    string username;
    string pin;

public:
    User();
    User(string uname, string upin);
    bool login(string uname, string upin);
    void registerUser(string uname, string upin);
    string getUsername();
};
#endif
