//
// Created by marvinle on 2019/3/15 5:48 PM.
//

// leetcode 91
// 这题是看了二评论区做的


class Solution {
public:
    /* 如果当前位为0：
        1. 如果前一位不是1或2，则这个0无法和任何数组成字母，代表整个串无法构成编码
        2.如果前一位是1或者2，则说明前一位和当前位能组成字母，这时候能构成的编码数目是和前前位相同的即：dp[i] = dp[i-2]
        如果当前位不为0：
        1. 如果前一位和当前位能组成字母，则当前位的构成编码数目应该为前一位和前前位之和，即：dp[i] = dp[i-1] + dp[i-2](即相当于楼梯n-2+楼梯n-2)，
            当然要考虑当前位是否符合i>=2?
        2. 如果前一位和当前位不能组成字母，则当前位单独组成字母，即dp[i] = dp[i-1]

    */
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;
        int len  = s.length();
        vector<int> dp(len, 0);
        dp[0] = 1;
        for(int i = 1; i < len ; i++) {
            if(s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2')
                    dp[i] = i >= 2 ? dp[i-2] : 1;
                else
                    return 0;
            } else {
                if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                    dp[i] = dp[i-1] + 1;
                    if(i >= 2)
                        dp[i] += (dp[i-2]-1);
                } else
                    dp[i] = dp[i-1];
            }
        }
        return dp[len-1];
    }
};