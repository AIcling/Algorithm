#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
const int maxn = 200000;
int n,m,mright=maxn,mleft=0,res=0;
vector<int> genland(vector<int> &a,vector<int> &b){
    vector<int> res(2);
    res[0] = min(a[0],b[0]);
    res[1] = max(a[1],b[1]);
}
int main(void){
    cin >> n >> m;
    vector<vector<int> > land(maxn,vector<int>(maxn,0));
    vector<vector<int> > cars(m);
    for(int i=1;i<=m;i++){
        int left,right;
        cin >> left >> right;
        mleft = min(mleft,left);
        mright = max(mright,right);
        vector<int> temp = {left,right};
        cars.push_back(temp);
    } 
    for(auto car:cars){
        int left=car[0],right=car[1];
        land[left][right] = 1;
        for(int i=1;i<mleft;i++){
            for(int j=1;j<mright;j++){
                auto temp=genlan()
            }
        }
    }
    return 0;
}