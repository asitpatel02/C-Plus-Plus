#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <conio.h> 

using namespace std;

/**
 * @brief Represents a log entry containing transaction details and timestamp.
 */
struct LogEntry {
    string transaction; /**< The transaction details. */
    string timestamp; /**< The timestamp of the log entry. */
};


/**
 * Logs a transaction with the current timestamp.
 *
 * @param log The vector of LogEntry objects to store the transaction.
 * @param transaction The transaction to be logged.
 */
void logTransaction(vector<LogEntry>& log, const string& transaction) {
    time_t now = time(nullptr);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    log.push_back({transaction, timestamp});
}

/**
 * Writes the log entries to a file.
 *
 * @param filename The name of the file to write the log entries to.
 * @param log The vector of LogEntry objects representing the log entries.
 */
void writeLog(const string& filename, const vector<LogEntry>& log) {
    ofstream file(filename, ios::app); // Append mode
    if (!file.is_open()) {
        cout << "Error: Unable to open log file " << filename << " for writing" << endl;
        return;
    }

    for (const LogEntry& entry : log) {
        file << entry.timestamp << " - " << entry.transaction << endl;
    }

    file.close();
}

/**
 * @brief Represents a library item.
 *
 * This struct represents a library item with various properties such as title, author, genre, barcode, availability, reservation status, and dates for reservation, check-out, and check-in.
 */
struct LibraryItem {
    string title;
    string author;
    string genre;
    string barcode;
    bool available;
    bool reserved;
    string reservationDate;
    string checkOutDate;
    string checkInDate;
};

/**
 * Reads a database file and returns a vector of LibraryItem objects.
 *
 * @param filename The path to the database file.
 * @return A vector of LibraryItem objects read from the database file.
 */
vector<LibraryItem> readDatabase(const string& filename) {
    vector<LibraryItem> database;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open database file " << filename << endl;
        return database;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string title, author, genre, barcode, availability, reserved, reservationDate, checkOutDate, checkInDate;
        getline(iss, title, ',');
        getline(iss, author, ',');
        getline(iss, genre, ',');
        getline(iss, barcode, ',');
        getline(iss, availability, ',');
        getline(iss, reserved, ',');
        getline(iss, reservationDate, ',');
        getline(iss, checkOutDate, ',');
        getline(iss, checkInDate, ',');
        LibraryItem item;
        item.title = title;
        item.author = author;
        item.genre = genre;
        item.barcode = barcode;
        item.available = (availability == "Yes");
        item.reserved = (reserved == "Yes");
        item.reservationDate = reservationDate;
        item.checkOutDate = checkOutDate;
        item.checkInDate = checkInDate;
        database.push_back(item);
    }

    file.close();
    return database;
}

/**
 * Writes the library database to a file.
 *
 * @param filename The name of the file to write the database to.
 * @param database The vector of LibraryItem objects representing the database.
 */
void writeDatabase(const string& filename, const vector<LibraryItem>& database) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open database file " << filename << " for writing" << endl;
        return;
    }

    for (const LibraryItem& item : database) {
        file << item.title << ',' << item.author << ',' << item.genre << ','
             << item.barcode << ',' << (item.available ? "Yes" : "No") << ','
             << (item.reserved ? "Yes" : "No") << ',' << item.reservationDate << ','
             << item.checkOutDate << ',' << item.checkInDate << endl;
    }

    file.close();
}

/**
 * Adds a new book to the library database.
 *
 * @param database The vector of LibraryItem objects representing the library database.
 * @param log The vector of LogEntry objects representing the log of library transactions.
 */
void addBook(vector<LibraryItem>& database, vector<LogEntry>& log) {
    LibraryItem newItem;
    cout << "Enter book details:\n";
    cout << "Title: ";
    cin.ignore();
    getline(cin, newItem.title);
    cout << "Author: ";
    getline(cin, newItem.author);
    cout << "Genre: ";
    getline(cin, newItem.genre);
    cout << "Barcode: ";
    cin >> newItem.barcode;
    newItem.available = true;
    newItem.reserved = false;
    newItem.reservationDate = "";
    newItem.checkOutDate = "";
    newItem.checkInDate = "";
    database.push_back(newItem);
    logTransaction(log, "Added book: " + newItem.title);
    cout << newItem.title <<"Book added successfully!\n";
}

