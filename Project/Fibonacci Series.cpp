#include<iostream>
using namespace std;

int main()
{
    int n, t1 = 0, t2 = 1, nextTerm = 0, T1 = 0, T2 = 1, NextTerm = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    //Fibonacci Series up to n number of terms
    
    cout << "\nFibonacci Series up to n number of terms";

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; i++)
    {
        // Prints the first two terms.
        if (i == 1)
        {
            cout << " " << t1;
            continue;
        }
        if (i == 2)
        {
            cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        cout << nextTerm << " ";
    }

    // Fibonacci Sequence Up to a Certain Number
    cout << "\n";
    cout << "\nFibonacci Sequence Up to a Certain Number";

    cout << "Fibonacci Series: " << T1 << ", " << T2 << ", ";

    NextTerm = T1 + T2;

    while (NextTerm <= n)
    {
        cout << NextTerm << ", ";
        T1 = T2;
        T2 = NextTerm;
        NextTerm = T1 + T2;
    }

    return 0;
}