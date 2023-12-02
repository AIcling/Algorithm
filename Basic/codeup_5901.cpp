#include <cstdio>
#include <cstring>

int main(void){
    char buffer[255];
    while(scanf("%s",buffer)!=EOF){
    int len = strlen(buffer);
    int flag = 1;
    for(int i=0;i<len/2;i++){
        if(buffer[i]!=buffer[len-i-1]) {flag = 0; break;}
    }
    if(flag==1) printf("YES\n");
    else printf("NO\n");
  }
}