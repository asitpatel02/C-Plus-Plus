#include<iostream>
using namespace std;

int main()
{
	float n1, n2, n3;

	cout << "Enter Three Number: \n";
	cin >> n1 >> n2 >> n3;

	if (n1 >= n2 && n1 >= n3)
	{
		cout << "Largest Number: " << n1;
	}

	if (n2 >= n1 && n2 >= n3)
	{
		cout << "Largest Number: " << n2;
	}

	if (n3 >= n1 && n3 >= n2)
	{
		cout << "Largest Number: " << n3;
	}

	return 0;
}