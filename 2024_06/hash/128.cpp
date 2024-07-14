#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(),nums.end());
        int res=0;
        int curnum=0;
        for(int num:nums){
            int curlength =0;
            if(!num_set.count(num-1)){
                curnum = num;
                curlength++;
                while(num_set.count(curnum+1)){
                    curnum += 1;
                    curlength +=1;
                }
            }
            res = max(res,curlength);
        }
        return res;
    }
};