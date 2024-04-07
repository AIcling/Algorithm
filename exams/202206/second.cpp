#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int> x,pair<int,int> y){
    return(x.first<y.first&&x.second<y.second);
}
int n,L,S;
int main(void){
   cin >> n >> L >> S;
   vector<pair<int,int> > trees;
   vector<pair<int,int> > B;
   for(int i=0;i<n;i++){
   int x,y;
   cin >> x >> y;
   pair<int,int> temp = make_pair(x,y);
   trees.push_back(temp);
   }
   sort(trees.begin(),trees.end(),cmp);
    for(int i=S;i>=0;i--){
        for(int j=0;j<=S;j++){
            int xy;
            cin >> xy;
            if(xy==1){
               pair<int,int> temp =  make_pair(i,j);
               B.push_back(temp);
            }
        }
    }
    //
    int res = 0;
    for(int i=0;i<n;i++){
        auto tree = trees[i];
        int x=tree.first,y=tree.second;
        if(x+S>L||y+S>L) continue;
        int flag=1;
        for(int j=i+1;j<n;j++){
            auto t = trees[j];
            int dx=t.first-x,dy=t.second-y;
            if(dx>S||dy>S) break;
            auto cm = make_pair(dx,dy);
            auto it = find(B.begin(),B.end(),cm);
            if(it==B.end()){
                flag=0;
                break;
            }
        }
        if(flag==1) res++;
    }
    cout << res <<endl;
    return 0;
}
