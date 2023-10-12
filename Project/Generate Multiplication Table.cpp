#include<iostream>
using namespace std;

int main()
{
	int n;

	cout << "Enter a positive integer: ";
	cin >> n;

	for (int i = 1; i <= 20; ++i)
	{
		cout << n << " * " << i << " = " << n * i << endl;
	}

	return 0;
}