#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 函数用于打印矩阵，帮助理解过程
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double elem : row) {
            cout << elem << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// 使用高斯消元法求矩阵的秩
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

int main() {
    vector<vector<double>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    int rank = rankOfMatrix(matrix);
    cout << "Rank of the Matrix: " << rank << "\n";

    return 0;
}
