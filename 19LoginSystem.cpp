#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool registerUser() {
    string username, password;

    cout << "\n=== Register ===\n";
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    ifstream checkFile("users.txt");
    string user, pass;

    while (checkFile >> user >> pass) {
        if (user == username) {
            cout << "\nUsername already exists.\n";
            return false;
        }
    }

    checkFile.close();

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "\nRegistration successful!\n";
    return true;
}

bool loginUser() {
    string username, password;

    cout << "\n=== Login ===\n";
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass) {
        if (user == username && pass == password) {
            cout << "\nLogin successful!\n";
            return true;
        }
    }

    cout << "\nInvalid username or password.\n";
    return false;
}

int main() {

    int choice;

    do {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 3);

    return 0;
}
