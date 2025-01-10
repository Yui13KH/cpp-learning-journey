#include <iostream>
#include <string>
using namespace std;

enum Rating {
    ONE_STAR,
    TWO_STAR,
    THREE_STAR,
    FOUR_STAR,
    FIVE_STAR
}; // so basically a enum is a labeled integers ? but for making the programmer life easier they can be labeled for better readability and error handeling 

struct Book {
    string name;
    int pages;
    Rating rating;
}; // structs feel like object constructors in  javascript like very close 

struct Library {
    string libraryName;
    string address;
    Book book;
};

int main() {
    Library myLibrary;

    cout << "Enter Library Name: ";  // cout is kinda equivalent to console.log
    getline(cin, myLibrary.libraryName);
    cout << "Enter Library Address: ";
    getline(cin, myLibrary.address);

    cout << "\nEnter details for the book in the library:" << endl;
    cout << "Book Name: ";
    getline(cin, myLibrary.book.name);
    cout << "Number of Pages: ";
    cin >> myLibrary.book.pages; // while cin feels like prompt() 
    cout << "Rating (0: One Star, 1: Two Star, 2: Three Star, 3: Four Star, 4: Five Star): ";
    int ratingInput;
    cin >> ratingInput;
    myLibrary.book.rating = static_cast<Rating>(ratingInput);  // to be honest i dont get this much cuz enums arent really a thing in js but its a type conversion 

    cout << "\nLibrary Details:" << endl;
    cout << "Name: " << myLibrary.libraryName << endl;
    cout << "Address: " << myLibrary.address << endl;

    cout << "Book Details:" << endl;
    cout << "  Name: " << myLibrary.book.name << endl;
    cout << "  Pages: " << myLibrary.book.pages << endl;
    cout << "  Rating: ";
    if (myLibrary.book.rating == ONE_STAR) cout << "One Star";
    if (myLibrary.book.rating == TWO_STAR) cout << "Two Star";
    if (myLibrary.book.rating == THREE_STAR) cout << "Three Star";
    if (myLibrary.book.rating == FOUR_STAR) cout << "Four Star";
    if (myLibrary.book.rating == FIVE_STAR) cout << "Five Star";
    cout << endl;

    return 0;
}

