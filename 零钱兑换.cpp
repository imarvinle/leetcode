//
// Created by marvinle on 2019/3/23 7:59 PM.
//



// leetcode 322

// class Solution {
// public:
//     // 思路1, 最简单的回溯，即递归, 但是会出现重复
//     int coinChange(vector<int>& coins, int amount) {
//         if(coins.size() == 0)
//             return 0;
//         int sum = 0;
//         int min = numeric_limits<int>::max();
//         dfs(coins, amount, sum, min);
//         if(min == numeric_limits<int>::max()){
//             return -1;
//         }
//         return min;
//     }
//     void dfs(vector<int>& coins, int amount, int sum, int &min){
//         if(amount == 0){
//             if(sum < min)
//                 min = sum;
//             return;
//         }
//         for(int i = 0; i < coins.size(); i++){
//             if(coins[i] > amount){
//                 continue;
//             }
//             dfs(coins, amount-coins[i], sum+1, min);
//         }
//     }
// };


class Solution {
public:
    // 思路2, dp,类似上楼梯，一次1步或多步，但是上楼梯递推是之和，这里应该是选最小值
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0)
            return 0;
        int max = amount + 1;
        vector<int> dp(amount+1, max);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i >= coins[j]){
                    dp[i] = min(dp[i-coins[j]]+1, dp[i]);
                }
            }
        }
        return dp[amount] < max? dp[amount]: -1;
    }
};




