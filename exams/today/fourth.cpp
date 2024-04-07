#pragma GCC optimize(2)
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <utility>
using namespace std;
int c,n,m;
vector<int> w(c+2,0);
void handle(int L,int R){
    if(w[L]<5&&w[R]<5) return;
    int p;
    if(w[L]>=5) p=L;
    else p=R;
    w[p]=0;
    int l=0,r=c+1;
    for(int i=p-1;i>0;i--){
        if(w[i]!=0) {w[i]++;l=i;}
    }
    for(int i=p+1;i<=c;i++){
        if(w[i]!=0) {w[i]++;r=i;}
    }
    handle(l,r);
    return;
}
int main(void){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> c >> m >> n;
    while(m--){
        int x,y;
        cin >> x >> y;
        w[x]=y;
    }
    while(n--){
        int p;
        cin >> p;
        w[p]++; 
        w[p]=0;
        handle(p,p);
        int res=0;
        for(int i=1;i<=c;i++){
            if(w[i]!=0) {res++;}
        }
        cout << res << endl;
    }
    return 0;
}