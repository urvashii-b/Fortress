#include "access_control.h"
#include <unordered_map>
using namespace std;

unordered_map<string, string> userDatabase = {
    {"admin", "password123"},  // Basic mock user DB
    {"user", "userpass"}
};

bool authenticate(const string& username, const string& password) {
    if (userDatabase.find(username) != userDatabase.end() &&
        userDatabase[username] == password) {
        return true;
    }
    return false;
}

bool hasPermission(const string& username, const string& action) {
    // Example: only admin can delete files
    if (username == "admin" || (username == "user" && action != "delete")) {
        return true;
    }
    return false;
}
