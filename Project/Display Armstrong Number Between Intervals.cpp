#include<iostream>
using namespace std;

int main()
{
	int num1, num2, i, num, digit, sum;

	cout << "Enter first Number: ";
	cin >> num1;

	cout << "Enter Second Number";
	cin >> num2;

	cout << "Armstrong numbers betwwen " << num1 << " and " << num2 << " are " << endl;
	for (i = num1;i <= num2; i++)
	{
		sum = 0;
		num = 1;

		for (; num > 0; num /= 10)
		{
			digit = num % 10;
			sum = sum + digit * digit * digit;
		}

		if (sum == i)
		{
			cout << i << endl;
		}

		return 0;
	}
}