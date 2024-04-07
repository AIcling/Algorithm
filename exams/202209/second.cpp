#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    int n,x,sum=0;
    cin >> n >> x;
    vector<int> books;
    int count = n;
    while(count--){
        int val;
        cin >> val;
        sum += val;
        books.push_back(val);
    }
    vector<int> dp(sum+1,0);   
    dp[sum]=n;
    for(auto val : books){
        for(int i=x;i<=sum;i++){
           if(dp[i]!=0) {dp[i-val] = dp[i]-1;}
        }
    }
    // dp[sum]=n;
    for(int i=x;i<=sum;i++){
        if(dp[i]!=0){
            cout << i <<endl;
             break;
        }       
    }
    return 0;
}