#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
using namespace std;

struct node{
    double num;
    char ope;
    bool flag;
};
map<char,int> op;
stack<node> s;
queue<node> q; 
string str;

void change(void){
    node tmp;
    for(int i=0;i<str.length();){
        if(str[i]>='0'&&str[i]<='9'){
            tmp.flag = false;
            tmp.num = str[i] - '0';
            i++;
            while(str[i]>='0'&&str[i]<='9'&&i<str.length()){
                tmp.num = tmp.num*10 + str[i]-'0';
                i++;
            }
            q.push(tmp);
        }else{
            tmp.flag = true;
            while(!s.empty()&&op[str[i]]<=op[s.top().ope]){
                q.push(s.top());
                s.pop();
            }
            tmp.ope = str[i++];
            s.push(tmp);
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void cal(void){
    node tmp;
    double topnum;
    double secnum;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        if(tmp.flag==false) {s.push(tmp);}
        else {
            topnum = s.top().num;
            s.pop();
            secnum = s.top().num;
            s.pop();
            if(tmp.ope=='+') topnum = secnum + topnum ;
            if(tmp.ope=='-') topnum = secnum - topnum ;
            if(tmp.ope=='*') topnum = secnum * topnum ;
            if(tmp.ope=='/') topnum = secnum / topnum ;
            node topnode = {topnum,0,false};
            s.push(topnode);
        }

    }
    printf("%lf",s.top().num);
}
int main(void){
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while(getline(cin,str),str!="0"){
        for(string::iterator it=str.end();it!=str.begin();it --){   //去掉空格
             if(*it ==' ') str.erase(it);
        }
        // for(string::iterator it=str.begin();it!=str.end();it++) printf("%c",*it);
        change();
        cal();
    }

}