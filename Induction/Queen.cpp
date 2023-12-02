#include <cstdio>
#include <cmath>
int count = 0;
int n,P[10],HashTable[10]={false};

void GenerateP(int index){
    if(index == n-1){
        bool flag = true;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<n+1;j++){
                if(abs(i-j)==abs(P[i]-P[j])){
                    flag = false;
                }
            }
        }
        if(flag) count++;
    }
    for(int x=0;x<=n;x++){
        if(HashTable[x]==false){
            P[index] = x;
            HashTable[x]=true;
            GenerateP(index+1);
            HashTable[x] = false;
        }
    }
}

void TraceP(int index){
    for(int x=0;x<=n;x++){
        if(HashTable[x]==false){
            bool flag = true;
            for(int pre=1;pre<index;pre++){
                if(abs(index - pre)==abs(x-P[pre])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                P[index]=x;
                HashTable[x] = true;
                TraceP(index+1);
                HashTable[x] = false;
            }
        }
    }
    if(index==n+1){
        count++;
        return;
    }
}