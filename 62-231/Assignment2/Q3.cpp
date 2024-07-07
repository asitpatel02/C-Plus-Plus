#include<simplecpp>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Represents a book.
 * 
 * This struct represents a book and contains information such as the book ID, title, author, and price.
 */
struct Book {
    int bookID;
    string title;
    string author;
    float price;
};

/**
 * Function to input book details.
 * 
 * @param book The Book object to store the details.
 */
void inputBookDetails(Book& book) {
    cout << "Enter Book ID: ";
    cin >> book.bookID;
    cin.ignore(); // Ignore newline character
    cout << "Enter Title: ";
    getline(cin, book.title);
    cout << "Enter Author: ";
    getline(cin, book.author);
    cout << "Enter Price: $";
    cin >> book.price;
}

/**
 * Displays the details of a book.
 * 
 * @param book The book object whose details are to be displayed.
 */
void displayBookDetails(const Book& book) {
    cout << "Book ID: " << book.bookID << endl;
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Price: $" << book.price << endl;
}

/**
 * Searches for a book by its title in the given vector of books.
 * If a book with the specified title is found, its details are displayed.
 * If no book with the specified title is found, a message is printed.
 *
 * @param books The vector of books to search in.
 * @param title The title of the book to search for.
 */
void searchBookByTitle(const vector<Book>& books, const string& title) {
    bool found = false;
    for (const Book& book : books) {
        if (book.title == title) {
            displayBookDetails(book);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book with title \"" << title << "\" not found." << endl;
    }
}

/**
 * @brief The main function of the program.
 * 
 * @return int The exit status of the program.
 */
int main() {
    vector<Book> books;
    char choice;
    do {
        cout << "\nMenu:\n1. Add Book\n2. Search Book by Title\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case '1': {
                Book newBook;
                cout << "\nEnter details for the new book:\n";
                inputBookDetails(newBook);
                books.push_back(newBook);
                break;
            }
            case '2': {
                string title;
                cout << "Enter the title of the book to search: ";
                cin.ignore(); // Ignore newline character
                getline(cin, title);
                searchBookByTitle(books, title);
                break;
            }
            case '3':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '3');

    return 0;
}
