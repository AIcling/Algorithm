#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N=0,M=0;
    cin >> N >> M;
    vector<vector<int> > handle(N,vector<int>(2));
    vector<vector<int> > index(M,vector<int>(2));
    for (int i=0;i<N;i++){
        cin >> handle[i][0] >> handle[i][1];
    }
    for (int i=0;i<M;i++){
        cin >> index[i][0] >> index[i][1];
    }
    //index handling
    for (int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            index[i][0] += handle[j][0];
            index[i][1] += handle[j][1];
        }
        cout << index[i][0] << " " <<  index[i][1] <<endl;
    }
    return 0;
}