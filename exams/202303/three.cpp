#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace  std;
int n,m;
struct user
{
    int DN;
    unordered_map<int,int> attr;
};
vector<user> a;
int expr(string &s,int idx){
    int n = s.size();
    if(s[n-1]!=')'){ 
        int k,v;
        if(s.find(':')!=string::npos){
            sscanf(s.c_str(),"%d:%d",&k,&v);
            auto it = a[idx].attr.find(k);
            if(it!=a[idx].attr.end()&&it->second==v) return 1;
            else return 0;
        }else{
            sscanf(s.c_str(),"%d~%d",&k,&v);
            auto it = a[idx].attr.find(k);
            if(it!=a[idx].attr.end()&&it->second!=v) return 1;
            else return 0;
        }
    }
    int l = s.find_first_of('(');
    int r = s.find_last_of(')');
    int pos=0,sum=1;
    for(int i=1+1;i<=n;i++){  //找到与第一个'('对应的')'
        if(s[i]=='(') sum++;
        else if(s[i]==')'){
            sum--;
            if(sum==0){pos=i;break;}
        }
    }
    string sub1 = s.substr(1+1,pos-l-1);
    string sub2 = s.substr(pos+2,r-pos-2);//l=pos+1
    if((s[0]=='|'))
        return expr(sub1,idx) || expr(sub2,idx); 
    else
        return expr(sub1,idx) && expr(sub2,idx);
     
}
int main(void){
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    a.resize(n+1);
    for(int i=0;i<n;i++){
        int t;
        cin >> a[i].DN >> t;
        while(t--){
            int k,v;
            cin >> k >> v;
            a[i].attr[k]=v;
        }
    }
    cin >> m;
    string str;
    while(m--){
        cin >> str;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(expr(str,i)) res.push_back(a[i].DN);
        }
        sort(res.begin(),res.end());
        for(auto r:res){ cout << r <<" ";}
        cout << endl;
    }
}
