#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int n;
    cin >> n;
    double a[n],sum=0.0,ave=0.0,norm=0.0,temp=0.0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    ave = sum/n;
    for(int i=0;i<n;i++){
        temp += (a[i]-ave)*(a[i]-ave);
    }
    norm = temp/n;
    for(int i=0;i<n;i++){
        double res = (a[i]-ave)/sqrt(norm);
        printf("%f\n",res);
    }
    return 0;
}