#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Artwork {
public:
    string title;
    string artist;
    string category;
    int year;
};

vector<Artwork> gallery;


// Load artwork from file
void loadGallery() {
    ifstream file("gallery.txt");

    Artwork art;

    while(getline(file, art.title)) {
        getline(file, art.artist);
        getline(file, art.category);
        file >> art.year;
        file.ignore();

        gallery.push_back(art);
    }

    file.close();
}


// Save artwork
void saveGallery() {

    ofstream file("gallery.txt");

    for(auto &art : gallery) {

        file << art.title << endl;
        file << art.artist << endl;
        file << art.category << endl;
        file << art.year << endl;

    }

    file.close();
}


// Add artwork
void addArtwork() {

    Artwork art;

    cin.ignore();

    cout << "\nArtwork Title: ";
    getline(cin, art.title);

    cout << "Artist: ";
    getline(cin, art.artist);

    cout << "Category: ";
    getline(cin, art.category);

    cout << "Year Created: ";
    cin >> art.year;


    gallery.push_back(art);

    saveGallery();

    cout << "\nArtwork Added!\n";
}


// Display gallery
void displayGallery() {

    if(gallery.empty()) {
        cout << "Gallery is empty.\n";
        return;
    }


    cout << "\n===== DIGITAL ART GALLERY =====\n";

    for(int i = 0; i < gallery.size(); i++) {

        cout << "\nArtwork #" << i+1 << endl;
        cout << "Title: " << gallery[i].title << endl;
        cout << "Artist: " << gallery[i].artist << endl;
        cout << "Category: " << gallery[i].category << endl;
        cout << "Year: " << gallery[i].year << endl;

    }
}


// Search artwork
void searchArtwork() {

    cin.ignore();

    string keyword;

    cout << "Search title: ";
    getline(cin, keyword);


    bool found=false;


    for(auto &art : gallery) {

        if(art.title.find(keyword) != string::npos) {

            cout << "\nFound Artwork\n";
            cout << "Title: " << art.title << endl;
            cout << "Artist: " << art.artist << endl;
            cout << "Category: " << art.category << endl;
            cout << "Year: " << art.year << endl;

            found=true;
        }
    }


    if(!found)
        cout << "Artwork not found.\n";

}


// Delete artwork
void deleteArtwork() {

    cin.ignore();

    string title;

    cout << "Enter artwork title to delete: ";
    getline(cin,title);


    auto result = remove_if(
        gallery.begin(),
        gallery.end(),

        [&](Artwork art){

            return art.title == title;

        });


    if(result != gallery.end()) {

        gallery.erase(result,gallery.end());

        saveGallery();

        cout << "Artwork Removed.\n";

    }
    else {

        cout << "Artwork not found.\n";

    }

}



int main(){

    loadGallery();


    int choice;


    do {

        cout << "\n\n==== DIGITAL ART GALLERY ====\n";
        cout << "1. Add Artwork\n";
        cout << "2. View Gallery\n";
        cout << "3. Search Artwork\n";
        cout << "4. Delete Artwork\n";
        cout << "5. Exit\n";

        cout << "Choice: ";
        cin >> choice;


        switch(choice){

            case 1:
                addArtwork();
                break;

            case 2:
                displayGallery();
                break;

            case 3:
                searchArtwork();
                break;

            case 4:
                deleteArtwork();
                break;

            case 5:
                cout<<"Closing Gallery...\n";
                break;

            default:
                cout<<"Invalid option.\n";
        }


    }while(choice != 5);


    return 0;
}
