#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define LL long long 
struct TreeNode{
    int label;
    string start,end;
    vector<TreeNode *> childs;
    TreeNode(int label,string start,string end):label(label),start(start),end(end){}
};
void insertIP(TreeNode *root,string ){

}
int n,q;
int main(void){
    cin >> n >> q;
    n /=16;
    string maxip,minip;
    maxip.reserve(5*n-1);
    minip.reserve(5*n-1);
    for(int i=0;i<n-1;i++){
        string temp1 = "0000:";
        string temp2 = "ffff:";
        maxip += temp2;
        minip += temp1;
    }
    string temp1 = "0000";
    string temp2 = "ffff";
    minip += temp1;
    maxip += temp2;
    TreeNode *root = new TreeNode(0,minip,maxip);
    while(q--){
        int cmd,id;
        cin >> cmd;
        if(cmd==1){
            cin >> id;
            string start,end;
        }
    }
    return 0;
}