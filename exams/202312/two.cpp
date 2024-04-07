#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int n;
    cin >> n ;
    while(n--){
        long long number,k,res=1;
        cin>>number>>k;
        for(long long i=2;i<sqrt(number);i++){
            long long tem=0;
            while(number%i==0){
                number = number/i;
                tem++;
            }
            if(tem>=k) res = res * pow(i,tem);
        }
        cout << res << endl;
    }
    return 0;
}