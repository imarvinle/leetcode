/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
    }
    int lower_bound(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while(l < r) {
            mid = (l + r) / 2;
            if(nums[mid] <= target) {
                l = mid;
            } else {
                
            }
        }
    }
};

