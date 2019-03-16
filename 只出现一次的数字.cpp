//
// Created by marvinle on 2019/3/16 8:21 AM.
//


class Solution {
public:
    // 利用相同的数做 ^ 得到的结果是0
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        int size = nums.size();
        for(int i = 1; i < size; i++) {
            result ^= nums[i];
        }
        return result;
    }
};