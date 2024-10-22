#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H

#include <string>
using namespace std;

bool authenticate(const string& username, const string& password);
bool hasPermission(const string& username, const string& action);

#endif // ACCESS_CONTROL_H
