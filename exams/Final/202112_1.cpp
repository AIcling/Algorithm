#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,N;

int main(void){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> N;
    vector<int> A(n+1,0);
    vector<int> f(N,0);
    vector<int> stk;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin >> A[i];
        sum += (i-1)*(A[i]-A[i-1]);
    }
    sum+=n*(N-A[n]);
    cout << sum << endl;
    return 0;
}