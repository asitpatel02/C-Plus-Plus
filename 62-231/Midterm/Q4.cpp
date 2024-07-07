#include <simplecpp>
#include <string>
#include <algorithm>

bool isPalindrome(const string& str) {
    string copy = str;
    // Remove spaces and punctuation
    copy.erase(remove_if(copy.begin(), copy.end(), [](char c) {
        return isspace(c) || ispunct(c);
    }), copy.end());

    // Convert to lowercase
    transform(copy.begin(), copy.end(), copy.begin(), [](char c) {
        return tolower(c);
    });

    // Check if the reversed string is equal to the original string
    string reversed = copy;
    reverse(reversed.begin(), reversed.end());
    return copy == reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
