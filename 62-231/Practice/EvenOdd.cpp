#include <simplecpp>

bool even(int n) { return (n % 2 == 0); }

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << num << " is " << (even(num) ? "even." : "odd.") << endl;
    return 0;
}