/**
 * Searches for books in the database that match the given keyword.
 *
 * @param database The vector of LibraryItem objects representing the database.
 * @param keyword The string representing the keyword to search for.
 * @return A vector of LibraryItem pointers containing the matching books.
 */
vector<LibraryItem*> searchBooks(const vector<LibraryItem>& database, const string& keyword) {
    vector<LibraryItem*> results;
    for (const LibraryItem& item : database) {
        if (item.title.find(keyword) != string::npos) {
            results.push_back(const_cast<LibraryItem*>(&item)); // Temporary workaround to return a non-const pointer
        }
    }
    return results;
}

/**
 * Displays the details of a LibraryItem.
 *
 * @param item The LibraryItem to display the details of.
 */
void displayBookDetails(const LibraryItem& item) {
    cout << "Title: " << item.title << endl;
    cout << "Author: " << item.author << endl;
    cout << "Genre: " << item.genre << endl;
    cout << "Barcode: " << item.barcode << endl;
    cout << "Availability: " << (item.available ? "Yes" : "No") << endl;
    cout << "Reserved: " << (item.reserved ? "Yes" : "No") << endl;
    if (item.reserved) {
        cout << "Reservation Date: " << item.reservationDate << endl;
    }
    if (!item.available) {
        cout << "Check-Out Date: " << item.checkOutDate << endl;
    }
    if (!item.checkInDate.empty()) {
        cout << "Check-In Date: " << item.checkInDate << endl;
    }
}

/**
 * Reserves a book in the library database.
 *
 * This function searches for a book with the specified barcode in the database and reserves it if it is available.
 * If the book is already reserved or not found in the database, appropriate error messages are displayed.
 *
 * @param database The vector of LibraryItem objects representing the library database.
 * @param log The vector of LogEntry objects representing the log of library transactions.
 * @param barcode The barcode of the book to be reserved.
 */
void reserveBook(vector<LibraryItem>& database, vector<LogEntry>& log, const string& barcode) {
    auto it = find_if(database.begin(), database.end(), [&](const LibraryItem& item) {
        return item.barcode == barcode;
    });
    if (it != database.end()) {
        if (!it->available) {
            cout << "This book is not available for reservation.\n";
        } else if (it->reserved) {
            cout << "This book is already reserved.\n";
        } else {
            it->reserved = true;
            // Get current date and time
            time_t now = time(nullptr);
            tm* date = localtime(&now);
            // Add 2 weeks (14 days) to the current date
            date->tm_mday += 14;
            mktime(date); // Normalize the date
            char buffer[80];
            strftime(buffer, 80, "%Y-%m-%d", date);
            it->reservationDate = buffer;
            logTransaction(log, "Reserved book: " + it->barcode);
            it->available = false; // Change availability status to "No"
            cout << "Book reserved successfully!\n";
        }
    } else {
        cout << "Book not found in the database.\n";
    }
}

/**
 * @brief Unreserves a book in the library database.
 *
 * This function searches for a book with the specified barcode in the database and unreserves it if it is currently reserved.
 * If the book is successfully unreserved, a log entry is added and a success message is displayed.
 * If the book is not found in the database, an error message is displayed.
 * If the book is not currently reserved, a message indicating that the book is not reserved is displayed.
 *
 * @param database The vector of LibraryItem objects representing the library database.
 * @param log The vector of LogEntry objects representing the log of transactions.
 * @param barcode The barcode of the book to be unreserved.
 */
void unreserveBook(vector<LibraryItem>& database, vector<LogEntry>& log, const string& barcode) {
    auto it = find_if(database.begin(), database.end(), [&](const LibraryItem& item) {
        return item.barcode == barcode;
    });
    if (it != database.end()) {
        if (!it->reserved) {
            cout << "This book is not reserved.\n";
        } else {
            it->reserved = false;
            it->reservationDate = "";
            logTransaction(log, "Unreserved book: " + it->barcode);
            cout << "Book unreserved successfully!\n";
        }
    } else {
        cout << "Book not found in the database.\n";
    }
}

/**
 * Updates the availability status of a book in the library database.
 *
 * @param database The vector of LibraryItem objects representing the library database.
 * @param log The vector of LogEntry objects representing the log of transactions.
 * @param barcode The barcode of the book to update.
 * @param status The new availability status of the book.
 */
