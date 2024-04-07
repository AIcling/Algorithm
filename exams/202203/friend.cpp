#include <iostream>
using namespace std;
const int MAXN = 1e5; // 假定最多有1e5个元素
int parent[MAXN];
int myrank[MAXN]; // 用于按秩合并的优化

void makeSet(int n) {
    for (int i = 1; i <=n; i++) {
        parent[i] = i;
        myrank[i] = 0; // 初始化时秩为0
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // 路径压缩
    }
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        // 将秩较小的树的根指向秩较大的树的根
        if (myrank[rootX] < myrank[rootY]) {
            parent[rootX] = rootY;
        } else if (myrank[rootX] > myrank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            myrank[rootX]++; // 如果秩相等，合并后的树秩加一
        }
    }
}

int main(void){
    int n,m;
    cin >> n >> m;
    makeSet(n);
    while(m--){
        int a,b;
        cin >> a >> b;
        unite(a,b);
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        if(i==parent[i]) res++;
    }
    cout << res << endl;
}
