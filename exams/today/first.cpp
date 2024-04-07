#include <iostream>
#include <vector>
using namespace std;
int n,m;
struct word
{
   int times;
   int sum;
   word():sum(0),times(0){}
};

vector<word> words(101);
int main(void){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> m;
    vector<word> words(m+1);
    while(n--){
        int k;
        cin >> k;
        vector<int> flag(m+1,0);
        while(k--){
            int t;
            cin >> t;
            if(flag[t]==0){
                flag[t]=1;
                words[t].times++;
            }
            words[t].sum++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << words[i].times << " " << words[i].sum << endl;
    }
    return 0;
}