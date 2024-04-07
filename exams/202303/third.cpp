#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct user{
    int DN;
    map<int,int>  attr;
};
bool cmp(user a,user b){
    return a.DN<b.DN;
}
vector<int> findtrue(vector<user>& users,int key,int value);
vector<int> findfalse(vector<user>& users,int key,int value);
vector<int> findBNF(string exp,vector<user>& users);
vector<int> findinter(vector<int>& res1,vector<int>& res2);
vector<int> findexter(vector<int>& res1,vector<int>& res2);
int main(void){
    int n,handle;
    cin >> n;
    vector<user> users;
    while(n--){
        user usertemp;
        int num;
        cin >> usertemp.DN;
        cin >> num;
        while(num--){
            int key,value;
            cin >> key >> value;
            usertemp.attr[key] = value;
        }
        users.push_back(usertemp);
    }
    sort(users.begin(),users.end(),cmp);
    vector<int> allDNs;
    for (const user& u : users) {
        allDNs.push_back(u.DN);
    }
    // finish init    
    cin >> handle;
    cin.ignore();
    while(handle--){
        string exp;
        getline(cin,exp);
        vector<int> res;
        if(('1'<=exp[0])&&('9'>=exp[0])){
            res = findBNF(exp,users);
            int res_num = res.size();
            if(res_num==0) {printf("\n");}
            else{
                for(int i=0;i<res_num;i++){
                    if(i==res_num-1) printf("%d\n",res[i]);
                    else printf("%d ",res[i]);
                }
            }
        }else if(exp[0]=='&'){
            exp = exp.erase(0,1);
            vector<int> restemp;
            res = allDNs;
            int expnum = count(exp.begin(), exp.end(), ')');            
            while(expnum--){
                int begin = exp.find_first_of('(');
                int end = exp.find_first_of(')');
                string subexp = exp.substr(1,end-begin-1);
                if(expnum>0) exp = exp.erase(0,end-begin+1);
                restemp = findBNF(subexp,users);
                res = findinter(restemp,res);
            }
            int res_num = res.size();
            if(res_num==0) {printf("\n");}
            else{
                for(int i=0;i<res_num;i++){
                    if(i==res_num-1) printf("%d\n",res[i]);
                    else printf("%d ",res[i]);
                }
            }            
        }else if(exp[0]=='|'){
            exp = exp.erase(0,1);
            vector<int> restemp;
            int expnum = count(exp.begin(), exp.end(), ')');            
            while(expnum--){
                int begin = exp.find_first_of('(');
                int end = exp.find_first_of(')');
                string subexp = exp.substr(1,end-begin-1);
                if(expnum>0)exp = exp.erase(0,end-begin+1);
                restemp = findBNF(subexp,users);
                res = findexter(restemp,res);
            }
            int res_num = res.size();
            if(res_num==0) {printf("\n");}
            else{
                for(int i=0;i<res_num;i++){
                    if(i==res_num-1) printf("%d\n",res[i]);
                    else printf("%d ",res[i]);
                }
            }                        
        }
    }
    return 0;
}
vector<int> findBNF(string exp,vector<user>& users){
    vector<int> res;
    int pos = exp.find_first_of(":~");
    int key = stoi(exp.substr(0,pos));
    char opt=exp[pos];
    int value=stoi(exp.substr(pos+1,exp.length()-pos-1));    
    if(opt==':'){
       res =  findtrue(users,key,value);
    }else{
       res =  findfalse(users,key,value); 
    }
    return res;
}
vector<int> findtrue(vector<user>& users,int key,int value){
    vector<int> res;
    int n = users.size();
    for(int i=0;i<n;i++){
        auto it = users[i].attr.find(key);
        if(it!=users[i].attr.end()&&it->second==value){
            res.push_back(users[i].DN);
        }
    }
    return res;
}
vector<int> findfalse(vector<user>& users,int key,int value){
    vector<int> res;
    int n = users.size();
    for(int i=0;i<n;i++){
        auto it = users[i].attr.find(key);
        if(it!=users[i].attr.end()&&it->second!=value){
            res.push_back(users[i].DN);
        }
    }
    return res;
}
vector<int> findinter(vector<int>& res1,vector<int>& res2){
    vector<int> res;
    for(const auto& i:res1){
        auto it = find(res2.begin(), res2.end(), i);
        if(it!=res2.end()) res.push_back(i);
    }
    return res;
}
vector<int> findexter(vector<int>& res1,vector<int>& res2){
    vector<int> res = res2;
    for(const auto& i:res1){
        auto it = find(res2.begin(), res2.end(), i);
        if(it==res2.end()) res.push_back(i);
    }
    sort(res.begin(),res.end());
    return res;
}