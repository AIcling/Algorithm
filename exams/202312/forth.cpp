#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
using namespace std;
const int mod = 998244353;
struct matrix
{
    int _11;
    int _12;
    int _21;
    int _22;
matrix(int one,int two,int third,int four):_11(one),_12(two),_21(third),_22(four){}
};
matrix calres(matrix A,matrix B){
    matrix res(0,0,0,0);
    res._11 = (A._11*B._11+A._12*B._21);
    res._12 = (A._11*B._12+A._12*B._22);
    res._21 = (A._21*B._11+A._22*B._21);
    res._22 = (A._21*B._12+A._22*B._22);
    return res;
}
vector<vector<int> > commands;
int main(void){
    int n,m;
    vector<int> _zreo(1,0);
    commands.push_back(_zreo);
    cin >> n >> m;
    while(n--){
        vector<int> command;
        int temp;
        cin >> temp;
        command.push_back(temp);
        if(temp!=3){
            for(int i=0;i<4;i++){
                cin >> temp;
                command.push_back(temp);
            }
        }
        commands.push_back(command);
    }
    while(m--){
        int crl;
        cin >> crl;
        if(crl==1){
           int temp,index;
           cin >> index >>temp;
           vector<int> command;
           command.push_back(temp);
            if(temp!=3){
                for(int i=0;i<4;i++){
                    cin >> temp;
                    command.push_back(temp);
                }
            }
            commands[index] = command;
        }else if(crl==2){
            deque<matrix> dq;
            int start,end,flag;
            cin >> start >> end;
            for(int i=start;i<=end;i++){
                vector<int> command = commands[i];
                if(command[0]==1){
                    flag=0;
                    matrix temp(command[1],command[2],command[3],command[4]);
                    dq.push_front(temp);
                }else if(command[0]==2){
                    flag=1;
                    matrix temp(command[1],command[2],command[3],command[4]);
                    dq.push_back(temp);
                }else if(command[0]==3){
                    if(dq.empty()) continue;
                    if(flag==0) dq.pop_front();
                    else if(flag==1) dq.pop_back(); 
                }
            }
            matrix res(dq[0]._11,dq[0]._12,dq[0]._21,dq[0]._22);
            for(int i=1;i<dq.size();i++){
                res = calres(res,dq[i]);
            }
            res._11 %= mod;
            res._12 %= mod;
            res._21 %= mod;
            res._22 %= mod;
            cout <<res._11<<" "<<res._12<<" "<<res._21<<" "<<res._22<< endl;
        }
    }
    return 0;
}