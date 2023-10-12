#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	int num, guess, tries = 0;
	rand();//send random number generator
	num = rand();//randon number between 1 and 100
	cout << "Guess My Number Game\n\n";

	do
	{
		cout << "Enter a guess between 1 and 100 : ";
		cin >> guess;
		tries++;

		if (guess > num)
			cout << "Too High\n\n";

		else if (guess < num)
			cout << "Too Low!\n\n";

		else
			cout << "\nCorrect! You got it in "<< tries<<" guesses!\n";

	} while (guess != num);

	return 0;
}