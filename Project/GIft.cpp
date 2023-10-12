#include <iostream>
#include<iomanip>

using namespace std;

int  main() {

	// Delcaring Variables 
	double initialBalance = 10.0; // setting initial balance to 10.0
	double amount;
	cout << fixed;

	// programming loop for 
	while (initialBalance > 0.99)
	{
		cout << "Enter the cost of a song: ";
		cin >> amount;

		if (amount > initialBalance)
		{
			cout << "Your choice is too expensive!!!  Choose another one please!" << endl;
			cout << "Your reaming balance is: " << setprecision(2) << initialBalance << endl;
		}
		else if (amount < 0.99)
		{
			cout << "No song found at that price point. Select another one" << endl;
			cout << "Your remaning balance is: " << setprecision(2) << initialBalance << endl;
		}
		else if (amount <= initialBalance)
		{
			initialBalance = initialBalance - amount;
			cout << "Song purchased for $" << setprecision(2) << amount << "! Enjoy!!!" << endl;
			cout << "Your remaning balance is: " << setprecision(2) << initialBalance << endl;
		}
		else
		{

		}

	}

	cout << "Your balance is $" << setprecision(2) << initialBalance << ". You cannot buy more songs " << endl;
	cout << "Come Again!" << endl;



	return 0;
}