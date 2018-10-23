//
// Created by marvinle on 2018/10/17.
//

using namespace std;
#include <vector>

class Solution {
public:
    // O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        int *dp = (int*)malloc(nums.size()*sizeof(int));
        memset(dp,0,sizeof(int)*nums.size());
        int Max;
        for(int i = 0 ; i < nums.size(); i++){
            Max = 0;
            for(int j = 0 ; j < i; j++){
                if(nums[i] > nums[j]){
                    Max = max(Max,dp[j]);
                }
            }
            dp[i] = Max + 1;
        }
        Max = 0;
        for(int i = 0; i < nums.size(); i++){
            if(dp[i] > Max)
                Max = dp[i];
        }
        free(dp);
        return Max;
    }
    // O(nlogn)
    int lengthOfLIS_(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int *dp = new int(nums.size());
        int len = 1;
        int pos;
        memset(dp, 0 , sizeof(int)*nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pos = lower_bound(dp,dp+len,nums[i]) -dp;
            dp[pos] = nums[i];
            len = max(len, pos+1);
        }
        delete[] dp;
        return len;

    }

};

