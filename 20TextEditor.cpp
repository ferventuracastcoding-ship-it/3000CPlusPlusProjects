#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class TextEditor {
private:
    vector<string> lines;

public:
    void addLine() {
        string text;
        cout << "Enter text: ";
        cin.ignore();
        getline(cin, text);
        lines.push_back(text);
    }

    void display() {
        cout << "\n===== Document =====\n";
        for (size_t i = 0; i < lines.size(); i++) {
            cout << i + 1 << ". " << lines[i] << endl;
        }
    }

    void editLine() {
        int line;
        cout << "Line number: ";
        cin >> line;

        if (line < 1 || line > lines.size()) {
            cout << "Invalid line.\n";
            return;
        }

        cin.ignore();

        cout << "New text: ";
        getline(cin, lines[line - 1]);
    }

    void deleteLine() {
        int line;
        cout << "Delete line: ";
        cin >> line;

        if (line < 1 || line > lines.size()) {
            cout << "Invalid line.\n";
            return;
        }

        lines.erase(lines.begin() + line - 1);
    }

    void saveFile() {
        string filename;
        cout << "Filename: ";
        cin >> filename;

        ofstream file(filename);

        for (auto &line : lines)
            file << line << endl;

        file.close();

        cout << "File saved.\n";
    }

    void loadFile() {
        string filename;
        cout << "Filename: ";
        cin >> filename;

        ifstream file(filename);

        if (!file) {
            cout << "Cannot open file.\n";
            return;
        }

        lines.clear();

        string line;

        while (getline(file, line))
            lines.push_back(line);

        file.close();

        cout << "File loaded.\n";
    }
};

int main() {

    TextEditor editor;

    int choice;

    do {
        cout << "\n===== C++ TEXT EDITOR =====\n";
        cout << "1. Add Line\n";
        cout << "2. Display\n";
        cout << "3. Edit Line\n";
        cout << "4. Delete Line\n";
        cout << "5. Save File\n";
        cout << "6. Load File\n";
        cout << "7. Exit\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                editor.addLine();
                break;

            case 2:
                editor.display();
                break;

            case 3:
                editor.editLine();
                break;

            case 4:
                editor.deleteLine();
                break;

            case 5:
                editor.saveFile();
                break;

            case 6:
                editor.loadFile();
                break;

            case 7:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid option.\n";
        }

    } while (choice != 7);

    return 0;
}
