//
// Created by marvinle on 2018/10/16.
//
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int max = INT_MIN;
        int curMax = 0;
        for(auto i : nums)
        {
            if( curMax <= 0)
                curMax = i;
            else
                curMax += i;
            if(max < curMax)
                max = curMax;
        }
        return max;
    }
};