#include <algorithm>
#include <cstdio>
int count=0;
int two_poi(int a[],int n,int M){
    int left=0,right=n-1;
    while(left<=right){
        if(a[left]+a[right]==M){
            printf("%d,%d\n",a[left],a[right]);
            left ++;
            right--;
            count++;
        }else if(a[left]+a[right]>M){
            right--;
        }else{
            left++;
        }
    }
    return count;
}

int main(void){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    two_poi(a, 10,10);
}