//
// Created by marvinle on 2019/3/23 4:42 PM.
//

// leetcode  300


// class Solution {
// public:
//     // dp[i]表示必须把i选上它的子序列长度
//     // 状态转移方程:
//     // dp[i] = max{dp[j] + 1} (nums[j] < nums[i]);
//     int lengthOfLIS(vector<int>& nums) {
//         int len = nums.size();
//         if(len == 0)
//             return 0;
//         vector<int> dp(len,1);
//         int max_ = dp[0];
//         for(int i = 1; i < len; i++){
//             for(int j = i-1; j >=0; j--){
//                 if(nums[j] < nums[i]){
//                   dp[i] = max(dp[i], dp[j]+1);
//                 }
//             }
//             if(dp[i] > max_){
//                 max_ = dp[i];
//             }
//         }
//         return max_;
//     }
// };


#include <unordered_map>
class Solution {
public:
    // 思路二: 维护一个最长上升子序列数组，新的数如果都大于序列中所有数的话，可以直接插入到末尾
    // 否则二分查找到第一个大于等于数，替换掉
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(auto num: nums){
            auto it = lower_bound(lis.begin(),  lis.end(), num);
            if(it == lis.end()){
                lis.push_back(num);
            } else {
                *it = num;
            }
        }
        return lis.size();
    }
};};