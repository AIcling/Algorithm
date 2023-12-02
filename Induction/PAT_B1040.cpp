#include <cstdio>
#include <cstring>
#define Num 50
char str[Num];
int main(){
    scanf("%s",str);
    int Pnum[50]={0},Tnum[50]={0},result=0;
    //找到第一个A
    int firA=0;
    while(str[firA]!='A'){
        if(str[firA]=='P') Pnum[0]++;
        firA++; 
    }
    int index=0,temp=0;
    for(int i=firA+1;i<strlen(str);i++){
        if(str[i]=='P') temp++;
        else if(str[i]=='A'){
            int last = Pnum[index];
            Pnum[++index] = last + temp;
            temp = 0;
        } 
    }
    int Anum = index+1;
    //找到最后一个A
    int lastA = strlen(str)-1;
    while(str[lastA]!='A'){
        if(str[lastA]=='T') Tnum[index]++;
        lastA--;
    }
    temp = 0;
    for(int i=lastA-1;i>=0;i--){
        if(str[i]=='T') temp++;
        else if(str[i]=='A'){
            int last = Tnum[index];
            Tnum[--index] = last +temp;
            temp = 0;
        }
    }
    for(int i=0;i<Anum;i++){
        result += Pnum[i] * Tnum[i];
    }
    printf("%d\n",result);
    // printf("%d %d\n",Pnum[1],Tnum[1]);
}