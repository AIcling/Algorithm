#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const double eps = 1e-6;
int rankOfMatrix(vector<vector<double>> matrix) {
    int rank = 0;
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    for (int col = 0; col < numCols; ++col) {
        // 寻找非零元素
        int pivot = rank;
        while (pivot < numRows && abs(matrix[pivot][col]) < 1e-6) {
            ++pivot;
        }
        if (pivot == numRows) {
            continue; // 没有找到非零元素，继续下一列
        }

        // 将有非零首元的行交换到当前行
        swap(matrix[rank], matrix[pivot]);

        // 将当前列的首元化为1，并将此列其他行的元素化为0
        for (int row = 0; row < numRows; ++row) {
            if (row != rank && abs(matrix[row][col]) > 1e-6) {
                double factor = matrix[row][col] / matrix[rank][col];
                for (int k = col; k < numCols; ++k) {
                    matrix[row][k] -= factor * matrix[rank][k];
                }
            }
        }

        // 增加秩
        ++rank;
    }

    return rank;
}
int n;
bool isa(char a){
    return 'a'<=a && 'z'>=a;
}
int main(void){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        vector<unordered_map<string,int> > formus;
        unordered_set<string> yuansu;
        for(int g=0;g<k;g++){
            string s;
            cin >> s;
            unordered_map<string,int> word;
            int len = s.size();
            int i=0;
            while(i<len){
                string te,nu;
                while(isa(s[i])){
                    te+=s[i];
                    i++;
                }
                while(!isa(s[i])){
                    nu+=s[i];
                    i++;
                    if(i==len) break;
                }
                int num = stoi(nu);
                word[te]=num;
                yuansu.insert(te);                
            }
            formus.push_back(word);
        }
        int row = yuansu.size();//元素个数
        vector<vector<double>> mat(row,vector<double>(k));
        int ro=0;
        for(auto r:yuansu){
            for(int j=0;j<k;j++){
                auto it = formus[j].find(r);
                if(it!=formus[j].end()) mat[ro][j] = it->second;
                else mat[ro][j]=0;
            }
            ro++;
        }
        // for(auto m:mat){
        //     for(auto a:m){
        //         cout<<a<<" ";
        //     }
        //     cout <<endl;
        // }
        int rank = rankOfMatrix(mat);
        if(rank<k) cout<<"Y"<<"\n";
        else cout<<"N"<<"\n";
    }
    return 0;
}