#include <cstdio>

int main(void){
    int A=0,B=0,D=0,num=0;
    scanf("%d %d %d",&A,&B,&D);
    int C = A+B;
    int z[30]={0};
    do{
        z[num++] = C % D;
        C = C / D;
    }while(C!=0);
    for(int i = 0;i<num;i++){
        printf("%d",z[num-i-1]);
    }
}