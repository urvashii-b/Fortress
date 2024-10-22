#include "encryption.h"
#include <openssl/aes.h>
#include <fstream>
#include <iostream>
using namespace std;

const unsigned char key[16] = "simpleencryption";  // AES requires a 16-byte key

bool encryptFile(const string& inputFile, const string& outputFile) {
    ifstream ifs(inputFile, ios::binary);
    ofstream ofs(outputFile, ios::binary);
    
    if (!ifs || !ofs) {
        cerr << "File error\n";
        return false;
    }

    unsigned char buffer[16];
    unsigned char encrypted[16];

    AES_KEY encryptKey;
    AES_set_encrypt_key(key, 128, &encryptKey);
    
    while (ifs.read((char*)buffer, 16)) {
        AES_encrypt(buffer, encrypted, &encryptKey);
        ofs.write((char*)encrypted, 16);
    }

    return true;
}

bool decryptFile(const string& inputFile, const string& outputFile) {
    ifstream ifs(inputFile, ios::binary);
    ofstream ofs(outputFile, ios::binary);
    
    if (!ifs || !ofs) {
        cerr << "File error\n";
        return false;
    }

    unsigned char buffer[16];
    unsigned char decrypted[16];

    AES_KEY decryptKey;
    AES_set_decrypt_key(key, 128, &decryptKey);
    
    while (ifs.read((char*)buffer, 16)) {
        AES_decrypt(buffer, decrypted, &decryptKey);
        ofs.write((char*)decrypted, 16);
    }

    return true;
}
