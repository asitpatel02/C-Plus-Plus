#include<iostream>
using namespace std;

int main()
{
	char c;
	int Vowel;

	cout << "Enter a Alphabet: ";
	cin >> c;

	Vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

	if (Vowel)
		cout << c << " is a Vowel.";
	else
		cout << c << " is a consonant.";

	return 0;
}