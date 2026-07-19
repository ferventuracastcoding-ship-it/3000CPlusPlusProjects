#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileEncryptor {
private:
    char key;

public:
    FileEncryptor(char k) {
        key = k;
    }

    void process(string inputFile, string outputFile) {
        ifstream in(inputFile, ios::binary);
        ofstream out(outputFile, ios::binary);

        if (!in) {
            cout << "Could not open input file.\n";
            return;
        }

        char c;

        while (in.get(c)) {
            c ^= key;
            out.put(c);
        }

        in.close();
        out.close();

        cout << "Operation completed successfully!\n";
    }
};

int main() {
    string inputFile, outputFile;
    char key;

    cout << "=== File Encryption Tool ===\n";

    cout << "Input file: ";
    cin >> inputFile;

    cout << "Output file: ";
    cin >> outputFile;

    cout << "Encryption Key (single character): ";
    cin >> key;

    FileEncryptor encryptor(key);
    encryptor.process(inputFile, outputFile);

    return 0;
}
