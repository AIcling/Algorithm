#include <iostream>
#include <vector>
using namespace std;

int n,k;
int main(void){
    cin >> n >> k;
    vector<int> left(n+1,0);
    left[0]=1;
    int res=0;
    while(k--){
        int ll,rr;
        cin >> ll >> rr;
        if(left[rr]==1){
            left[ll] = 1;
        }else{
            left[ll] = 1;
            res++;
        }
    }
    cout << res <<endl;
    return 0;
}