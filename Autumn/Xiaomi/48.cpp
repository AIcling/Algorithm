/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        transpose(matrix);
        for(int i=0;i<matrix.size()/2;i++){
            swapcol(matrix,i,matrix.size()-1-i);
        }
    }
private:
    void transpose(std::vector<std::vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++){
                std::swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void swapcol(std::vector<std::vector<int>>& matrix,int col1,int col2){
        for(int i=0;i<matrix.size();i++){
            std::swap(matrix[i][col1],matrix[i][col2]);
        }
    }
};
int main(void){
    Solution solution;
    std::vector<std::vector<int> > maxtrix = {{1,2,3},{4,5,6},{7,8,9}};
    solution.rotate(maxtrix);
    for(auto line:maxtrix){
        for(auto num:line) std::cout<<num;
        std::cout<<std::endl;
    }
}