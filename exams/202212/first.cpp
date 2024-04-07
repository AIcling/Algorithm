#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    int n;
    double k,num,res=0.0;
    cin >> n >> k;
    for(int i=0;i<=n;i++){
        cin >> num;
        res += num*pow((1+k),-i);
    }
    cout << res << endl;
    return 0;
}