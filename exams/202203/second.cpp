#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 200000;
int n,m,k;
vector<int> diff(maxn+1,0);
int main(void){
    cin >> n >> m >> k;
    while(n--){
        int t,c;
        cin >> t >> c;
        int left = max(1,t-k-c+1);
        int right = t-k;
        if(right>0){
            diff[left]++;
            diff[right+1]--;
        }
    }
    for(int i=1;i<=maxn;i++){
        diff[i] += diff[i-1];
    }
    while(m--){
        int q;
        cin >> q;
        cout << diff[q] <<endl;
    }
}