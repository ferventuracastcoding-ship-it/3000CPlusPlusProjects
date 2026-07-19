#include <iostream>
#include <string>

using namespace std;

int main() {
    const string correctPassword = "Space2026";
    string password;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Enter password: ";
        cin >> password;

        if (password == correctPassword) {
            cout << "\nAccess Granted!\n";
            cout << "Welcome to the secure system.\n";
            return 0;
        } else {
            attempts--;
            cout << "Incorrect password.\n";

            if (attempts > 0)
                cout << "Attempts remaining: " << attempts << "\n\n";
        }
    }

    cout << "\nAccess Denied. Too many failed attempts.\n";

    return 0;
}
