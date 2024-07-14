#include <iostream>
#include <vector>
#include <algorithm>
// using namespace std;

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size()-1;

        while(left<right){
            int tem = std::min(height[left],height[right]) * (right-left);
            maxArea = std::max(tem,maxArea);
            if(height[left]<height[right]) left ++;
            else right--;
        }
        return maxArea;
    }
};

int main(){
    Solution solution;
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << "The maximum  is: " << solution.maxArea(height) << std::endl;    
    return 0;
}