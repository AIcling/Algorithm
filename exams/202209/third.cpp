#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 1000;
struct record{
    int d;
    int u;
    int r;
record(int d,int u,int r):d(d),u(u),r(r){}
};
vector<int> flag(MAX,0);
int main(void){
    int n;
    cin >> n;
    vector<record> records;
    vector< vector<int> > regins(MAX,vector<int>(0));
    for(int day=0;day<n;day++){
        int rnum,mnum;
        cin >> rnum >> mnum;
        while(rnum--){
            int regin;
            cin >> regin;
            //if not existed
            if(flag[regin]==0){
                vector<int> temp(3,0);
                temp[0] = regin;
                temp[1] = day;
                temp[2] = day;
                flag[regin]=1;
                regins.push_back(temp);
            }else{
                for(auto temp:regins){
                    if(temp[0]==regin){
                        temp[1] = temp[2];
                        temp[2] = day;
                    }
                }
            }
        }
        while(mnum--){
            int d,u,r;
            cin >> d >> u >> r;
            record mess(d,u,r);
            records.push_back(mess);
        }
        // for(auto it=regins.begin();it!=regins.end();){
        //     if(day>=it->second+7) it = regins.erase(it);
        //     else it++;
        // }
        vector<int> res;
        for(auto record: records){
            for(auto regin:regins){
                if((record.r==regin[0])&&(record.d<regin[1]+7)&&(record.d>=regin[1])&&(record.d<regin[2]+7)&&(record.d>=regin[2])){
                    res.push_back(record.u);
                }
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        cout << day <<" ";
        for(int out:res){
            cout <<out<<" ";
        }
        cout<<endl;
    }
    return 0;
}