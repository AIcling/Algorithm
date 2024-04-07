#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = pow(10,9);
int find_min(int *weights,int root,int n);
struct node{
    int val;
    vector<node *> children;
node(int value):val(value){}
    void addchild (node *child){
        children.push_back(child);
    }
};
int cal_val(node *root){
    int val=root->val;
    if(root->children.size()==0) {val=val;}
    else{ 
        for(auto child : root->children){
             val += cal_val(child);
        }
    }
    return val;
}
int ifchild(node *fnode, node *snode){
    int flag=0;
    if(fnode==snode){return 1;}
    else if(snode->children.size()==0){flag = 0;}
    else{
        for(auto child : snode->children){
            if(ifchild(fnode,child)==1) {flag=1;break;}
        }
    }
    return flag;
}
void delete_child(node *root){
    root->val = 0;
    if(root->children.size()!=0){
        for(auto child : root->children) delete_child(child);
    }
}
void delete_others(node *root,node *parent){

}
int main(void){
    int n,m;
    cin >> n >> m;
    node *node_list[n+1];
    int vals[n+1];
    for(int i=1;i<=n;i++){
        cin >> vals[i];
        node_list[i] = new node(vals[i]);
    }
    int parents[n+1];
    for(int i=2;i<=n;i++){
        int parent;
        cin >> parent;
        parents[i] = parent;
        node_list[parent]->addchild(node_list[i]);
    }
    
    //finish init
    while(m--){
        int index;
        cin >> index;
        int root=1,old_root=1;
        // restore
        for(int i=1;i<=n;i++){
            node_list[i]->val = vals[i];
        }
        while(1){
        int sum = cal_val(node_list[root]);
            // cout <<sum <<endl;
            if(sum==node_list[index]->val) {cout<<endl;break;}
            int weights[n]={MAX};
            for(int i=root;i<=n;i++){
                if(ifchild(node_list[i],node_list[root])==1) {
                    weights[i] = abs(sum-2*cal_val(node_list[i]));
                }
            }
            int select = find_min(weights,root,n);
            cout << select << " ";
             if(select==1) {cout<<endl;break;}
            if(ifchild(node_list[index],node_list[select])==0){
                delete_child(node_list[select]);
            }else{
                root = select;
            }
        }
    }
    
    return 0;
}
int find_min(int *weights,int root,int n){
    int index=root,minval = weights[root];
    for(int i=root;i<=n;i++){
        if (weights[i]<minval) {index = i;minval = weights[i];}
    }
    return index;
}