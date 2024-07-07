#include<simplecpp>

main_program{
int i=1, n; cin >> n;
int nfac=1;
repeat(n){
nfac = nfac * i; // multiplied by 1 to n
i = i + 1; // i goes from 1 to n
}
cout << nfac << endl; // n! printed
}
