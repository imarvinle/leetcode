//
// Created by marvinle on 2019/3/16 4:49 PM.
//

/* 回溯法，内存超出
class Solution {
public:
    // 回溯
    int minDistance(string word1, string word2) {
        int edit = 0;
        int min = numeric_limits<int>::max();
        helper(0, 0, word1, word2, edit, min);
        return min;
    }

    void helper(int s1, int s2, string word1,  string word2, int edit, int& min) {
        int l1 = word1.size();
        int l2 = word2.size();
        if(l1 == s1 || l2 ==  s2) {
            // 统计多余的，只能删除或者插入
            if(l1  !=  s1)
                edit += (l1-s1);
            if(l2 != s2)
                edit += (l2-s2);
            // 更新最小值
            if(edit < min)
                min = edit;
            return;
        } else if(word1[s1] ==  word2[s2]){
            helper(s1+1,  s2+1, word1, word2, edit, min);
        } else {
            // 不等
            // 删除一个
            helper(s1+1, s2, word1, word2, edit+1, min);
            helper(s1, s2+1, word1, word2, edit+1, min);
            //替换一个,继续前进
            helper(s1+1, s2+1, word1, word2, edit+1, min);
        }
    }
};
 */


class Solution {
public:
    // 回溯
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m == 0 || n == 0){
            return m+n;
        }


        int dp[m][n];   // dp[i][j]表示,到i,j需要的最小编辑次数
        // 初始化 word1 到 word2[0]
        for(int i = 0; i < m; i++){
            if(word1[i] == word2[0])
                dp[i][0] = i;
            else if(i != 0)
                dp[i][0] = dp[i-1][0]+1;
            else
                dp[i][0] = 1;
        }
        // 初始化  word1[0] 到 word2
        for(int i = 0; i < n; i++){
            if(word1[0] == word2[i])
                dp[0][i] = i;
            else if(i != 0)
                dp[0][i] = dp[0][i-1]+1;
            else
                dp[0][i] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(word1[i] == word2[j]){
                    // 三者选最小
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]+1);
                    dp[i][j] = min (dp[i][j],dp[i][j-1]+1);
                }
                else{
                    // 否则三者选最小
                    dp[i][j] = min(dp[i-1][j-1]+1, dp[i-1][j]+1);
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
