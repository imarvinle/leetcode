//
// Created by marvinle on 2019/3/18 3:16 PM.
//

class Solution {
public:
    // 摩尔投票，即从第一个数开始计数，遇到相同的计数+1，不同的计数-1，减到0，就重新开始计数
    // 其实就是依据众数比其他数的总合还多，所以最后一定是众数剩下来
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];
        int count = 1;
        for(auto num: nums){
            if(num == ret){
                ++count;
            } else {
                --count;
                if(count == 0){
                    ret = num;
                    count = 1;
                }
            }
        }
        return ret;
    }
};