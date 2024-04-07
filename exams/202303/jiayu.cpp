#include<bits/stdc++.h>
using namespace std;
struct task{
        int time;
        int need;
};

vector<task> vi;
int n, m , k;

bool cmp(task a,task b){
        return a.time > b.time ;
}

bool judge(int days){
        int tot =  0;
        for(int i = 0;i < vi.size();i++){
                if(vi[i].time > days){
                        tot += (vi[i].time - days)*vi[i].need;
                        if (tot > m){
                                return false;
                        }
                }
        }
        return true;
}

int main(){
        
        cin >> n >> m >> k;
        for(int i = 0;i < n;i ++){
                task t;
                cin >> t.time >>t.need;
                vi.push_back(t);
        }
        
        sort(vi.begin(),vi.end(),cmp);
        
        int left = k-1,right = vi[0].time, ans = right;
        while(left + 1 != right){
                int mid = (left + right)/2;
                if (judge(mid)){
                        ans = mid;
                        right = mid;
                }
                else {
                        left = mid ;
                }
        }
        
        cout << ans << endl;
        
        return 0;        
}