#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


int main(void){
    long n,d;
    cin >> n >> d;
    int Q[n][d],V[n][d],K[d][n],W[n];
    for(long i=0;i<n;i++){
        for (long j=0;j<d;j++){
            cin >> Q[i][j];
        }
    }
    for(long i=0;i<n;i++){
        for(long j=0;j<d;j++){
            cin >> K[j][i];
        }
    }
    for(long i=0;i<n;i++){
        for (long j=0;j<d;j++){
            cin >> V[i][j];
        }
    } 
    for(long i=0;i<n;i++){
        cin >> W[i];
    }
    //calculate
    long long temp[n],res[d]={0};
    for(long i=0;i<n;i++){
        for(long i=0;i<d;i++){
            res[i]=0;
        }
        for(long i=0;i<n;i++){
            temp[i]=0;
        }
        for(long j=0;j<n;j++){
            for(long k=0;k<d;k++){
                temp[j] += Q[i][k]*K[k][j];
            }
        }
        for(long j=0;j<n;j++){
            temp[j] = temp[j]*W[i];
        }
        for(long k=0;k<d;k++){
            for(long j=0;j<n;j++){
                res[k] += temp[j]*V[j][k];
            }
            if(k<d-1) printf("%lld ",res[k]);
            else if(k==d-1) printf("%lld\n",res[k]);
        }
    }   
    return 0;
}