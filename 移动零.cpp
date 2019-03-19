//
// Created by marvinle on 2019/3/19 9:40 PM.
//
// 将数组所有零移动到末尾

class Solution {
public:
    // 其实类似奇偶数移动
    void moveZeroes(vector<int>& nums) {
        // 减少移动次数,先统计0的个数，直接将非0移动到前面去，而将后面置0
        int zerocnt = 0;
        int i = 0;
        int size = nums.size();
        for(int j = 0; j < size; j++){
            if(nums[j] != 0)
                nums[i++] = nums[j];
        }
        for(; i < size; i++){
            nums[i] = 0;
        }
    }
};