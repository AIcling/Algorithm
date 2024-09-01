/*
给你一个数组 nums ，请你完成两类查询。
其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
实现 NumArray 类：
NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值 更新 为 val
int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
*/
#include <vector>
class SegmentTree {
public:
    SegmentTree(const std::vector<int>& nums) {
        n = nums.size();
        tree.resize(2 * n);
        build(nums);
    }

    void update(int index, int value) {
        index += n;
        tree[index] = value;
        while (index > 0) {
            index /= 2;
            tree[index] = tree[2 * index] + tree[2 * index + 1];
        }
    }

    int query(int left, int right) {
        left += n;
        right += n + 1;
        int sum = 0;
        while (left < right) {
            if (left % 2 == 1) {
                sum += tree[left];
                left++;
            }
            if (right % 2 == 1) {
                right--;
                sum += tree[right];
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }

private:
    std::vector<int> tree;
    int n;

    void build(const std::vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            tree[i + n] = nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
};

class NumArray {
public:
    SegmentTree* segtree;
    NumArray(std::vector<int>& nums) {
        segtree = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        segtree->update(index,val);
    }
    
    int sumRange(int left, int right) {
        return segtree->query(left,right);
    }
};