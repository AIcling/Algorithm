#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    int N=0,k=0,k_i=0,res =1;
    long long number = 0;
    cin >> N;
    while(N--){
        cin >> number >> k;
        res =1;
        for(int i=2;i<=sqrt(number);i++){
            k_i = 0;
            while(number%i==0){
                number = number/i;
                k_i++;
            }
            if(k_i>=k) res *= pow(i,k_i);
        }
        cout << res << endl;
    }
    return 0;
}