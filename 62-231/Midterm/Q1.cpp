#include <simplecpp>

int main() {
    for (int i = 1; i <= 30; i++) {
        if (i % 3 == 0 && i % 4 == 0) {
            cout << "FizzBuzz" << endl;
        } else if (i % 3 == 0) {
            cout << "Fizz" << endl;
        } else if (i % 4 == 0) {
            cout << "Buzz" << endl;
        } else {
            cout << i << endl;
        }
    }
    return 0;
}
