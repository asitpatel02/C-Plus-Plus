#include<simplecpp>

main_program{

    float nextmark, sum = 0;
    int count = 0;
    while(true){
        cin >> nextmark;
        if(nextmark < 0) break;
        sum += nextmark;
        count++;
        }
    cout <<"Avg: " << sum/count << endl;
}
