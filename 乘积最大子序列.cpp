//
// Created by marvinle on 2019/3/23 4:04 PM.
//

//leetcode 152


class Solution {
public:
    // 二维DP ,将到当前整数的最大值和负数的最大值都存起来
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        int dp[size][2];
        memset(dp, 0, sizeof(int) * size *2);
        int max_  = nums[0];
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for(int i = 1; i < size; i++){
            dp[i][0] = getMax(nums[i], nums[i]*dp[i-1][0], nums[i]*dp[i-1][1]);
            dp[i][1] = getMin(nums[i], nums[i]*dp[i-1][0], nums[i]*dp[i-1][1]);
            if(dp[i][0] > max_){
                max_ = dp[i][0];
            }
        }
        return max_;

    }
    int getMax(int a, int b, int c){
        int max =  a > b ? a : b;
        return max > c ? max : c;
    }

    int getMin(int a, int b,  int c){
        int min = a < b ? a : b;
        return min < c ? min : c;
    }
};