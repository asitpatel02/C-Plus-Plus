#include <iostream>
#include<string.h>
using namespace std;
int main() {
    char binary[10] = "10000000";
    cout << "Binary number is " << binary;
    //once complement....
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        if (binary[i] == '0') {
            binary[i] = '1';
        }
        else
            binary[i] = '0';
    }
    cout << "One’s Complement is " << binary << endl;
    // cout<<binary[length-1];
    for (int i = length - 1; i >= 0; i--) {
        // cout<<binary[i];
        if (binary[i] == '0') {
            binary[i] = '1';
            //cout<<binary[i];
            break;
        }
        else {
            binary[i] = '0';
        }
    }
    cout << "Two’s complement is " << binary;
    return 0;
}