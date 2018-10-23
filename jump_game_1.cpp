//
// Created by marvinle on 2018/10/23.
//
#include <vector>
using namespace std;


class Solution {
public:
    // 从后面往前看，看每一个是否能到后一面最近一个点，这个点能够到终点
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)
            return true;

        int a[len] = {0};
        int target = len-1;
        int temp = len - 2;
        while(temp >= 0)
        {
            if(nums[temp] >= target-temp)
            {
                a[temp] = 1;
                target = temp;
            }
            temp--;
        }

        return a[0];
    }
};