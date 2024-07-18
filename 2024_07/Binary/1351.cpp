/*
给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非严格递减顺序排列。 
请你统计并返回 grid 中 负数 的数目。
*/
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int num=0;
        for (auto x:grid){
            int l=0,r=(int)x.size()-1,pos=-1;
            while (l<=r){
                int mid=l+((r-l)>>1);
                if (x[mid]<0){
                    pos=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if (~pos) num+=(int)x.size()-pos;// pos=-1表示这一行全是>=0的数，不能统计
        }
        return num;
    }
};
