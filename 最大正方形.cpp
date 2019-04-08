//
// Created by marvinle on 2019/4/8 9:09 AM.
//

class Solution {
public:
    // dp[n][m]是以 [n,m]为右下角的最大正方形边长
    // dp方程 dp[n][m] = min(dp[n-1][m], dp[n][m-1], dp[n-1][m-1]) + 1;
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return 0;
        int m = matrix[0].size();
        int dp[n][m];
        int max_ = 0;
        memset(dp, 0, sizeof(int) * n * m);
        for(int i = 0; i < n; i++){
            if(matrix[i][0] == '1') {
                if(max_ == 0){
                    max_ = 1;
                }
                dp[i][0] = 1;
            }
        }
        for(int i = 0; i < m; i++){
            if(matrix[0][i] == '1') {
                if(max_ == 0){
                    max_ = 1;
                }
                dp[0][i] = 1;
            }
        }
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (matrix[i][j] == '1') {
                    int temp = min(dp[i-1][j], dp[i][j-1]);
                    temp = min(temp, dp[i-1][j-1]) + 1;
                    if(temp > max_){
                        max_ = temp;
                    }
                    dp[i][j] = temp;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return max_ * max_;
    }
};