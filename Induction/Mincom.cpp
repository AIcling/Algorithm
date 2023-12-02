#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int table[10] = {0};
int num=0;
char mincom[10] = {0};

int main(void){
    for(int i=0;i<10;i++){
        scanf("%d",&num);
        table[i] = num;
    }
    for(int i=1;i<10;i++){
        if(table[i]!=0){
            mincom[0] = i+48;
            table[i]--;
            break;
        }
    }
    int j = 1,n=0;
    while(n<10){
        if(table[n]!=0){
            mincom[j++] = n+48;
            table[n]--;
        }else{
            n++;
        }
    }
    printf("%s",mincom);
}