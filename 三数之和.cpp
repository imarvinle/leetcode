//
// Created by marvinle on 2019/3/14 10:56 AM.
//

// leetcode 15 三数之和


class Solution {
public:
    // 思路1. 两重循环 a+b 然后在set里找第三个数set(-a-b)
    // 思路2, 先nlogn排序，一遍循环，i , 然后 i+1  size-1两个双指针向中间移动
    // 不断判断a+b+c，如果成功还要继续看i+1和size-1有没有重复元素，要继续移动去除重复元素
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return vector<vector<int>>();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-2; i++) {
            // FIXME 连续的要去重
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int temp = nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r) {
                int sum = temp + nums[l] + nums[r];
                if(sum < 0){
                    l++;
                }
                else  if(sum > 0){
                    r--;
                }
                else {
                    vector<int> v{temp, nums[l], nums[r]};
                    result.push_back(v);
                    // 去除左边重复
                    while(l < r  &&  nums[l] == nums[l+1])
                        l++;
                    while(l < r && nums[r] == nums[r-1])
                        r--;
                    l++;
                    r--;
                }
            }
        }
        return result;
    }
};