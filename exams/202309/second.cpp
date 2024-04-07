#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void){
    int N=0,M=0;
    cin >> N >> M;
    vector<vector<double> > handle(N+1,vector<double>(2));
    vector<vector<double> > index(M+1,vector<double>(4));
    for (int i=1;i<=N;i++){
        cin >> handle[i][0] >> handle[i][1];
    }
    for (int i=1;i<=M;i++){
        cin >> index[i][0] >> index[i][1] >> index[i][2] >> index[i][3];
    }
    double tempx=0.0,tempy=0.0;
    for(int i=1;i<=M;i++){
        for(int n=index[i][0];n<=index[i][1];n++){
            if(handle[n][0]==1){
               index[i][2] =  index[i][2]*handle[n][1];
               index[i][3] =  index[i][3]*handle[n][1];
            }else{
               tempx = index[i][2];
               tempy = index[i][3];
               index[i][2] = tempx*cos(handle[n][1]) - tempy*sin(handle[n][1]);
               index[i][3] = tempx*sin(handle[n][1]) + tempy*cos(handle[n][1]);
            }
        }
         cout << fixed << setprecision(3) << index[i][2] << " " << index[i][3] <<endl;
    }
    return 0;
}