#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;
};

vector<Contact> contacts;

void loadContacts() {
    ifstream file("contacts.txt");
    Contact c;

    while (getline(file, c.name)) {
        getline(file, c.phone);
        getline(file, c.email);
        contacts.push_back(c);
    }

    file.close();
}

void saveContacts() {
    ofstream file("contacts.txt");

    for (const auto& c : contacts) {
        file << c.name << endl;
        file << c.phone << endl;
        file << c.email << endl;
    }

    file.close();
}

void addContact() {
    Contact c;

    cin.ignore();

    cout << "Name: ";
    getline(cin, c.name);

    cout << "Phone: ";
    getline(cin, c.phone);

    cout << "Email: ";
    getline(cin, c.email);

    contacts.push_back(c);
    saveContacts();

    cout << "\nContact Added!\n";
}

void viewContacts() {
    if (contacts.empty()) {
        cout << "No contacts.\n";
        return;
    }

    for (size_t i = 0; i < contacts.size(); i++) {
        cout << "\nContact #" << i + 1 << endl;
        cout << "Name : " << contacts[i].name << endl;
        cout << "Phone: " << contacts[i].phone << endl;
        cout << "Email: " << contacts[i].email << endl;
    }
}

void searchContact() {
    cin.ignore();

    string search;
    cout << "Enter name: ";
    getline(cin, search);

    bool found = false;

    for (auto &c : contacts) {
        if (c.name.find(search) != string::npos) {
            cout << "\nFound\n";
            cout << c.name << endl;
            cout << c.phone << endl;
            cout << c.email << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Contact not found.\n";
}

void deleteContact() {
    cin.ignore();

    string name;
    cout << "Delete contact name: ";
    getline(cin, name);

    auto it = remove_if(contacts.begin(), contacts.end(),
        [&](Contact c) {
            return c.name == name;
        });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        saveContacts();
        cout << "Deleted.\n";
    } else {
        cout << "Not found.\n";
    }
}

int main() {

    loadContacts();

    int choice;

    do {
        cout << "\n==== PHONE BOOK ====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
