#include <iostream>
using namespace std;

int main() {
    double centigrade, fahrenheit;
    cout << "Give temperature in Centigrade: ";
    cin >> centigrade;
    fahrenheit = centigrade * 9 / 5 + 32;
    cout << "In Fahrenheit: " << fahrenheit << endl;

    return 0;
}
