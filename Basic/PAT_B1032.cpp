#include <cstdio>
    #define max_sch 1000
    int main(){
        int n;
        int ID,score;
        int sum[max_sch] = {0};
        scanf("%d",&n);
    int max_val;
    int schtar;
    for(int i=0;i<n;i++){
        scanf("%d %d",&ID,&score);
        sum[ID] +=score;
        if(sum[ID]>max_val){
            max_val = sum[ID];
            schtar = ID;
            // printf("%d",max_val);
        }
    }
    printf("%d %d",schtar,max_val);
 }