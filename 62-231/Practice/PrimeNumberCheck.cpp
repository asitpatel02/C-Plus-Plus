#include<simplecpp>
using namespace std;

int main() {
	int n, i;
	bool isPrime = true;

	cout << "Enter a positive interger: ";
	cin >> n;

	for ( i = 2; i <= n / 2; i++)
	{
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	}
	if (isPrime)
		cout << n << " is a prime number";
	else
		cout << n << " is not a prime nubmer";

	return 0;
}