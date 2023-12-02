#include <cstdio>
 
 int main(void){
    int length,row,n;
    char letter;
    scanf("%d %c",&length,&letter);
    if(length%2==0) row = length/2;
    else row = length/2 + 1;
    for(int i=0;i<row;i++){
        if(i==0){
            n =length;
            while(n--) printf("%c",letter);
            printf("\n");
        }else if(i==row-1){
            n =length;
            while(n--) printf("%c",letter);
            printf("\n");
        }else{
            n =length;
            while(n--){
                if(n==length-1||n==0) {
                    printf("%c",letter);
                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
 }