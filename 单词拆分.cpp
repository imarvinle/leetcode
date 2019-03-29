//
// Created by marvinle on 2019/3/29 5:16 PM.
//


/// @brief leetcode 139. 单词拆分


class Solution {
public:
    // dp[i]表示字符串s前i个字符能否拆分

    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<bool> dp(size+1, false);
        unordered_set<string> sets(wordDict.begin(), wordDict.end());
        if(wordDict.size() == 0)
            return false;
        int maxsize = wordDict[0].size();

        for(auto str: wordDict){
            maxsize =  str.size() > maxsize? str.size() : maxsize;
        }

        dp[0] = true;
        for(int i = 1; i <= size; i++){
            /// FIXME 优化 可以不必每次都从头开始搜，可以从(i-maxLenth(wirdDict))
            // for(int j = 0; j < i; j++){
            //     if(dp[j] && sets.find(s.substr(j,i-j)) != sets.end()){
            //         dp[i] = true;
            //         break;
            //     }
            // }
            for(int j = max(0,(i-maxsize)); j < i; j++){
                if(dp[j] && sets.find(s.substr(j,i-j)) != sets.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};