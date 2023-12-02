#include <cstdio>
#include <cstring>

int main(void){
    char buffer[80][80];
    int num = 0;
    while(scanf("%s",buffer[num++])!=EOF);


    for(int i=0;i<num;i++){
        printf("%s ",buffer[num-i-1]);
    }
}