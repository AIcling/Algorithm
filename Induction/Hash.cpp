#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int String_Hash(char S[]){
    int len = strlen(S);
    int id = 0;
    for(int i=0;i<len;i++){
        id = id + (S[i]-'A') * pow(26,i);
    }
    return id;
}
int HashTable[26*26*26] = {0};

int main(void){
    int n=0,id=0;
    char TestString[3];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char tmp[3];
        scanf("%s",tmp);
        id = String_Hash(tmp);
        HashTable[id] = 1;
    }
    printf("HashTable OK!\n");
    int testid = 0;
    while(scanf("%s",TestString)!=EOF){
        testid = String_Hash(TestString);
        if(HashTable[testid]!=0) printf(("Existed!\n"));
        else printf("Not Existed!\n");
    }
}