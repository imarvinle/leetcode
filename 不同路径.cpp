//
// Created by marvinle on 2019/3/15 2:39 PM.
//

// 动态规划

// leetcode 62

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp, 0, sizeof(int) * m *n);
        // 初始化
        for(int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        // 直接将左上边界排除
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++) {
                // 每个点都可以由上和左边两个点走过来，即把上和左相加即可得到当前的
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};