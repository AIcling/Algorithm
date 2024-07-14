#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int first = Findtar(nums,target,true);
        if(first==-1) return {-1,-1};
        int last = Findtar(nums,target,false);
        return {first,last};
    }

    int Findtar(const std::vector<int>& nums, int target, bool findFirst){
        int low=0,high=nums.size()-1,ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<target) low = mid+1;
            else if(nums[mid]>target) high = mid-1;
            else{
                ans = mid;
                if(findFirst) high = mid-1;
                else low = mid+1;
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    std::vector<int> result = solution.searchRange(nums, target);
    std::cout << "Start position: " << result[0] << ", End position: " << result[1] << std::endl;
    return 0;
}