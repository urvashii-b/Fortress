#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
using namespace std;

bool encryptFile(const string& inputFile, const string& outputFile);
bool decryptFile(const string& inputFile, const string& outputFile);

#endif // ENCRYPTION_H
