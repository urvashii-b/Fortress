#include "file_manager.h"
#include <iostream>
#include <fstream>
using namespace std;

bool deleteFileSecurely(const string& filename) {
    ifstream file(filename, ios::binary);
    
    if (!file) {
        cerr << "File not found!\n";
        return false;
    }

    ofstream ofs(filename, ios::binary | ios::trunc);
    for (int i = 0; i < 3; i++) {
        ofs << string(1024, '\0');  // Overwrite with zeros
    }

    remove(filename.c_str());
    cout << "File securely deleted.\n";
    return true;
}
