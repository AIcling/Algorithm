#include <cstdio>
#include <algorithm>
 using namespace std;
struct In_terval{
    int left;
    int right;
    bool use;
}Interval[100];

bool cmp(In_terval a,In_terval b){
    return a.left > b.left;
}

int main(void){
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d,%d",&Interval[i].left,&Interval[i].right);
        Interval[i].use = false;
    }
    sort(Interval,Interval+n,cmp);
    int before = 0;
    Interval[0].use = true;
    for(int i=1;i<n;i++){
        if(Interval[i].right<=Interval[before].left){
            Interval[i].use = true;
            before = i;
        }
    }
    for(int i=0;i<n;i++){
        if(Interval[i].use==true) printf("%d,%d\n",Interval[i].left,Interval[i].right);
    }
}