#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    bool borrowed;

    Book(string t, string a) {
        title = t;
        author = a;
        borrowed = false;
    }
};

int main() {

    vector<Book> library;

    library.push_back(Book("Dune", "Frank Herbert"));
    library.push_back(Book("Foundation", "Isaac Asimov"));
    library.push_back(Book("The Hobbit", "J.R.R. Tolkien"));

    int choice;

    do {

        cout << "\n===== Library =====\n";
        cout << "1. View Books\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch(choice) {

            case 1:

                for (int i = 0; i < library.size(); i++) {

                    cout << i + 1 << ". "
                         << library[i].title
                         << " by "
                         << library[i].author;

                    if (library[i].borrowed)
                        cout << " (Borrowed)";

                    cout << endl;
                }

                break;

            case 2: {

                int num;

                cout << "Book number: ";
                cin >> num;

                if (!library[num - 1].borrowed) {

                    library[num - 1].borrowed = true;

                    cout << "Book borrowed!\n";
                }
                else
                    cout << "Already borrowed.\n";

                break;
            }

            case 3: {

                int num;

                cout << "Book number: ";
                cin >> num;

                library[num - 1].borrowed = false;

                cout << "Book returned!\n";

                break;
            }

        }

    } while(choice != 4);

    return 0;
}
