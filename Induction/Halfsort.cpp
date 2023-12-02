#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL ;

int binarySearch(int a[],int length,int x){
    int mid=0,left=0;
    int right = length-1;
    while(left<=right){
        mid = (left+right)/2;
        if(a[mid] == x) return x;
        else if(a[mid]<x) left = mid+1;
        else right = mid-1;
    }
    return -1;
}

int lower_bound(int a[],int length,int x){
    int mid=0,left=0;
    int right = length-1;
    while(left<right){
        mid = (left+right)/2;
        if(a[mid]>=x) right = mid;
        else left = mid+1;
    } 
    return left;  
}

int upper_bound(int a[],int length,int x){
    int mid=0,left=0;
    int right = length-1;   
    while(left<right){
        mid = (left+right)/2;
        if(a[mid]>x) right = mid;
        else left = mid+1;
    }
    return left;
}

LL binaryPow(LL a,LL b,LL m){
    if(b==0) return 1;
    else if(b%2 == 1) return a * binaryPow(a, b-1, m) % m;
    else {
        LL mul = binaryPow(a, b, m);
        return mul * mul % m;
    }
}