void updateAvailability(vector<LibraryItem>& database, vector<LogEntry>& log, const string& barcode, bool status) {
    auto it = find_if(database.begin(), database.end(), [&](const LibraryItem& item) {
        return item.barcode == barcode;
    });
    if (it != database.end()) {
        it->available = status;
        logTransaction(log, "Updated availability status of book: " + it->barcode + " to " + (status ? "available" : "unavailable"));
        cout << "Availability status updated successfully!\n";
    } else {
        cout << "Book not found in the database.\n";
    }
}

/**
 * @brief Checks out a book from the library database.
 *
 * This function searches for a book with the specified barcode in the library database.
 * If the book is found and is available for checkout, it updates the availability status,
 * sets the checkout date, logs the transaction, and displays a success message.
 * If the book is not available or is reserved, appropriate error messages are displayed.
 * If the book is not found in the database, a message indicating the same is displayed.
 *
 * @param database The vector of LibraryItem objects representing the library database.
 * @param log The vector of LogEntry objects representing the transaction log.
 * @param barcode The barcode of the book to be checked out.
 */
void checkOutBook(vector<LibraryItem>& database, vector<LogEntry>& log, const string& barcode) {
    auto it = find_if(database.begin(), database.end(), [&](const LibraryItem& item) {
        return item.barcode == barcode;
    });
    if (it != database.end()) {
        if (!it->available) {
            cout << "This book is not available for checkout.\n";
        } else if (it->reserved) {
            cout << "This book is reserved and cannot be checked out.\n";
        } else {
            it->available = false; // Change availability status to "No"
            // Get current date and time
            time_t now = time(nullptr);
            char buffer[80];
            strftime(buffer, 80, "%Y-%m-%d", localtime(&now));
            it->checkOutDate = buffer;
            logTransaction(log, "Checked out book: " + it->barcode);
            cout << "Book checked out successfully!\n";
        }
    } else {
        cout << "Book not found in the database.\n";
    }
}

/**
 * @brief Checks in a book in the library database.
 *
 * This function searches for a book with the specified barcode in the library database.
 * If the book is found and it is currently checked out, it updates the availability status to "Yes"
 * and records the check-in date. It also logs the transaction and displays a success message.
 * If the book is already checked in or not found in the database, an appropriate message is displayed.
 *
 * @param database The vector of LibraryItem objects representing the library database.
 * @param log The vector of LogEntry objects representing the transaction log.
 * @param barcode The barcode of the book to be checked in.
 */
void checkInBook(vector<LibraryItem>& database, vector<LogEntry>& log, const string& barcode) {
    auto it = find_if(database.begin(), database.end(), [&](const LibraryItem& item) {
        return item.barcode == barcode;
    });
    if (it != database.end()) {
        if (it->available) {
            cout << "This book is already checked in.\n";
        } else {
            it->available = true; // Change availability status to "Yes"
            // Get current date and time
            time_t now = time(nullptr);
            char buffer[80];
            strftime(buffer, 80, "%Y-%m-%d", localtime(&now));
            it->checkInDate = buffer;
            logTransaction(log, "Checked in book: " + it->barcode);
            cout << "Book checked in successfully!\n";
        }
    } else {
        cout << "Book not found in the database.\n";
    }
}

/**
 * Reads a user database from a file and returns it as a vector of pairs.
 * Each pair contains a username and a password.
 *
 * @param filename The name of the file to read the user database from.
 * @return A vector of pairs representing the user database.
 *         Each pair contains a username and a password.
 */
vector<pair<string, string>> readUserDatabase(const string& filename) {
    vector<pair<string, string>> userDatabase;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open user database file " << filename << endl;
        return userDatabase;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string username, password;
        getline(iss, username, ',');
        getline(iss, password, ',');
        userDatabase.push_back({username, password});
    }

    file.close();
    return userDatabase;
}

/**
 * Authenticates a user by checking if the provided username and password match any entry in the user database.
 *
 * @param username The username to authenticate.
 * @param password The password to authenticate.
 * @param userDatabase The database containing the usernames and passwords of registered users.
 * @return True if the username and password match an entry in the user database, false otherwise.
 */
