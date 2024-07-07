#include<simplecpp>

main_program{
int n; cin >> n;
double I, T, S;
I=1; T=1; S=1; //Implement plan for iteration 1
repeat(n){ // Plan for iteration i=1..n
// I=i, T=1/(i-1)!, S=1/0!+..+1/(i-1)!
T = T/I; // Now T = 1/i!
S = S + T; // Now S = 1/0!+..+1/i!
I = I + 1; // Now I = i+1
// Need I=i+1,T=1/i!,S=1/0!+..+1/i!
}
cout <<S<< endl;
}
