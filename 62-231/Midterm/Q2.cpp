#include <simplecpp>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter a number: ";
    if (!(cin >> n)) {
        cout << "Invalid input. Please enter an integer." << endl;
        return 0;
    }
    if (n < 2) {
        cout << "There are no prime numbers up to " << n << endl;
        return 0;
    }
    cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
