#include <cstdio>
    int main(){
        int n=0,i=0,sort=0;
        int number[100] = {0};
        scanf("%d",&n);
        while(n--){
            scanf("%d",&number[i]);        
            i++;
        }
        // printf("OK\n");
         printf("%d\n",number[n-1]);
        for(int k=0;k<n;k++){
        printf("%d\n",number[k]);
        }
        int x = -1;
        int j = 0;
        scanf("%d",&sort);
        for(j=0;j<n;j++){ 
            if(number[j]==sort){
                x = j;
                break;
            }
        }
        printf("%d",x);
    }