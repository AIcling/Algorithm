#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

bool compare(vector<int>& a,vector<int>& b){
    if(a[0]==b[0]) return a[1]<b[1];
    else return a[0]>b[0];
}
int main(void){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int> > land;
    map<int, int> tempLand;    
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        tempLand[first] += second;
    }
    for (const auto& p : tempLand) {
        land.push_back({p.first, p.second});
    }    
    sort(land.begin(),land.end(),compare);
    int num = land.size();
    while(k<=land[num-1][0]){
        if(m>=(land[0][1]+land[1][1])){
            m -= land[0][1]+land[1][1];
            land[0][0]--;
            land[1][0]--;
            sort(land.begin(),land.end(),compare);
        }else if(m>=land[0][1]){
            m -= land[0][1];
            land[0][0]--;
            sort(land.begin(),land.end(),compare);
        }else{
            break;
        }
    }
    cout << land[0][0] << endl;
    return 0;
}