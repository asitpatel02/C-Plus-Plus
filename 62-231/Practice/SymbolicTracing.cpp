#include<simplecpp>

main_program{
 int n; cin >> n;
 double I, T, S;
 I=1; T=1; S=1;
 repeat(n){ // Plan for iteration i=1..n
 // I=i, T=1/(i-1)!, S=1/0!+..+1/(i-1)!
 S = S + T; // What is the new value of S?
 T = T/I;
 I = I + 1;
 // Need I=i+1,T=1/i!,S=1/0!+..+1/i!
 }
 cout <<S<< endl;
}
// new S = 1/0! + ..1/(i-1)! + 1/(i-1)! Hence wrong!
