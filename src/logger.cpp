#include "logger.h"
#include <fstream>
#include <iostream>
using namespace std;

void logAccess(const string& username, const string& filename, const string& action) {
    ofstream logFile("logs/access.log", ios_base::app);
    if (logFile.is_open()) {
        logFile << username << " accessed " << filename << " for " << action << "\n";
        logFile.close();
    } else {
        cerr << "Unable to open log file.\n";
    }
}
