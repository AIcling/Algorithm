#include <iostream>
using namespace std;
int main(void){
    int n;
    long long m;
    cin >> n >> m;
    long long c[n],a[n+1],b[n+1];
    long long sum[n]={0};
    c[0]=1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i<n) c[i] = a[i]*c[i-1];
    }
    for(int i=1;i<n;i++){
        b[i] = (m%c[i]-sum[i-1])/c[i-1];
        sum[i] = c[i-1]*b[i];
        cout << b[i] << " ";
    }
    b[n] = (m-sum[6])/c[n-1];
    cout << b[n] << endl;
    return 0;
}