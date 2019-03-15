//
// Created by marvinle on 2019/3/15 4:15 PM.
//

// leetcode 64



class Solution {
public:
    // dp 每个点考察上和左最小的，然后和当前值相加即可得到当前最短
    // 继续迭代下去就可以
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        int dp[m][n];
        memset(dp, 0, m * n * sizeof(int));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(dp[i-1][j] < dp[i][j-1]) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                } else {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};