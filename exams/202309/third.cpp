#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int mod=1000000007;
int calres(long long res){
    int out=0;
    if(res>=0) out = res%mod;
    else{
        while(res<0){
            res+=mod;
        }
        out = res-mod;
    }
    return out;
}
int main(void){
    int n,m;
    cin >> n >> m;
    map<int,int> Xn;
    if(n==1){
        string exp;
        int flag=-1,mul=0;
        cin.ignore();
        getline(cin,exp);
        int expnum = exp.size();
        if(expnum==2&&exp[0]=='x') flag=0;
        else if(exp[4]=='*'&&exp[0]=='x'&&exp[2]=='x') flag=1;
        else if(exp[4]=='+'&&exp[0]=='x'&&exp[2]=='x')flag=2;
        else if(exp[4]=='-'&&exp[0]=='x'&&exp[2]=='x')flag=-1;
        else if(count(exp.begin(),exp.end(),'x')==1){
            if(exp[expnum-1]=='+'||exp[expnum-1]=='-') flag=0;
            else if(exp[0]=='x'&&exp[expnum-1]=='*'){
                flag=3;
                if(exp[2]!='-') mul = stoi(exp.substr(2,expnum-3));
                else mul = -stoi(exp.substr(3,expnum-4));
            }else if(exp[0]!='x'&&exp[expnum-1]=='*'){
                flag=3;
                if(exp[0]!='-')mul = stoi(exp.substr(0,expnum-3));
                else mul = -stoi(exp.substr(1,expnum-4));
            }
        }else flag=-1;
        
        while(m--){
          int x;
          long long num,res;
          cin >> x >> num;
          if(flag==0) res=1;
          else if(flag==1) res = 2*num;
          else if(flag==2) res=2;
          else if(flag==3) res=mul;
          else res=0;
          int out = calres(res);
          cout << res <<endl;
        }
    }else{

    }
    return 0;
}