bool authenticateUser(const string& username, const string& password, const vector<pair<string, string>>& userDatabase) {
    for (const auto& user : userDatabase) {
        if (user.first == username && user.second == password) {
            return true;
        }
    }
    return false;
}

/**
 * @brief The main function of the Library Management System.
 *
 * This function is responsible for the execution of the Library Management System.
 * It prompts the user to log in and provides a menu of options to perform various operations on the library database.
 * The function reads the library database, user database, and transaction log from files.
 * It also writes the updated library database and transaction log back to files before exiting.
 *
 * @return int The exit status of the program.
 */
int main() {
    string filename = "library_database.csv";
    string userFilename = "user_database.csv";
    string logFilename = "transaction_log.txt";
    vector<LibraryItem> database = readDatabase(filename);
    vector<pair<string, string>> userDatabase = readUserDatabase(userFilename);
    vector<LogEntry> log;

    string username, password;
    cout << "Welcome to the Library Management System!\n";
    cout << "Please log in to continue.\n";

    bool loggedIn = false;

    while(!loggedIn) {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        // Hide the password
        char ch;
        password = "";
        while ((ch = _getch()) != '\r') { // '\r' is the Enter key
            if (ch == '\b') { // Backspace character
                if (password.length() > 0) {
                    password.pop_back();
                    cout << "\b \b"; // Erase the character from console
                }
            } else {
                password += ch;
                cout << '*'; // Print '*' instead of actual characters
            }
        }

        cout << endl;

        //authenticate user
        if (authenticateUser(username, password, userDatabase)) {
            loggedIn = true;
            logTransaction(log, "User logged in: " + username);
            cout << "Login successful!\n";
        } else {
            cout << "Invalid username or password. Please try again.\n";
        }
    }

    int option;
    do {
        cout << "\nOptions:\n";
        cout << "1. Add a book\n";
        cout << "2. Find a book by title\n";
        cout << "3. Check book details by Barcode\n";
        cout << "4. Reserve a book\n";
        cout << "5. Unreserve a book\n";
        cout << "6. Update availability status\n";
        cout << "7. Check out a book\n";
        cout << "8. Check in a book\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                addBook(database, log);
                break;
            case 2: {
                string keyword;
                cout << "Enter the title of the book: ";
                cin.ignore();
                getline(cin, keyword);
                vector<LibraryItem*> searchResults = searchBooks(database, keyword);
                if (searchResults.empty()) {
                    cout << "No book found with that title.\n";
                } else {
                    cout << "Search Results:\n";
                    for (LibraryItem* item : searchResults) {
                        displayBookDetails(*item);
                    }
                }
                break;
            }
            case 3: {
                string barcode;
                cout << "Enter the barcode of the book you want to check details for: ";
                cin >> barcode;
                auto it = find_if(database.begin(), database.end(), [&](const LibraryItem& item) {
                    return item.barcode == barcode;
                });
                if (it != database.end()) {
                    displayBookDetails(*it);
                } else {
                    cout << "Book not found in the database.\n";
                }
                break;
            }

            case 4: {
                string barcode;
                cout << "Enter the barcode of the book you want to reserve: ";
                cin >> barcode;
                reserveBook(database, log, barcode);
                break;
            }
            case 5: {
                string barcode;
                cout << "Enter the barcode of the book you want to unreserve: ";
                cin >> barcode;
                unreserveBook(database, log, barcode);
                break;
            }
            case 6: {
                string barcode;
                char choice;
                cout << "Enter the barcode of the book you want to update availability for: ";
                cin >> barcode;
                cout << "Set availability (Y/N): ";
                cin >> choice;
                bool status = (toupper(choice) == 'Y') ? true : false;
                updateAvailability(database, log, barcode, status);
                break;
            }
            case 7: {
                string barcode;
                cout << "Enter the barcode of the book you want to check out: ";
                cin >> barcode;
                checkOutBook(database, log, barcode);
                break;
            }
            case 8: {
                string barcode;
                cout << "Enter the barcode of the book you want to check in: ";
                cin >> barcode;
                checkInBook(database, log, barcode);
                break;
            }
            case 9:
                logTransaction(log, "User logged out: " + username);
                cout << "Exiting the program. Goodbye! " << username << endl;
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (option != 9);

    writeDatabase(filename, database);
    writeLog(logFilename, log);

    return 0;
}
