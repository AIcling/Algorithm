#pragma GCC optimize(2)
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>
using namespace std;

string alltolow(string &s){
    string res;
    for(auto a :s){
        char r = tolower(a);
        res+=r;
    }
    return res;
}
int m,n;
int main(void){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> m;
    unordered_set<string> N;
    unordered_set<string> M; //jiao
    unordered_set<string> R; //bing
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        s = alltolow(s);
        N.insert(s);
        R.insert(s);
    }
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        s = alltolow(s);
        auto it = N.find(s);
        if(it!=N.end()) M.insert(s);
        else R.insert(s);        
    }
    cout << M.size() <<"\n"<<R.size() << endl;
    return 0;
}