
// Entry point

#include <iostream>
#include "encryption.h"
#include "access_control.h"
#include "file_manager.h"
#include "logger.h"
using namespace std;

int main() {
    // Initialize the system
    cout << "Welcome to Fortress: Secure File Vault\n";
    
    // Mock user authentication (for now, just for illustration)
    if (authenticate("admin", "password123")) {
        cout << "Authentication successful!\n";
    } else {
        cout << "Authentication failed.\n";
        return 1;
    }

    // Example: Encrypt a file
    string filename = "secret.txt";
    string encrypted_file = "encrypted_secret.bin";
    
    if (encryptFile(filename, encrypted_file)) {
        cout << "File encrypted successfully!\n";
    }

    // Logging file access
    logAccess("admin", filename, "read");
    
    return 0;
}
