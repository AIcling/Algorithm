#include <cstdio>

int Partition(int A[],int left,int right){
    int temp = A[left];
    while(left<right){
        while(left<right && temp<=A[right]) right--;
        A[left] = A[right];
        while(left<right && temp>A[left]) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}
void quicksort(int A[],int left,int right){
    if(left<right){
        int mid = Partition(A, left, right);
        quicksort(A, left, mid-1);
        quicksort(A, mid+1, right);
    }else return;
}
int main(void){
    int A[10] = {9,8,7,6,5,4,3,2,1,0};
    quicksort(A, 0, 9);
    for(int i=0;i<10;i++) printf("%d",A[i]);
}