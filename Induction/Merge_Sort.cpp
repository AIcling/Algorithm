#include <cstdio>
#include <algorithm>

#define max 100
void Combine(int A[],int L1,int R1,int L2,int R2){
    int temp[max],index=0;
    int i=L1,j=L2;
    while(i<=R1 &&j<=R2){
        if(A[i]<=A[j]) temp[index++] = A[i++];
        else temp[index++] = A[j++];
    }
    while(i<=R1) temp[index++] = A[i++];
    while(j<=R2) temp[index++] = A[j++];
    for(int x=0;x<index;x++) A[L1+x] = temp[x];
}

void merge_Re(int A[],int left,int right){
    if(left<right){
        int mid = (left+right)/2;
        merge_Re(A, left, mid);
        merge_Re(A, mid+1, right);
        Combine(A, left, mid, mid+1, right);
    }
}

int main(void){
    int A[10] = {9,8,7,6,5,4,3,2,1,0};
    merge_Re(A, 0, 9);
    for(int i=0;i<10;i++) printf("%d",A[i]);
}